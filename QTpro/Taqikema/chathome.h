#ifndef CHATHOME_H
#define CHATHOME_H

#include <QWidget>
#include <QUdpSocket>
#include"taqikema.h"
namespace Ui {
class ChatHome;
}

class ChatHome : public QWidget
{
    Q_OBJECT

public:
    enum Msgtype{Msg, UserEnter,UserLeft};
    explicit ChatHome(QString _uName, QWidget *parent = nullptr);
    ~ChatHome();

    void sndMsg(Msgtype type);  // 广播udp消息
    void ReceiveMsg();  // 接受udp消息
    QString getName();    // 获取名字
    QString getMsg();  // 获取聊天信息
    void userEnter(QString username);  // 处理用户进入
    void userLeft(QString username, QString time);  // 处理用户离开



private slots:
    void on_sendButton_clicked();

private:
    Ui::ChatHome *ui;
    quint16 port; // 端口
    QString uName;
    QUdpSocket *udpSocket;  // 套接字

};

#endif // CHATHOME_H
