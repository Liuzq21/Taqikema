#include "chathome.h"
#include "ui_chathome.h"
#include "taqikema.h"
#include <QDataStream>
#include <QMessageBox>
#include <QDateTime>


ChatHome::ChatHome( QString _uName, QWidget *parent)
    :  QWidget(parent)
    , ui(new Ui::ChatHome)
{
    ui->setupUi(this);
    // this->setAttribute(Qt::WA_DeleteOnClose); // close 时析构
    this->uName = _uName;
    this->port = 9999;
    this->udpSocket = new QUdpSocket(this);
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    connect(udpSocket, &QUdpSocket::readyRead, this, &ChatHome::ReceiveMsg);

}

ChatHome::~ChatHome()
{
    delete ui;
}

void ChatHome::sndMsg(ChatHome::Msgtype type)
{
    QByteArray array;
    array.clear();
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream<<type<<this->getName();

    switch(type){
    case Msg:
        if(ui->msgText->toPlainText() == ""){
            QMessageBox::warning(this,"Warning","Send Message should not be null !");
            return;
        }
        stream<<this->getMsg();
        break;
    case UserEnter:
        break;
    case UserLeft:
        break;
    }
    // broadcast msg
    udpSocket->writeDatagram(array.data(), array.size(), QHostAddress::Broadcast, this->port);

}

void ChatHome::ReceiveMsg()
{
    qint64 size = udpSocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    udpSocket->readDatagram((*array).data(), size);
    QDataStream stream(array, QIODevice::ReadOnly);
    int mytype;
    QString name, msg;
    QString time = QDateTime::currentDateTime().toString();
    stream>>mytype;
    switch(mytype){
    case Msg:
        stream>>name>>msg;
        ui->msgBrowser->setTextColor(QColor(Qt::blue));
        ui->msgBrowser->append("["+name+"]"+time);
        ui->msgBrowser->append(msg);
        break;
    case UserEnter:
        break;
    case UserLeft:
        break;
    }
    delete array;
}

QString ChatHome::getName()
{
    return uName;
}

QString ChatHome::getMsg()
{
    QString msg = ui->msgText->toPlainText();
    ui->msgText->clear();
    ui->msgText->setFocus();
    return msg;
}

void ChatHome::on_sendButton_clicked()
{
    // QMessageBox::warning(this,"Warning","Send Message should not be null !");
    sndMsg(Msg);
}

