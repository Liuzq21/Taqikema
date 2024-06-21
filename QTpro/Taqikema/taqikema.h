#ifndef TAQIKEMA_H
#define TAQIKEMA_H


#include <QWidget>
#include <QSystemTrayIcon>
#include "labelmenu.h"
// #include "mymenu.h"  // 不可以在这里加头文件，因为menu从上界面widget传来，会报错重复定义
class MyMenu;  // 声明但不定义，引用头文件放到.cpp文件中


namespace Ui {
class Taqikema;
}

class Taqikema : public QWidget
{
    Q_OBJECT

public:
    explicit Taqikema(QString _uName, QWidget *parent);
    ~Taqikema();
    QString getUserName();

private slots:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent * ev);
    void right_menu(); //弹出右键菜单

private:
    Ui::Taqikema *ui;
    QPoint diff_pos;  // 鼠标和窗口的相对位移
    QPoint window_pos;
    QPoint mouse_pos;
    QSystemTrayIcon  * systemtrayicon;  //系统托盘

    QString uName;  // 用户名字
    MyMenu *menu; // 菜单变量

};

#endif // TAQIKEMA_H
