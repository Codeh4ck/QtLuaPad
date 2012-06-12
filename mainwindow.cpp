#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "definitions.h"
#include "options.h"
#include "finddialog.h"
#include "questcreator.h"
#include "about.h"

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

    //Read MainWindow settings from registry.
    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    this->move(settings.value("pos").toPoint());
    QSize s = settings.value("size").toSize();

    if(s.width() == 1280 && s.height() == 962)
        this->setWindowState(Qt::WindowMaximized);
    else
        this->resize(s);

    int view = settings.value("mdiview").toInt();
    (view == 1)? mdi->setViewMode(QMdiArea::TabbedView) : mdi->setViewMode(QMdiArea::SubWindowView);
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //Write MainWindow settings to registry.

    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    settings.setValue("pos", this->pos());
    settings.setValue("size", this->size());
    settings.endGroup();

    if(mdi->subWindowList().count() > 0)
    {

        QString windows;
        foreach(QMdiSubWindow *window, mdi->subWindowList())
        {
            if(window)
            {
                LuaEditor *editor = qobject_cast<LuaEditor *>(window->widget());
                if(editor->isModified())
                {
                    windows += "" +editor->windowTitle() + "\n";
                }
            }
        }
        if(windows != "")
        {
            QMessageBox::StandardButton ret =
                  QMessageBox::warning(this, "Attention!",
                      tr("If you close the editor "
                         "without saving your scripts, "
                         "all changes will be lost.\n"
                         "Unsaved Scripts:\n"
                         "\n%1\n"
                         "Would you like to proceed?").arg(windows),
                      QMessageBox::Yes | QMessageBox::No,
                      QMessageBox::No);
            if(ret == QMessageBox::Yes)
            {
                event->accept();
                delete ui;
            }
            else if(ret == QMessageBox::No)
                event->ignore();
        } else {
            event->accept();
            delete ui;
        }
    }
}

void MainWindow::newFile()
{
    on_actionNew_triggered();
}

void MainWindow::saveFile()
{
    if(getActiveEditor() && getActiveEditor()->save())
        ui->statusBar->showMessage("File successfully saved!", 4000);
}

void MainWindow::_openFile(QString file)
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
	setWindowState(Qt::WindowMaximized);
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
    ui->mainToolBar->addAction(QIcon(":/replace.png"), tr("Replace..."),  this,  SLOT(showGotoLine()));
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
    ui->statusBar->showMessage("Initialized new script successfully!", 4000);
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
    About *about = new About(this);
    about->showNormal();
    about->setWindowTitle("About QtLuaPad");
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

void MainWindow::updateSettings(int tabWidth, bool _wrap, bool _brace, bool _fold)
{
    foreach(QMdiSubWindow *window, mdi->subWindowList())
    {
            LuaEditor *editor = qobject_cast<LuaEditor *>(window->widget());

            (_wrap)? editor->setWrapMode(QsciScintilla::WrapWord) :
                    editor->setWrapMode(QsciScintilla::WrapNone);
            (_brace)? editor->setBraceMatching(QsciScintilla::StrictBraceMatch) :
                    editor->setBraceMatching(QsciScintilla::NoBraceMatch);
            (_fold)? editor->setFolding(QsciScintilla::BoxedTreeFoldStyle) :
                    editor->setFolding(QsciScintilla::NoFoldStyle);
            editor->setTabWidth(tabWidth);
    }
}

void MainWindow::updateMdiView(int viewType)
{
    if(viewType == 1)
        mdi->setViewMode(QMdiArea::TabbedView);
    else
        mdi->setViewMode(QMdiArea::SubWindowView);
}

void MainWindow::showFind()
{
    if(mdi->subWindowList().count() > 0)
    {
        FindDialog *dialog = new FindDialog(this);
        dialog->setEditor(getActiveEditor());
        dialog->showNormal();
    } else
        ui->statusBar->showMessage("No active editor found to open the Find Dialog.", 4000);
}

void MainWindow::on_actionQuest_Creator_triggered()
{
	QuestCreator *quest = new QuestCreator(this);
	quest->show();
}

void MainWindow::on_actionPrint_triggered()
{
    ui->statusBar->showMessage("Not implemented yet.", 4000);
}

void MainWindow::on_actionDebuger_triggered()
{
    ui->statusBar->showMessage("Not implemented yet.", 4000);
}

void MainWindow::on_actionDelirium_triggered()
{
    QDesktopServices::openUrl(QUrl(DELIRIUMSPROF));
}

void MainWindow::on_actionFallen_triggered()
{
    QDesktopServices::openUrl(QUrl(FALLENSPROF));
}

void MainWindow::on_actionFind_triggered()
{
    showFind();
}

void MainWindow::on_actionChojrak_triggered()
{
    QDesktopServices::openUrl(QUrl(CHOJRAKSPROF));
}

void MainWindow::showGotoLine()
{
    if(mdi->subWindowList().count() > 0)
    {
        bool ok = false;
        int ret = QInputDialog::getInteger(0, "Goto Line", "Enter a line number to goto:", 1, 1,
                                           getActiveEditor()->lines(), 10, &ok);
        if(ok)
        {
            ret--;
            if(getActiveEditor()->lines() >= ret)
            {
                getActiveEditor()->setSelection(ret, 0, ret, getActiveEditor()->lineLength(ret) - 1);
                getActiveEditor()->ensureLineVisible(ret);
            }
        }
    } else
        ui->statusBar->showMessage("No active editor found to open the Goto Line dialog!", 4000);
}

void MainWindow::on_actionGoto_Line_triggered()
{
    showGotoLine();
}
