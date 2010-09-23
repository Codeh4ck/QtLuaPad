#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupToolbar();
    editor = new LuaEditor();
    setWindowTitle("QtLuaPad");
    QLabel *label = new QLabel;
    label->setText(QDate::currentDate().toString());
    ui->statusBar->addPermanentWidget(label);
    this->setCentralWidget(editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{

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
