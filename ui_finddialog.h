/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created: Fri 24. Dec 03:25:24 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QLineEdit *txtFind;
    QRadioButton *rdDown;
    QRadioButton *rdUp;
    QFrame *line;
    QCheckBox *cbCaseSensitive;
    QLabel *label;
    QCheckBox *cbWholeWords;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QCheckBox *replace;
    QPushButton *goReplace;
    QPushButton *findNext;
    QPushButton *pushButton;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->setWindowModality(Qt::WindowModal);
        FindDialog->resize(346, 112);
        txtFind = new QLineEdit(FindDialog);
        txtFind->setObjectName(QString::fromUtf8("txtFind"));
        txtFind->setGeometry(QRect(80, 6, 141, 20));
        rdDown = new QRadioButton(FindDialog);
        rdDown->setObjectName(QString::fromUtf8("rdDown"));
        rdDown->setGeometry(QRect(10, 36, 89, 17));
        rdUp = new QRadioButton(FindDialog);
        rdUp->setObjectName(QString::fromUtf8("rdUp"));
        rdUp->setGeometry(QRect(10, 57, 82, 17));
        line = new QFrame(FindDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(93, 31, 41, 51));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        cbCaseSensitive = new QCheckBox(FindDialog);
        cbCaseSensitive->setObjectName(QString::fromUtf8("cbCaseSensitive"));
        cbCaseSensitive->setGeometry(QRect(123, 36, 96, 17));
        label = new QLabel(FindDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 7, 61, 16));
        cbWholeWords = new QCheckBox(FindDialog);
        cbWholeWords->setObjectName(QString::fromUtf8("cbWholeWords"));
        cbWholeWords->setGeometry(QRect(123, 57, 91, 17));
        lineEdit = new QLineEdit(FindDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(111, 86, 161, 20));
        label_2 = new QLabel(FindDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(80, 88, 31, 16));
        replace = new QCheckBox(FindDialog);
        replace->setObjectName(QString::fromUtf8("replace"));
        replace->setEnabled(false);
        replace->setGeometry(QRect(9, 87, 63, 17));
        goReplace = new QPushButton(FindDialog);
        goReplace->setObjectName(QString::fromUtf8("goReplace"));
        goReplace->setEnabled(false);
        goReplace->setGeometry(QRect(280, 84, 60, 23));
        findNext = new QPushButton(FindDialog);
        findNext->setObjectName(QString::fromUtf8("findNext"));
        findNext->setGeometry(QRect(230, 10, 111, 23));
        pushButton = new QPushButton(FindDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 44, 111, 23));

        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QApplication::translate("FindDialog", "Find Text", 0, QApplication::UnicodeUTF8));
        rdDown->setText(QApplication::translate("FindDialog", "Search Down", 0, QApplication::UnicodeUTF8));
        rdUp->setText(QApplication::translate("FindDialog", "Search Up", 0, QApplication::UnicodeUTF8));
        cbCaseSensitive->setText(QApplication::translate("FindDialog", "Case Sensitive", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FindDialog", "Text to Find:", 0, QApplication::UnicodeUTF8));
        cbWholeWords->setText(QApplication::translate("FindDialog", "Whole Words", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FindDialog", "With:", 0, QApplication::UnicodeUTF8));
        replace->setText(QApplication::translate("FindDialog", "Replace?", 0, QApplication::UnicodeUTF8));
        goReplace->setText(QApplication::translate("FindDialog", "Replace", 0, QApplication::UnicodeUTF8));
        findNext->setText(QApplication::translate("FindDialog", "Find Next", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FindDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
