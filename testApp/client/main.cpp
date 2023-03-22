#include "widget.h"

#include <QApplication>
#include <QPainter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QPainter * painter = new QPainter(  &w );
    w.show();
    QPen* red= new QPen()
    painter->background(  );

    return a.exec();
}
