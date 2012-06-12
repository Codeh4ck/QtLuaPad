/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jun 10 05:31:38 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete_Line;
    QAction *actionDelete_Selected;
    QAction *actionSelect_All;
    QAction *actionFind;
    QAction *actionGoto_Line;
    QAction *actionDebuger;
    QAction *actionOptions;
    QAction *actionQtLuaPad;
    QAction *actionOtland;
    QAction *actionQuest_Creator;
    QAction *actionDelirium;
    QAction *actionFallen;
    QAction *actionChojrak;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuDelete;
    QMenu *menuAbout;
    QMenu *menuContact;
    QMenu *menuTools;
    QMenu *menuOpen_Tibia_Tools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(481, 386);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/winicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/diskall.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon4);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon5);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon6);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon7);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon8);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon9);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon10);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon11);
        actionDelete_Line = new QAction(MainWindow);
        actionDelete_Line->setObjectName(QString::fromUtf8("actionDelete_Line"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/x.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Line->setIcon(icon12);
        actionDelete_Selected = new QAction(MainWindow);
        actionDelete_Selected->setObjectName(QString::fromUtf8("actionDelete_Selected"));
        actionDelete_Selected->setIcon(icon12);
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/doc.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_All->setIcon(icon13);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon14);
        actionGoto_Line = new QAction(MainWindow);
        actionGoto_Line->setObjectName(QString::fromUtf8("actionGoto_Line"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/doc_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGoto_Line->setIcon(icon15);
        actionDebuger = new QAction(MainWindow);
        actionDebuger->setObjectName(QString::fromUtf8("actionDebuger"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/warning2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebuger->setIcon(icon16);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/cog.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon17);
        actionQtLuaPad = new QAction(MainWindow);
        actionQtLuaPad->setObjectName(QString::fromUtf8("actionQtLuaPad"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQtLuaPad->setIcon(icon18);
        actionOtland = new QAction(MainWindow);
        actionOtland->setObjectName(QString::fromUtf8("actionOtland"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOtland->setIcon(icon19);
        actionQuest_Creator = new QAction(MainWindow);
        actionQuest_Creator->setObjectName(QString::fromUtf8("actionQuest_Creator"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/font_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuest_Creator->setIcon(icon20);
        actionDelirium = new QAction(MainWindow);
        actionDelirium->setObjectName(QString::fromUtf8("actionDelirium"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/session_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelirium->setIcon(icon21);
        actionFallen = new QAction(MainWindow);
        actionFallen->setObjectName(QString::fromUtf8("actionFallen"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/session.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFallen->setIcon(icon22);
        actionChojrak = new QAction(MainWindow);
        actionChojrak->setObjectName(QString::fromUtf8("actionChojrak"));
        actionChojrak->setIcon(icon22);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuDelete = new QMenu(menuEdit);
        menuDelete->setObjectName(QString::fromUtf8("menuDelete"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuContact = new QMenu(menuAbout);
        menuContact->setObjectName(QString::fromUtf8("menuContact"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuOpen_Tibia_Tools = new QMenu(menuTools);
        menuOpen_Tibia_Tools->setObjectName(QString::fromUtf8("menuOpen_Tibia_Tools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(menuDelete->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionGoto_Line);
        menuDelete->addAction(actionDelete_Line);
        menuDelete->addAction(actionDelete_Selected);
        menuAbout->addAction(actionQtLuaPad);
        menuAbout->addAction(actionOtland);
        menuAbout->addAction(menuContact->menuAction());
        menuContact->addAction(actionDelirium);
        menuContact->addAction(actionFallen);
        menuContact->addAction(actionChojrak);
        menuTools->addAction(actionDebuger);
        menuTools->addAction(menuOpen_Tibia_Tools->menuAction());
        menuTools->addAction(actionOptions);
        menuOpen_Tibia_Tools->addAction(actionQuest_Creator);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionDelete_Line->setText(QApplication::translate("MainWindow", "Delete Line", 0, QApplication::UnicodeUTF8));
        actionDelete_Selected->setText(QApplication::translate("MainWindow", "Delete Selected", 0, QApplication::UnicodeUTF8));
        actionDelete_Selected->setShortcut(QApplication::translate("MainWindow", "Ctrl+Del", 0, QApplication::UnicodeUTF8));
        actionSelect_All->setText(QApplication::translate("MainWindow", "Select All", 0, QApplication::UnicodeUTF8));
        actionSelect_All->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionGoto_Line->setText(QApplication::translate("MainWindow", "Goto Line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGoto_Line->setToolTip(QApplication::translate("MainWindow", "Goto Line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionGoto_Line->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionDebuger->setText(QApplication::translate("MainWindow", "Debuger", 0, QApplication::UnicodeUTF8));
        actionDebuger->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        actionOptions->setShortcut(QApplication::translate("MainWindow", "Shift+O", 0, QApplication::UnicodeUTF8));
        actionQtLuaPad->setText(QApplication::translate("MainWindow", "About QtLuaPad", 0, QApplication::UnicodeUTF8));
        actionQtLuaPad->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOtland->setText(QApplication::translate("MainWindow", "Otland", 0, QApplication::UnicodeUTF8));
        actionOtland->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionQuest_Creator->setText(QApplication::translate("MainWindow", "Quest Creator", 0, QApplication::UnicodeUTF8));
        actionDelirium->setText(QApplication::translate("MainWindow", "Delirium", 0, QApplication::UnicodeUTF8));
        actionFallen->setText(QApplication::translate("MainWindow", "Fallen", 0, QApplication::UnicodeUTF8));
        actionChojrak->setText(QApplication::translate("MainWindow", "chojrak", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuDelete->setTitle(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuContact->setTitle(QApplication::translate("MainWindow", "Contact", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuOpen_Tibia_Tools->setTitle(QApplication::translate("MainWindow", "Open Tibia Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
