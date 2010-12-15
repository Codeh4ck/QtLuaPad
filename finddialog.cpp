#include "finddialog.h"
#include "ui_finddialog.h"
#include "mainwindow.h"
#include "luaeditor.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->rdDown->setChecked(true);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_pushButton_clicked()
{
    LuaEditor *editor = qobject_cast<LuaEditor*>(MainWindow::getInstance()->mdi
                                                 ->activeSubWindow()
                                                 ->widget());
    if(editor)
    {
        editor->findFirst(ui->txtFind->text(), false, ui->cbCaseSensitive->isChecked(),
                          ui->cbWholeWords->isChecked(), true, ui->rdDown->isChecked());
    }
}
