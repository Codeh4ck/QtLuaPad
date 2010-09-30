#include "options.h"
#include "ui_options.h"
#include "definitions.h"
#include <QtGui>

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    this->setWindowModality(Qt::WindowModal);
    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    int view = settings.value("mdiview").toInt();
    ui->programmer->setText(settings.value("programmer").toString().toLatin1());
    ui->cbWrap->setChecked(settings.value("wrap").toBool());
    ui->cbCodeFolding->setChecked(settings.value("folding").toBool());
    ui->cbBraceMatch->setChecked(settings.value("bracematch").toBool());
    ui->spinTab->setValue(settings.value("tabwidth").toInt());
    ui->comboStyle->setCurrentIndex(ui->comboStyle->findText(
            settings.value("style").toString().toLatin1(),
            Qt::MatchExactly | Qt::MatchCaseSensitive));
    (view == 1) ? ui->rdTabbedView->setChecked(true) : ui->rdWindowedView->setChecked(true);
    settings.endGroup();
}

Options::~Options()
{
    delete ui;
}

void Options::on_pushButton_clicked()
{
    int view = 0;
    if(ui->rdTabbedView->isChecked()) {
        view = 1;
    } else if(ui->rdWindowedView->isChecked()) {
        view = 2;
    }

    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    settings.setValue("mdiview", view);
    settings.setValue("programmer", ui->programmer->text());
    settings.setValue("wrap", ui->cbWrap->isChecked());
    settings.setValue("folding", ui->cbCodeFolding->isChecked());
    settings.setValue("bracematch", ui->cbBraceMatch->isChecked());
    settings.setValue("tabwidth", ui->spinTab->value());
    settings.setValue("style", ui->comboStyle->currentText());
    settings.endGroup();
    QMessageBox::warning(0, "Attention!", tr("In order for your changes to take a proper effect, "
                                             "you must restart QtLuaPad."),
                         QMessageBox::Ok, QMessageBox::NoButton);

    this->close();
}

void Options::on_pushButton_2_clicked()
{
    this->close();
}

void Options::on_comboStyle_currentIndexChanged(QString )
{
    QApplication::setStyle(QStyleFactory::create(ui->comboStyle->currentText()));
    QApplication::setPalette(QApplication::style()->standardPalette());
}
