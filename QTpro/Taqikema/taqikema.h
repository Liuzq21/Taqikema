#ifndef TAQIKEMA_H
#define TAQIKEMA_H

#include <QWidget>
#include<QMenu>
#include "labelmenu.h"
#include "mymenu.h"

namespace Ui {
class Taqikema;
}

class Taqikema : public QWidget
{
    Q_OBJECT

public:
    explicit Taqikema(MyMenu* _menu=nullptr,QWidget *parent = nullptr);
    ~Taqikema();

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
    MyMenu *menu; // 菜单变量



};

#endif // TAQIKEMA_H
