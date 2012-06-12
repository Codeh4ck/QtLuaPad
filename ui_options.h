/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created: Sun Jun 10 05:31:38 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QRadioButton *rdTabbedView;
    QRadioButton *rdWindowedView;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_2;
    QLineEdit *programmer;
    QCheckBox *cbWrap;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_3;
    QSpinBox *spinTab;
    QFrame *line_5;
    QCheckBox *cbBraceMatch;
    QFrame *line_6;
    QCheckBox *cbCodeFolding;
    QFrame *line_7;
    QLabel *label_4;
    QComboBox *comboStyle;
    QLabel *label_5;
    QLineEdit *funcFile;
    QToolButton *browseBtn;
    QCheckBox *cbAutoComplete;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(345, 211);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/winicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Options->setWindowIcon(icon);
        pushButton = new QPushButton(Options);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 180, 75, 23));
        pushButton_2 = new QPushButton(Options);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 180, 75, 23));
        label = new QLabel(Options);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(8, 62, 81, 16));
        rdTabbedView = new QRadioButton(Options);
        rdTabbedView->setObjectName(QString::fromUtf8("rdTabbedView"));
        rdTabbedView->setGeometry(QRect(88, 52, 82, 17));
        rdWindowedView = new QRadioButton(Options);
        rdWindowedView->setObjectName(QString::fromUtf8("rdWindowedView"));
        rdWindowedView->setGeometry(QRect(88, 72, 101, 17));
        line = new QFrame(Options);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(40, 98, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Options);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(40, 42, 118, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(Options);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(8, 12, 71, 16));
        programmer = new QLineEdit(Options);
        programmer->setObjectName(QString::fromUtf8("programmer"));
        programmer->setGeometry(QRect(80, 11, 101, 20));
        cbWrap = new QCheckBox(Options);
        cbWrap->setObjectName(QString::fromUtf8("cbWrap"));
        cbWrap->setGeometry(QRect(10, 112, 141, 20));
        line_3 = new QFrame(Options);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(40, 142, 118, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Options);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(186, 12, 16, 161));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(Options);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 153, 61, 16));
        spinTab = new QSpinBox(Options);
        spinTab->setObjectName(QString::fromUtf8("spinTab"));
        spinTab->setGeometry(QRect(100, 150, 42, 22));
        spinTab->setMaximum(20);
        line_5 = new QFrame(Options);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(207, 80, 118, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        cbBraceMatch = new QCheckBox(Options);
        cbBraceMatch->setObjectName(QString::fromUtf8("cbBraceMatch"));
        cbBraceMatch->setGeometry(QRect(207, 90, 121, 17));
        line_6 = new QFrame(Options);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(210, 113, 118, 3));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        cbCodeFolding = new QCheckBox(Options);
        cbCodeFolding->setObjectName(QString::fromUtf8("cbCodeFolding"));
        cbCodeFolding->setGeometry(QRect(207, 123, 121, 17));
        line_7 = new QFrame(Options);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(207, 150, 118, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(Options);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 160, 91, 16));
        comboStyle = new QComboBox(Options);
        comboStyle->setObjectName(QString::fromUtf8("comboStyle"));
        comboStyle->setGeometry(QRect(209, 180, 121, 22));
        label_5 = new QLabel(Options);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(205, 30, 91, 16));
        funcFile = new QLineEdit(Options);
        funcFile->setObjectName(QString::fromUtf8("funcFile"));
        funcFile->setGeometry(QRect(205, 50, 105, 20));
        browseBtn = new QToolButton(Options);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));
        browseBtn->setGeometry(QRect(315, 50, 25, 19));
        cbAutoComplete = new QCheckBox(Options);
        cbAutoComplete->setObjectName(QString::fromUtf8("cbAutoComplete"));
        cbAutoComplete->setGeometry(QRect(205, 10, 139, 17));

        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Options", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Options", "Okay", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Options", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Options", "MDI View Type:", 0, QApplication::UnicodeUTF8));
        rdTabbedView->setText(QApplication::translate("Options", "Tabbed View", 0, QApplication::UnicodeUTF8));
        rdWindowedView->setText(QApplication::translate("Options", "Windowed View", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Options", "Programmer:", 0, QApplication::UnicodeUTF8));
        cbWrap->setText(QApplication::translate("Options", "Enable Word-Wrap Code", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Options", "Tab Width:", 0, QApplication::UnicodeUTF8));
        cbBraceMatch->setText(QApplication::translate("Options", "Enable Brace Match", 0, QApplication::UnicodeUTF8));
        cbCodeFolding->setText(QApplication::translate("Options", "Enable Code Folding", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Options", "Application Style:", 0, QApplication::UnicodeUTF8));
        comboStyle->clear();
        comboStyle->insertItems(0, QStringList()
         << QApplication::translate("Options", "Windows", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Options", "WindowsXP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Options", "WindowsVista", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Options", "Plastique", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Options", "Cleanlooks", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Options", "Motif", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("Options", "Functions File:", 0, QApplication::UnicodeUTF8));
        browseBtn->setText(QApplication::translate("Options", "...", 0, QApplication::UnicodeUTF8));
        cbAutoComplete->setText(QApplication::translate("Options", "Enable Auto-Completion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
