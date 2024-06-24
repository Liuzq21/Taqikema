#ifndef TAQIKEMA_H
#define TAQIKEMA_H

#include <QMenu>
#include <QWidget>
#include <QSystemTrayIcon>
#include "labelmenu.h"

// #include "chathome.h"
// class ChatHome;  // 声明，但不用头文件，因为链接报错

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
    // menu option
    void minwidget();
    void showwidget();
    void closewidget();
    void openChatHome();

private:
    Ui::Taqikema *ui;
    QString uName;  // 用户名字
    QPoint diff_pos;  // 鼠标和窗口的相对位移
    QPoint window_pos;
    QPoint mouse_pos;
    QSystemTrayIcon  * systemtrayicon;  //系统托盘

    QMenu *menu; // 菜单变量
    QAction *m_pMinAction;
    QAction *m_pShowAction;
    QAction *m_pCloseAction;
    QAction *m_pChatHomeAction;
    bool chOpened;



};

#endif // TAQIKEMA_H
