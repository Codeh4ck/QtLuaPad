/********************************************************************************
** Form generated from reading UI file 'questcreator.ui'
**
** Created: Thu 16. Dec 22:33:47 2010
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
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestCreator
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *questName;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QuestCreator)
    {
        if (QuestCreator->objectName().isEmpty())
            QuestCreator->setObjectName(QString::fromUtf8("QuestCreator"));
        QuestCreator->resize(417, 373);
        centralwidget = new QWidget(QuestCreator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(14, 10, 67, 13));
        questName = new QLineEdit(centralwidget);
        questName->setObjectName(QString::fromUtf8("questName"));
        questName->setGeometry(QRect(87, 8, 121, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(14, 40, 46, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 40, 46, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 40, 61, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(221, 10, 91, 16));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(320, 8, 71, 22));
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(73, 35, 71, 22));
        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(209, 35, 71, 22));
        spinBox_4 = new QSpinBox(centralwidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(339, 37, 71, 22));
        QuestCreator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QuestCreator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 417, 21));
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
        label->setText(QApplication::translate("QuestCreator", "Quest Name:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        questName->setStatusTip(QApplication::translate("QuestCreator", "Enter the name of the quest here.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("QuestCreator", "Action Id:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QuestCreator", "Item Id:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QuestCreator", "Unique Id:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QuestCreator", "Quest Storage Id:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QuestCreator: public Ui_QuestCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTCREATOR_H
