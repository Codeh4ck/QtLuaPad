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
    //~MainWindow();
    void setStatusBarText(const QString &text);

    static MainWindow *getInstance()
    {
        static MainWindow window;
        return &window;
    }

    LuaEditor *createMdiChild();
    LuaEditor *getActiveEditor();
    void updateSettings(int tabWidth, bool _wrap, bool _brace, bool _fold);
    void updateMdiView(int viewType);
    QMdiArea *mdi;

protected:
    void closeEvent(QCloseEvent *event);

public slots:
	void _openFile(QString file);

private slots:
    void on_actionGoto_Line_triggered();
    void on_actionChojrak_triggered();
    void on_actionFind_triggered();
    void on_actionFallen_triggered();
    void on_actionDelirium_triggered();
    void on_actionDebuger_triggered();
    void on_actionPrint_triggered();
    void on_actionQuest_Creator_triggered();
    void on_actionOptions_triggered();
    void on_actionQtLuaPad_triggered();
    void on_actionOtland_triggered();
    void on_actionSelect_All_triggered();
    void on_actionDelete_Selected_triggered();
    void on_actionDelete_Line_triggered();
    void on_actionPaste_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionRedo_triggered();
    void on_actionUndo_triggered();
    void on_actionClose_triggered();
    void on_actionSave_As_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionNew_triggered();
    void newFile();
    void openFile();
    void saveFile();
    void showFind();
    void showGotoLine();
    void cut();
    void copy();
    void paste();
    void zoomIn();
    void zoomOut();
    void zoomDef();

private:
    Ui::MainWindow *ui;
    LuaEditor *editor;
    void setupToolbar();
    QMdiSubWindow *getChildByPath(const QString &path);
};

#endif // MAINWINDOW_H
