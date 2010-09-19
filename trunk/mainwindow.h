#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include "mdichild.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow *getInstance()
    {
        static MainWindow m;
        return &m;
    }

private:
    Ui::MainWindow *ui;
    MdiChild *getActiveWindow();
    QMdiSubWindow *getSubWindowByFile(QString &fileName);

private slots:
    void on_actionSettings_triggered();
    void on_actionOpen_triggered();
    void on_actionNew_triggered();
    MdiChild *createMdiChild();

};

#endif // MAINWINDOW_H
