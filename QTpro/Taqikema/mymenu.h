#ifndef MYMENU_H
#define MYMENU_H
#include<QMenu>
#include <QWidget>
#include <QAction>

#include "chathome.h"

class Taqikema;

class MyMenu : public QMenu
{
    Q_OBJECT
public:
    MyMenu();
    explicit MyMenu(Taqikema* t);
    ~MyMenu();


private slots:
    void minwidget();
    void showwidget();
    void closewidget();
    void openChatHome();

private:
    QAction *m_pMinAction;
    QAction *m_pShowAction;
    QAction *m_pCloseAction;
    QAction *m_pChatHomeAction;

    QString uName;
    ChatHome *ch;
};

#endif // MYMENU_H
