#ifndef LABELMENU_H
#define LABELMENU_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QAction>
#include <QMenu>

class LabelMenu : public QLabel
{
    Q_OBJECT
public:
    LabelMenu();

    explicit LabelMenu(QWidget *parent = nullptr);

protected:
    //重写单击和双击事件
    virtual void mousePressEvent(QMouseEvent *event); //单击和右键事件
    virtual void mouseDoubleClickEvent(QMouseEvent *event); //双击事件

private:

signals:
    //自定义信号,在mousePressEvent事件发生时触发
    void clicked(); //单击信号
    void clicked_right(); //右键单击信号
    void doubleClicked();//双击信号

public slots:

};

#endif // LABELMENU_H
