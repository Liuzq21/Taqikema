#include "taqikema.h"
#include "ui_taqikema.h"
#include "labelmenu.h"
#include "chathome.h"
#include<QPoint>
#include<QMouseEvent>
#include<QMovie>
#include<QAction>
#include <QSystemTrayIcon>
#include <QMenu>

Taqikema::Taqikema(QString _uName, QWidget *parent)
    : uName(_uName), QWidget(parent), chOpened(false)
    , ui(new Ui::Taqikema)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint); // 取消菜单栏
    this->setAttribute(Qt::WA_TranslucentBackground,true); //设置背景透明
    //初始化系统托盘
    systemtrayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/login/lib/shezhang.png");
    systemtrayicon->setIcon(icon);
    systemtrayicon->setToolTip("Taqikema");
    systemtrayicon->show();
    // Menu init
    m_pChatHomeAction = new QAction("ChatHome");
    m_pMinAction = new QAction("Minilize");
    m_pShowAction = new QAction("Show");
    m_pCloseAction = new QAction("Exit");

    menu = new QMenu(this);
    menu->addAction(m_pChatHomeAction);
    menu->addAction(m_pMinAction);
    menu->addAction(m_pShowAction);
    menu->addSeparator();
    menu->addAction(m_pCloseAction);
    systemtrayicon->setContextMenu(menu);

    // label右键菜单
    connect(ui->label,SIGNAL(clicked_right()),this,SLOT(right_menu())); //连接label标签点击事件，此处不连接就不会弹出右键菜单

    // menu connect
    connect(m_pChatHomeAction,SIGNAL(triggered(bool)),this,SLOT(openChatHome()));
    connect(m_pMinAction,SIGNAL(triggered(bool)),this,SLOT(minwidget()));
    connect(m_pShowAction,SIGNAL(triggered(bool)),this,SLOT(showwidget()));
    connect(m_pCloseAction,SIGNAL(triggered(bool)),this,SLOT(closewidget()));


    // 待机gif
    // ui->label->setStyleSheet("background:transparent");
    // QMovie* wait = new QMovie(":/login/lib/Taqikema.gif");
    QMovie* wait = new QMovie(":/login/lib/waitall-unscreen.gif");
    ui->label ->setMovie(wait);
    wait->start();
    ui->label ->setScaledContents(true);
    ui->label->show();

}

Taqikema::~Taqikema()
{
    delete ui;
}

void Taqikema::openChatHome(){
    if(!this->chOpened)
    {
        ChatHome *ch;
        ch = new ChatHome(this->uName); // 关闭的时候记得释放
        this->chOpened = true;
        ch->show();
        connect(ch, &ChatHome::sgnClosed, this, [=](){
            this->chOpened = false;
        });
    }
}


void Taqikema::minwidget(){
    this->showMinimized();
    // qDebug() << "Custom menu item clicked!";
}

void Taqikema::showwidget(){
    this->showNormal();
}


void Taqikema::closewidget(){
    QApplication::quit();
}

QString Taqikema::getUserName()
{
    return this->uName;
}

void Taqikema::mousePressEvent(QMouseEvent* event)
{
    mouse_pos = event->globalPos();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}

void Taqikema::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPos();
    //this->move(pos);
    this->move(pos - diff_pos);
}

void Taqikema::resizeEvent(QResizeEvent * ev)
{
    ui->label->resize(this->size());
}

//弹出右键菜单
void Taqikema::right_menu(){
    //获取光标所在位置
    int x = cursor().pos().x();
    int y = cursor().pos().y();

    //获取菜单大小
    int w = menu->geometry().size().rwidth();
    int h = menu->geometry().size().rheight();

    //在光标位置弹出菜单
    menu->setGeometry(x,y,w,h);
    menu->exec();  // 如果用menu->show()将只会展示菜单栏第一个QAction！！
}

