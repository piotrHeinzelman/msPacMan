#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        printf ( "*** prepare ***\r\n" );
        MainWindow w;
                   w.show();
    return a.exec();
}

