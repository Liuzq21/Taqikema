#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_toolButton_clicked()
{
    this->hide();
}


void Widget::on_toolButton_2_clicked()
{
    this->close();
}

