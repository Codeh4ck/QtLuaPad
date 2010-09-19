#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "options.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
    QDate date;
    QTime time;
    QLabel *newLabel = new QLabel;
    ui->statusBar->addPermanentWidget(newLabel);
    newLabel->setText(tr("Date: %1 / Time %2").arg
                               (date.currentDate().toString(),
                                time.currentTime().toString()));
    QSettings settings("Delirium", "QtLuaPad");
    settings.beginGroup("QtLuaPad_Main");
    resize(settings.value("size").toSize());
    move(settings.value("pos").toPoint());
    settings.endGroup();
}

MainWindow::~MainWindow()
{
    QSettings settings("Delirium", "QtLuaPad");
    settings.beginGroup("QtLuaPad_Main");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    MdiChild *mdiChild = createMdiChild();
    mdiChild->show();
}

MdiChild *MainWindow::createMdiChild()
{
    MdiChild *mdiChild = new MdiChild;
    ui->mdiArea->addSubWindow(mdiChild);
    return mdiChild;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);

        MdiChild *child = createMdiChild();
        if (child->loadFile(fileName)) {
            ui->statusBar->showMessage(tr("File loaded"), 2000);
            child->show();
        } else {
            child->close();
        }
}

void MainWindow::on_actionSettings_triggered()
{
    Options *options = new Options(this);
    options->showNormal();
}

MdiChild *MainWindow::getActiveWindow()
{
    if(ui->mdiArea->subWindowList().length() > 0)
    {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(ui->mdiArea->activeSubWindow()->widget());
        return mdiChild;
    }

    return 0;
}

QMdiSubWindow *MainWindow::getSubWindowByFile(QString &fileName)
{
    QString filePath = QFileInfo(fileName).canonicalFilePath();

    foreach(QMdiSubWindow *mdiChild, ui->mdiArea->subWindowList())
    {
        MdiChild *child = qobject_cast<MdiChild *>(mdiChild->widget());
        if(child->currentFile() == filePath)
            return mdiChild;
    }

    return 0;
}
