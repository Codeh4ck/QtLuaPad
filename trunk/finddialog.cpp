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
    foundFirst = false;
    oldText = "";
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

void FindDialog::on_findNext_clicked()
{
    if (!d.editor)
        return;

    oldText = ui->txtFind->text();
    QString newText = "";
    bool notFound = true;

    bool forward;
    if(ui->rdDown->isChecked())
        forward = true;
    else if(ui->rdUp->isChecked())
        forward = false;

    if(oldText == ui->txtFind->text() && !foundFirst)
    {
        if(d.editor->findFirst(oldText, false,
                            ui->cbCaseSensitive->isChecked(), ui->cbWholeWords->isChecked(),
                            forward))
        {
            foundFirst = true;
            notFound = false;
        }
    } else if(oldText != newText && foundFirst) {

        oldText = ui->txtFind->text();
        newText = oldText;
        foundFirst = true;

        if(d.editor->findFirst(ui->txtFind->text(), false,
                                ui->cbCaseSensitive->isChecked(), ui->cbWholeWords->isChecked(),
                                forward))
        {
            notFound = false;
        }

    } else if(oldText == ui->txtFind->text() && foundFirst) {
        d.editor->findNext();
    }

    if(notFound) {
        QMessageBox::warning(0, "Could not find text!",
                         tr("Could not find \"%1\" within/further this context.")
                         .arg(ui->txtFind->text()));
    }
}

void FindDialog::on_pushButton_clicked()
{
    this->close();
}
