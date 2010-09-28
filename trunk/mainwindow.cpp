#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "definitions.h"
#include "options.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupToolbar();
    setWindowTitle(APPNAME);
    QLabel *label = new QLabel;
    label->setText(QDate::currentDate().toString());
    ui->statusBar->addPermanentWidget(label);
    mdi = new QMdiArea(this);
    this->setCentralWidget(mdi);
    this->setWindowIcon(QIcon(":/winicon.png"));
    mdi->setViewMode(QMdiArea::TabbedView);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(mdi->subWindowList().count() > 0)
    {
        QMessageBox::StandardButton ret =
                QMessageBox::question(this, "Attention!",
                    tr("If you close the editor "
                       "without saving your scripts, "
                       "all changes will be lost. "
                       "Would you like to proceed?"),
                    QMessageBox::Yes | QMessageBox::No,
                    QMessageBox::No);
        if(ret == QMessageBox::Yes)
        {
            event->accept();
            delete ui;
        }
        else if(ret == QMessageBox::No)
            event->ignore();
    }
    event->accept();
}

void MainWindow::newFile()
{
    on_actionNew_triggered();
    ui->statusBar->showMessage("Initialized new script successfully!", 4000);
}

void MainWindow::saveFile()
{
    if(getActiveEditor() && getActiveEditor()->save())
        ui->statusBar->showMessage("File successfully saved!", 4000);
}

void MainWindow::openFile()
{
    QString file = QFileDialog::getOpenFileName(this, "Open Script", "", "Lua Scripts (*.lua)");
    if(!file.isEmpty())
    {
        QMdiSubWindow *w = getChildByPath(file);
        if(w)
        {
            mdi->setActiveSubWindow(w);
            return;
        }
        LuaEditor *editor = createMdiChild();
        if(editor->openFile(file))
        {
            ui->statusBar->showMessage(tr("Loaded file: %1.").arg(file));
            mdi->addSubWindow(editor);
            mdi->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(editor));
            editor->showMaximized();
        } else {
            editor->close();
        }
    }
}

LuaEditor *MainWindow::createMdiChild()
{
    LuaEditor *editor = new LuaEditor;
    return editor;
}

LuaEditor *MainWindow::getActiveEditor()
{
    QMdiSubWindow *window = mdi->activeSubWindow();
    if(window)
    {
        LuaEditor *L = qobject_cast<LuaEditor *>(window->widget());
        return L;
    }
    return 0;
}

QMdiSubWindow *MainWindow::getChildByPath(const QString &path)
{
    QString canonicalFilePath = QFileInfo(path).canonicalFilePath();
    foreach (QMdiSubWindow *window, mdi->subWindowList()) {
        LuaEditor *mdiChild = qobject_cast<LuaEditor *>(window->widget());
        if (mdiChild->currentFileP() == canonicalFilePath)
            return window;
    }
    return 0;
}

void MainWindow::setStatusBarText(const QString &text)
{
    ui->statusBar->showMessage(text);
}

void MainWindow::setupToolbar()
{
    ui->mainToolBar->setMovable(false);
    ui->mainToolBar->addAction(QIcon((":/new.png")),  "New File",  this,  SLOT(newFile()));
    ui->mainToolBar->addAction(QIcon((":/open.png")),  "Open File",  this,  SLOT(openFile()));
    ui->mainToolBar->addAction(QIcon((":/disk.png")),  "Save File",  this,  SLOT(saveFile()));
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(QIcon(":/find.png"), tr("Find..."),  this,  SLOT(showFind()));
    ui->mainToolBar->addAction(QIcon(":/replace.png"), tr("Replace..."),  this,  SLOT(showReplace()));
    ui->mainToolBar->addAction(QIcon(":/cut.png"), tr("Cut"),  this,  SLOT(cut()));
    ui->mainToolBar->addAction(QIcon(":/copy.png"), tr("Copy"),  this,  SLOT(copy()));
    ui->mainToolBar->addAction(QIcon(":/paste.png"), tr("Paste"),  this,  SLOT(paste()));
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(QIcon(":/zoomin.png"), tr("Zoom in"),  this,  SLOT(zoomIn()));
    ui->mainToolBar->addAction(QIcon(":/zoomout.png"), tr("Zoom out"),  this,  SLOT(zoomOut()));
    ui->mainToolBar->addAction(QIcon(":/zoomdef.png"), tr("Default zoom"),  this,  SLOT(zoomDef()));
}

void MainWindow::on_actionNew_triggered()
{
    LuaEditor *child = createMdiChild();
    mdi->addSubWindow(child);
    child->newFile();
    child->setWindowIcon(QIcon(":/winicon.png"));
    child->showMaximized();
}

void MainWindow::on_actionOpen_triggered()
{
    openFile();
}

void MainWindow::on_actionSave_triggered()
{
    saveFile();
}

void MainWindow::on_actionSave_As_triggered()
{
    if(getActiveEditor() && getActiveEditor()->saveAs())
        ui->statusBar->showMessage("Saved new file successfully!", 4000);
}


void MainWindow::on_actionUndo_triggered()
{
    if(getActiveEditor())
        getActiveEditor()->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    if(getActiveEditor())
        getActiveEditor()->redo();
}

void MainWindow::on_actionCut_triggered()
{
    if(getActiveEditor())
        getActiveEditor()->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    if(getActiveEditor())
        getActiveEditor()->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    if(getActiveEditor())
        getActiveEditor()->paste();
}

void MainWindow::on_actionDelete_Line_triggered()
{
    ui->statusBar->showMessage("Not implemented yet.");
}

void MainWindow::on_actionDelete_Selected_triggered()
{
    if(getActiveEditor())
        getActiveEditor()->removeSelectedText();
}

void MainWindow::on_actionSelect_All_triggered()
{
    if(getActiveEditor())
        getActiveEditor()->selectAll(true);
}


void MainWindow::on_actionClose_triggered()
{
    QApplication::closeAllWindows();
}

void MainWindow::on_actionOtland_triggered()
{
    QDesktopServices::openUrl(QUrl(ORGURL));
}

void MainWindow::zoomIn()
{
    if(getActiveEditor())
        getActiveEditor()->zoomIn();
}

void MainWindow::zoomOut()
{
    if(getActiveEditor())
        getActiveEditor()->zoomOut();
}

void MainWindow::zoomDef()
{
    if(getActiveEditor())
        getActiveEditor()->zoomTo(0);
}

void MainWindow::on_actionQtLuaPad_triggered()
{
    QMessageBox::about(this, "About QtLuaPad",
                       tr("<b>Author:</b> Nikolas S. Andreou."
                          "<br />"
                          "<b>Version:</b> %1."
                          "<br />"
                          "<b>Licence:</b> GPL v3."
                          "<br />"
                          "<b>Website:</b> <a href='http://otland.net/'>Otland.</a>"
                          "<br />"
                          "<b>Icons made by:</b> Unknown creator.").arg(APPVRSN));
}

void MainWindow::on_actionOptions_triggered()
{
    Options *opt = new Options(this);
    opt->showNormal();
}

void MainWindow::cut()
{
    on_actionCut_triggered();
}

void MainWindow::copy()
{
    on_actionCopy_triggered();
}

void MainWindow::paste()
{
    on_actionPaste_triggered();
}
