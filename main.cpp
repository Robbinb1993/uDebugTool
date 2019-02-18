#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont("./fonts/DejaVuSans.ttf");
    QFontDatabase::addApplicationFont("./fonts/COUR.TTF");
    QFontDatabase::addApplicationFont("./fonts/couri.ttf");
    QFontDatabase::addApplicationFont("./fonts/coure.fon");
    QFontDatabase::addApplicationFont("./fonts/courbi.ttf");
    QFontDatabase::addApplicationFont("./fonts/courbd.ttf");

    MainWindow w;
    w.show();

    return a.exec();
}
