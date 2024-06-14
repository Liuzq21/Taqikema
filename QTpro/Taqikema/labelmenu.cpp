#include "labelmenu.h"

//构造函数
LabelMenu::LabelMenu(QWidget *parent) :
    QLabel(parent)
{

}

//重写mousePressEvent单击事件
void LabelMenu::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        emit clicked(); //发送左键单击信号
        break;

    case Qt::RightButton:
        emit clicked_right(); //发送右键单击信号
        break;
    }

    //将该事件传给父类处理
    QLabel::mousePressEvent(event);
}

//重写mouseDoubleClickEvent双击事件
void LabelMenu::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit doubleClicked(); //发送左键双击信号
    }
    //将该事件传给父类处理
    QLabel::mouseDoubleClickEvent(event);
}
