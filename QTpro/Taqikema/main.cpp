#include "widget.h"
#include "taqikema.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    // Taqikema t;
    // t.show();
    return a.exec();
}
