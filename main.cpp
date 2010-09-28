#include <QtGui/QApplication>
#include <QtGui>
#include "mainwindow.h"
#include "definitions.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setStyle(QStyleFactory::create("Plastique"));
    QApplication::setPalette(QApplication::style()->standardPalette());
    QApplication::setOrganizationDomain(ORGURL);
    QApplication::setOrganizationName(ORGNAME);
    QApplication::setApplicationName(APPNAME);
    QApplication::setApplicationVersion(APPVRSN);
    w.show();
    return a.exec();
}
