#include <QtGui/QApplication>
#include <QtGui>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("QtLuaPad");
    a.setApplicationVersion("1.0");
    a.setOrganizationDomain("http://otland.net/");
    a.setOrganizationName("Delirium");
    a.setStyle(new QPlastiqueStyle);
    a.setPalette(a.style()->standardPalette());
    MainWindow w;
    w.show();

    return a.exec();
}
