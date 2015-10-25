#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //add write to file

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
