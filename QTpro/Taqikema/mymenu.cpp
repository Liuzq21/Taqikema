#include "mymenu.h"
#include "chathome.h"
#include "widget.h"
#include "taqikema.h"
#include<QApplication>

MyMenu::MyMenu(): QMenu(nullptr){}

MyMenu::MyMenu(Taqikema* t): QMenu(nullptr) {

    this->uName = t->getUserName();
    // 菜单栏
    m_pChatHomeAction = addAction("ChatHome");
    m_pMinAction = addAction("Minilize");
    m_pShowAction = addAction("Show");
    addSeparator();
    m_pCloseAction = addAction("Exit");


    // menu->addAction(m_pMinAction);
    // menu->addAction(m_pShowAction);
    // menu->addSeparator();
    // menu->addAction(m_pCloseAction);


    // connect
    connect(m_pChatHomeAction,SIGNAL(triggered(bool)),this,SLOT(openChatHome()));
    connect(m_pMinAction,SIGNAL(triggered(bool)),this,SLOT(minwidget()));
    connect(m_pShowAction,SIGNAL(triggered(bool)),this,SLOT(showwidget()));
    connect(m_pCloseAction,SIGNAL(triggered(bool)),this,SLOT(closewidget()));
}

void MyMenu::openChatHome(){
    ch = new ChatHome(this->uName); // 关闭的时候记得释放
    ch->show();
}

MyMenu::~MyMenu(){
    delete m_pMinAction;
    delete m_pShowAction;
    delete m_pCloseAction;
}

void MyMenu::minwidget(){
    this->showMinimized();
    // qDebug() << "Custom menu item clicked!";
}

void MyMenu::showwidget(){
    this->showNormal();
}


void MyMenu::closewidget(){
    QApplication::quit();
}
