#include "taqikema.h"
#include "ui_taqikema.h"
#include "labelmenu.h"
#include<QPoint>
#include<QMouseEvent>
#include<QMovie>

Taqikema::Taqikema(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Taqikema)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint); // 取消菜单栏
    this->setAttribute(Qt::WA_TranslucentBackground,true); //设置背景透明
    // 欢迎gif
    /*QLabel *label = new QLabel();
    QMovie *movie = new QMovie("/Users/Biao/Desktop/x.gif");
    label->setMovie(movie); // 1. 设置要显示的 GIF 动画图片
    movie->start();         // 2. 启动动画
    label->show();

    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        // GIF 动画执行一次就结束
        if (frameNumber == movie->frameCount() - 1) {
            movie->stop();
        }
    });*/

    // 待机gif
    ui->label ->setPixmap(QPixmap(":/login/lib/head3.png"));
    ui->label ->setScaledContents(true);

    // label右键菜单
    initMenu();

}

Taqikema::~Taqikema()
{
    delete ui;
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

//初始化右键菜单
void Taqikema::initMenu(){
    /* 创建右键菜单 */
    QAction *test_menu = new QAction("测试 (&A)",this); //添加测试功能菜单，快捷键A

    /* 添加菜单项 */
    menu->addAction(test_menu);

    /* 连接槽函数 */
    connect(ui->label,SIGNAL(clicked_right()),this,SLOT(right_menu())); //连接label标签点击事件，此处不连接就不会弹出右键菜单
    //connect(test_menu,SIGNAL(triggered()),this,SLOT(test())); //连接 测试 功能

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
    menu->show();
}

