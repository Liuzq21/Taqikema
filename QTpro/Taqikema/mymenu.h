#ifndef MYMENU_H
#define MYMENU_H
#include<QMenu>
#include <QWidget>
#include <QAction>

class MyMenu : public QMenu
{
    Q_OBJECT
public:
    MyMenu();
    explicit MyMenu(QWidget *parent);
    ~MyMenu();

    void changeWin(QWidget* newWin);

private slots:
    void minwidget();
    void showwidget();
    void closewidget();

private:
    QWidget *win;
    QAction *m_pMinAction;
    QAction *m_pShowAction;
    QAction *m_pCloseAction;
};

#endif // MYMENU_H
