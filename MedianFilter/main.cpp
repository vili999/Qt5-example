#include "mainwindow.h"
#include "imagechanger.h"
#include <QApplication>
#include <QtTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
