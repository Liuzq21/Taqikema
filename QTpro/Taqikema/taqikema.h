#ifndef TAQIKEMA_H
#define TAQIKEMA_H

#include <QWidget>
#include "labelmenu.h"

namespace Ui {
class Taqikema;
}

class Taqikema : public QWidget
{
    Q_OBJECT

public:
    explicit Taqikema(QWidget *parent = nullptr);
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
    QMenu *menu = new QMenu(this); // 菜单变量

    void initMenu(); //初始化右键菜单
};

#endif // TAQIKEMA_H
