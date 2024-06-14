#include "mymenu.h"
#include<QApplication>

MyMenu::MyMenu(): QMenu(nullptr), win(nullptr){}

MyMenu::MyMenu(QWidget *parent): QMenu(parent), win(parent){
    // 菜单栏

    m_pMinAction = addAction("minilize");
    m_pShowAction = addAction("show");
    m_pCloseAction = addAction("exit");

    /*menu->(m_pMinAction);
    menu->(m_pShowAction);
    menu->addSeparator();
    menu->addAction(m_pCloseAction);*/


    // connect
    connect(m_pMinAction,SIGNAL(triggered(bool)),this,SLOT(minwidget()));
    connect(m_pShowAction,SIGNAL(triggered(bool)),this,SLOT(showwidget()));
    connect(m_pCloseAction,SIGNAL(triggered(bool)),this,SLOT(closewidget()));
}

void MyMenu::changeWin(QWidget* newWin){
    win = newWin;
}


MyMenu::~MyMenu(){
    delete m_pMinAction;
    delete m_pShowAction;
    delete m_pCloseAction;
}

void MyMenu::minwidget(){
    win->showMinimized();
    // qDebug() << "Custom menu item clicked!";
}

void MyMenu::showwidget(){
    win->showNormal();
}


void MyMenu::closewidget(){
    QApplication::quit();
}
