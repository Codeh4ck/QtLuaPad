#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    this->setWindowModality(Qt::WindowModal);
}

Options::~Options()
{
    delete ui;
}
