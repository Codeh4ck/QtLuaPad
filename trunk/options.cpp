#include "options.h"
#include "ui_options.h"
#include "highlighter.h"
#include <QProcess>
#include <QFileDialog>
#include <QSettings>
#include <QMessageBox>
//#include <QRegExp>
//#include <QRegExpValidator>

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
//    QRegExp reg("[0-9]{0,2}");
//    ui->tabEdit->setValidator(new QRegExpValidator(reg, this));
    setFixedSize(width(), height());
    loadOptions();
}

Options::~Options()
{
    delete ui;
}

void Options::setOptions()
{
    QSettings settings("Delirium", "QtLuaPad");
    settings.beginGroup("QtLuaPad_Opt");
    settings.setValue("wordWrap", ui->wordWrapCheck->isChecked());
    settings.setValue("progNick", ui->progNickLine->text());
//  settings.setValue("tabs", ui->tabEdit->text().toInt());
    settings.endGroup();
}

void Options::loadOptions()
{
    QSettings settings("Delirium", "QtLuaPad");
    settings.beginGroup("QtLuaPad_Opt");
    ui->progNickLine->setText(settings.value("progNick").toString().toLatin1());
    ui->wordWrapCheck->setChecked(settings.value("wordWrap").toBool());
    settings.endGroup();
}


void Options::on_doneBtn_clicked()
{
    setOptions();
//    QMessageBox::StandardButton ret;
//    ret = QMessageBox::information(this, "Information!",
//                             "In order for your new options to take effect, you must restart QtLuaPad.\nWould you like to do that now?",
//                             QMessageBox::Yes | QMessageBox::No, QMessageBox::NoButton);
//    if(ret == QMessageBox::Yes)
//    {
//        QProcess::startDetached(QApplication::applicationFilePath());
//        QApplication::closeAllWindows();
//    }
//    else
        close();
}
