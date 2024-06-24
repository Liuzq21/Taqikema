#include "widget.h"
#include "taqikema.h"
#include "chathome.h"
#include <QApplication>

QWidget *t;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget *w = new Widget();  // 动态申请对象，但是不手动delete，等close时析构
    w->show();
    // Widget w;
    // w.show();

    // Taqikema t;
    // t.show();
    // ChatHome ch;
    // ch.show();
    return a.exec();
}
