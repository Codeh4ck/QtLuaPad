/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 25. Sep 02:48:58 2010
**      by: Qt User Interface Compiler version 4.7.0
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
    QAction *actionFind_Replace;
    QAction *actionDebuger;
    QAction *actionOptions;
    QAction *actionQtLuaPad;
    QAction *actionOtland;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuDelete;
    QMenu *menuAbout;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 336);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/diskall.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon3);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon4);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon5);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon6);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon7);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon8);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon9);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon10);
        actionDelete_Line = new QAction(MainWindow);
        actionDelete_Line->setObjectName(QString::fromUtf8("actionDelete_Line"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/x.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Line->setIcon(icon11);
        actionDelete_Selected = new QAction(MainWindow);
        actionDelete_Selected->setObjectName(QString::fromUtf8("actionDelete_Selected"));
        actionDelete_Selected->setIcon(icon11);
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/doc.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_All->setIcon(icon12);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon13);
        actionFind_Replace = new QAction(MainWindow);
        actionFind_Replace->setObjectName(QString::fromUtf8("actionFind_Replace"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/doc_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind_Replace->setIcon(icon14);
        actionDebuger = new QAction(MainWindow);
        actionDebuger->setObjectName(QString::fromUtf8("actionDebuger"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/warning2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebuger->setIcon(icon15);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/session_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon16);
        actionQtLuaPad = new QAction(MainWindow);
        actionQtLuaPad->setObjectName(QString::fromUtf8("actionQtLuaPad"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQtLuaPad->setIcon(icon17);
        actionOtland = new QAction(MainWindow);
        actionOtland->setObjectName(QString::fromUtf8("actionOtland"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOtland->setIcon(icon18);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuDelete = new QMenu(menuEdit);
        menuDelete->setObjectName(QString::fromUtf8("menuDelete"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
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
        menuEdit->addAction(actionFind_Replace);
        menuDelete->addAction(actionDelete_Line);
        menuDelete->addAction(actionDelete_Selected);
        menuAbout->addAction(actionQtLuaPad);
        menuAbout->addAction(actionOtland);
        menuTools->addAction(actionDebuger);
        menuTools->addAction(actionOptions);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionDelete_Line->setText(QApplication::translate("MainWindow", "Delete Line", 0, QApplication::UnicodeUTF8));
        actionDelete_Selected->setText(QApplication::translate("MainWindow", "Delete Selected", 0, QApplication::UnicodeUTF8));
        actionSelect_All->setText(QApplication::translate("MainWindow", "Select All", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        actionFind_Replace->setText(QApplication::translate("MainWindow", "Find & Replace", 0, QApplication::UnicodeUTF8));
        actionDebuger->setText(QApplication::translate("MainWindow", "Debuger", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        actionQtLuaPad->setText(QApplication::translate("MainWindow", "About QtLuaPad", 0, QApplication::UnicodeUTF8));
        actionOtland->setText(QApplication::translate("MainWindow", "Otland", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuDelete->setTitle(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
