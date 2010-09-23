#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "luaeditor.h"

namespace Ui {
    class MainWindow;
}

class LuaEditor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow *getInstance()
    {
        static MainWindow w;
        return &w;
    }

private slots:
    void newFile();
    void openFile() { }
    void saveFile() { }
    void showFind() { }
    void showReplace() { }
    void cut() { }
    void copy() { }
    void paste() { }
    void zoomIn() { }
    void zoomOut() { }
    void zoomDef() { }

private:
    Ui::MainWindow *ui;
    LuaEditor *editor;
    void setupToolbar();
};

#endif // MAINWINDOW_H
