#include "widget.h"
#include "taqikema.h"
#include "chathome.h"
#include "mymenu.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();
    // Taqikema t;
    // t.show();
    // ChatHome ch;
    // ch.show();
    return a.exec();
}
