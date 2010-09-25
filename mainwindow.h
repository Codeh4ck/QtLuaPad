#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "luaeditor.h"

namespace Ui {
    class MainWindow;
}

class LuaEditor;

QT_BEGIN_NAMESPACE
class QMdiArea;
class QMdiSubWindow;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setStatusBarText(const QString &text);

    static MainWindow *getInstance()
    {
        static MainWindow window;
        return &window;
    }

    LuaEditor *createMdiChild();
    LuaEditor *getActiveEditor();


private slots:
    void on_actionNew_triggered();
    void newFile();
    void openFile();
    void saveFile();
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
    QMdiArea *mdi;
    QMdiSubWindow *getChildByPath(const QString &path);
};

#endif // MAINWINDOW_H
