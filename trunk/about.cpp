#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
}

About::~About()
{
    delete ui;
}

void About::on_closeWindow_clicked()
{
    this->close();
}
