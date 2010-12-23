#include "finddialog.h"
#include "ui_finddialog.h"
#include "mainwindow.h"
#include "luaeditor.h"
#include "definitions.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->rdDown->setChecked(true);
}

void FindDialog::setEditor(LuaEditor* editor)
{
    if (d.editor != editor)
        d.editor = editor;
}

LuaEditor* FindDialog::editor() const
{
    return d.editor;
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_pushButton_clicked()
{
    if (!d.editor)
        return;

    d.editor->findFirst(ui->txtFind->text(), false,
                        ui->cbCaseSensitive->isChecked(), ui->cbWholeWords->isChecked(), true);
}
