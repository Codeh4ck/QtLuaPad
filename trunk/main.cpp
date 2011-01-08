#include <QtGui/QApplication>
#include <QtGui>
#include "mainwindow.h"
#include "definitions.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    QString style = settings.value("style").toString().toLatin1();
    settings.endGroup();
    QApplication::setStyle(QStyleFactory::create(style));
    QApplication::setPalette(QApplication::style()->standardPalette());
    QApplication::setOrganizationDomain(ORGURL);
    QApplication::setOrganizationName(ORGNAME);
    QApplication::setApplicationName(APPNAME);
    QApplication::setApplicationVersion(APPVRSN);

    // Simple trick to create a single instance application.
    QSharedMemory sharedMemory("QtLuaPad");
    if (sharedMemory.create(1) && sharedMemory.error() != QSharedMemory::AlreadyExists)
        w.show();
    else {
        QMessageBox::critical(0, "Warning!", "Application is already running!");
        return 1;
    }
    return a.exec();
}
