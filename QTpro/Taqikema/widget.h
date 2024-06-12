#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMenu>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

    void showwidget();
    void closewidget();

private:
    Ui::Widget *ui;
    QPoint diff_pos;  // 鼠标和窗口的相对位移
    QPoint window_pos;
    QPoint mouse_pos;
    QSystemTrayIcon  * systemtrayicon;  //系统托盘
    QMenu * menu;  // 菜单栏
    QAction *m_pShowAction;
    QAction *m_pCloseAction;


};
#endif // WIDGET_H
