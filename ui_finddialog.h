/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created: Sun Jun 10 05:31:38 2012
**      by: Qt User Interface Compiler version 4.7.3
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label;
    QRadioButton *rdUp;
    QCheckBox *cbWholeWords;
    QFrame *line;
    QLineEdit *txtFind;
    QRadioButton *rdDown;
    QCheckBox *cbCaseSensitive;
    QPushButton *findNext;
    QGroupBox *groupBox_2;
    QPushButton *replaceAll;
    QPushButton *goReplace;
    QLabel *label_2;
    QLineEdit *txtReplaceWith;
    QLabel *label_3;
    QLineEdit *txtReplace;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->setWindowModality(Qt::WindowModal);
        FindDialog->resize(375, 206);
        groupBox = new QGroupBox(FindDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(8, 5, 358, 101));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 60, 111, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 23, 61, 16));
        rdUp = new QRadioButton(groupBox);
        rdUp->setObjectName(QString::fromUtf8("rdUp"));
        rdUp->setGeometry(QRect(10, 73, 82, 17));
        cbWholeWords = new QCheckBox(groupBox);
        cbWholeWords->setObjectName(QString::fromUtf8("cbWholeWords"));
        cbWholeWords->setGeometry(QRect(123, 73, 91, 17));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(93, 47, 41, 51));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        txtFind = new QLineEdit(groupBox);
        txtFind->setObjectName(QString::fromUtf8("txtFind"));
        txtFind->setGeometry(QRect(80, 22, 141, 20));
        rdDown = new QRadioButton(groupBox);
        rdDown->setObjectName(QString::fromUtf8("rdDown"));
        rdDown->setGeometry(QRect(10, 52, 89, 17));
        cbCaseSensitive = new QCheckBox(groupBox);
        cbCaseSensitive->setObjectName(QString::fromUtf8("cbCaseSensitive"));
        cbCaseSensitive->setGeometry(QRect(123, 52, 96, 17));
        findNext = new QPushButton(groupBox);
        findNext->setObjectName(QString::fromUtf8("findNext"));
        findNext->setGeometry(QRect(240, 26, 111, 23));
        groupBox_2 = new QGroupBox(FindDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(8, 120, 358, 80));
        groupBox_2->setCheckable(true);
        replaceAll = new QPushButton(groupBox_2);
        replaceAll->setObjectName(QString::fromUtf8("replaceAll"));
        replaceAll->setEnabled(false);
        replaceAll->setGeometry(QRect(280, 50, 71, 23));
        goReplace = new QPushButton(groupBox_2);
        goReplace->setObjectName(QString::fromUtf8("goReplace"));
        goReplace->setEnabled(false);
        goReplace->setGeometry(QRect(210, 50, 60, 23));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(10, 50, 32, 16));
        txtReplaceWith = new QLineEdit(groupBox_2);
        txtReplaceWith->setObjectName(QString::fromUtf8("txtReplaceWith"));
        txtReplaceWith->setEnabled(false);
        txtReplaceWith->setGeometry(QRect(40, 50, 161, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);
        label_3->setGeometry(QRect(10, 20, 46, 13));
        txtReplace = new QLineEdit(groupBox_2);
        txtReplace->setObjectName(QString::fromUtf8("txtReplace"));
        txtReplace->setEnabled(false);
        txtReplace->setGeometry(QRect(59, 18, 291, 20));

        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QApplication::translate("FindDialog", "Find Text", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FindDialog", "Text Search", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FindDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FindDialog", "Text to Find:", 0, QApplication::UnicodeUTF8));
        rdUp->setText(QApplication::translate("FindDialog", "Search Up", 0, QApplication::UnicodeUTF8));
        cbWholeWords->setText(QApplication::translate("FindDialog", "Whole Words", 0, QApplication::UnicodeUTF8));
        rdDown->setText(QApplication::translate("FindDialog", "Search Down", 0, QApplication::UnicodeUTF8));
        cbCaseSensitive->setText(QApplication::translate("FindDialog", "Case Sensitive", 0, QApplication::UnicodeUTF8));
        findNext->setText(QApplication::translate("FindDialog", "Find Next", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("FindDialog", "Search && Replace", 0, QApplication::UnicodeUTF8));
        replaceAll->setText(QApplication::translate("FindDialog", "Replace All", 0, QApplication::UnicodeUTF8));
        goReplace->setText(QApplication::translate("FindDialog", "Replace", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FindDialog", "With:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FindDialog", "Replace:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
