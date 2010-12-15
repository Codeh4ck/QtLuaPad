/********************************************************************************
** Form generated from reading UI file 'questcreator.ui'
**
** Created: Fri 5. Nov 20:39:48 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTCREATOR_H
#define UI_QUESTCREATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestCreator
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QuestCreator)
    {
        if (QuestCreator->objectName().isEmpty())
            QuestCreator->setObjectName(QString::fromUtf8("QuestCreator"));
        QuestCreator->resize(279, 234);
        centralwidget = new QWidget(QuestCreator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QuestCreator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QuestCreator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 279, 21));
        QuestCreator->setMenuBar(menubar);
        statusbar = new QStatusBar(QuestCreator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QuestCreator->setStatusBar(statusbar);

        retranslateUi(QuestCreator);

        QMetaObject::connectSlotsByName(QuestCreator);
    } // setupUi

    void retranslateUi(QMainWindow *QuestCreator)
    {
        QuestCreator->setWindowTitle(QApplication::translate("QuestCreator", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QuestCreator: public Ui_QuestCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTCREATOR_H
