#include "widget.h"
#include "ui_widget.h"
#include<QPoint>
#include<QMouseEvent>
#include<QMenu>

#include <QSystemTrayIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
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
    m_pShowAction = new QAction("show");
    m_pCloseAction = new QAction("exit");
    menu->addAction(m_pShowAction);
    menu->addSeparator();
    menu->addAction(m_pCloseAction);
    systemtrayicon->setContextMenu(menu);
    connect(m_pShowAction,SIGNAL(triggered(bool)),this,SLOT(showwidget()));
    connect(m_pCloseAction,SIGNAL(triggered(bool)),this,SLOT(closewidget()));

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

void Widget::showwidget()
{
    this->show();
}

void Widget::closewidget()
{
    this->close();
}
