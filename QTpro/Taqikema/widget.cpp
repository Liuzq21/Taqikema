#include "widget.h"
#include "ui_widget.h"
#include "taqikema.h"
#include <QMenu>
#include<QPoint>
#include<QMouseEvent>
#include <QSystemTrayIcon>
#include<QMovie>
#include <QThread>
#include <QMessageBox>

extern QWidget *t;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);  // 隐藏窗口选项
    this->setAttribute(Qt::WA_DeleteOnClose); // close 时析构
    ui->label_5->setVisible(false);
    //初始化系统托盘
    systemtrayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/login/lib/shezhang.png");
    //添加图标
    systemtrayicon->setIcon(icon);
    //当鼠标悬浮，显示文字
    systemtrayicon->setToolTip("Taqikema");
    //显示图标
    systemtrayicon->show();
    // 菜单栏
    menu = new QMenu(this);
    m_pMinAction = new QAction("min");
    m_pShowAction = new QAction("show");
    m_pCloseAction = new QAction("exit");
    menu->addAction(m_pMinAction);
    menu->addAction(m_pShowAction);
    menu->addAction(m_pCloseAction);
    systemtrayicon->setContextMenu(menu);
    //Taqikema ID文本框
    QAction * searchAction = new QAction(ui->uName);
    searchAction->setIcon(QIcon(":/login/lib/id.png"));
    ui->uName->addAction(searchAction,QLineEdit::LeadingPosition);//表示action所在方位（左侧）。
    //Taqikema 密码文本框
    QAction * searchAction2 = new QAction(ui->lineEdit_2);
    searchAction2->setIcon(QIcon(":/login/lib/R.png"));
    ui->lineEdit_2->addAction(searchAction2,QLineEdit::LeadingPosition);//表示action所在方位（左侧）。

    connect(m_pMinAction,SIGNAL(triggered(bool)),this,SLOT(minwidget()));
    connect(m_pShowAction,SIGNAL(triggered(bool)),this,SLOT(showwidget()));
    connect(m_pCloseAction,SIGNAL(triggered(bool)),qApp,SLOT(quit()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_toolButton_2_clicked()
{
    this->hide();
}


void Widget::on_toolButton_clicked()
{
    this->close();
}


void Widget::mousePressEvent(QMouseEvent* event)
{
    mouse_pos = event->globalPos();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}

void Widget::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPos();
    //this->move(pos);
    this->move(pos - diff_pos);
}

void Widget::on_pushButton_clicked()
{
    QString name = ui->uName->text();
    if(name == ""){
        QMessageBox::warning(this,"Warning","Send Message should not be null !");
        return;
    }
    // 这里要加上对账号密码的判断


    // 登录成功，进入塔奇克马桌宠
    ui->label_5->setVisible(true);
    QMovie *movie = new QMovie(":/login/lib/hello.gif");
    ui->label_5->setMovie(movie); // 1. 设置要显示的 GIF 动画图片
    movie->start();         // 2. 启动动画
    ui->label_5->setScaledContents(true); // 自适应大小
    ui->label_5->show();

    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        // GIF 动画执行一次就结束
        if (frameNumber == movie->frameCount() - 1) {
            movie->stop();
            QThread::msleep(1000);  // sleep 1s
            t = new Taqikema(name,nullptr);
            t->show();
            // systemtrayicon->setContextMenu(t->menu);  // 一种可能的解决办法
            this->close();
        }
    });


}

void Widget::minwidget(){
    this->showMinimized();
    // qDebug() << "Custom menu item clicked!";
}

void Widget::showwidget(){
    this->showNormal();
}


void Widget::closewidget(){
    QApplication::quit();
}
