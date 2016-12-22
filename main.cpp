#include "mainwindow.h"
#include "bitmapmodel.h"
#include "settingswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
