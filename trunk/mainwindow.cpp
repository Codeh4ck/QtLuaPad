#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupToolbar();
    setWindowTitle("QtLuaPad");
    QLabel *label = new QLabel;
    label->setText(QDate::currentDate().toString());
    ui->statusBar->addPermanentWidget(label);
    mdi = new QMdiArea(this);
    this->setCentralWidget(mdi);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    QString file = QFileDialog::getOpenFileName(this);
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
    LuaEditor *window = qobject_cast<LuaEditor *>(mdi->activeSubWindow()->widget());
    return window;
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
    ui->mainToolBar->addAction(QIcon(":/copy.png"), tr("Copy"),  this,  SLOT(copy()));
    ui->mainToolBar->addAction(QIcon(":/paste.png"), tr("Paste"),  this,  SLOT(paste()));
    ui->mainToolBar->addAction(QIcon(":/cut.png"), tr("Cut"),  this,  SLOT(cut()));
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
    child->showMaximized();
}
