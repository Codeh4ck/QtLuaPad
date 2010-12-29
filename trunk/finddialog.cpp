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
    ui->groupBox_2->setChecked(false);
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

    bool forward = true;
    if(ui->rdDown->isChecked())
        forward = true;
    else if(ui->rdUp->isChecked())
        forward = false;

    if(oldText != "")
    {
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
    } else {
        QMessageBox::warning(0, "Error!", "You may not search for an empty string!");
    }

    if(notFound) {
        QMessageBox::warning(0, "Search failed!",
                         tr("Could not find \"%1\" within/further this context.")
                         .arg(ui->txtFind->text()));
    }
}

void FindDialog::on_pushButton_clicked()
{
    this->close();
}

void FindDialog::on_goReplace_clicked()
{
    if(ui->txtReplace->text() != "")
    {
        if(d.editor->findFirst(ui->txtReplace->text(), false,
                            ui->cbCaseSensitive->isChecked(), ui->cbWholeWords->isChecked(),
                            true))
        {
            d.editor->replace(ui->txtReplaceWith->text());
        }
    } else {
        QMessageBox::warning(0, "Error!", "You may not replace an empty string!");
    }
}

void FindDialog::on_groupBox_2_clicked()
{
    bool enable;
    ui->groupBox_2->isChecked()? enable = true : enable = false;
    ui->txtReplace->setEnabled(enable);
    ui->txtReplaceWith->setEnabled(enable);
    ui->label_3->setEnabled(enable);
    ui->label_2->setEnabled(enable);
    ui->goReplace->setEnabled(enable);
    ui->replaceAll->setEnabled(enable);
}

void FindDialog::on_replaceAll_clicked()
{
    int count = 0;
    if(ui->txtReplace->text() != "")
    {
        if(d.editor->findFirst(ui->txtReplace->text(), false,
                            ui->cbCaseSensitive->isChecked(), ui->cbWholeWords->isChecked(),
                            true, 0, 0))
        {
            d.editor->replace(ui->txtReplaceWith->text());
            count++;
            while(d.editor->findFirst(ui->txtReplace->text(), false,
                                      ui->cbCaseSensitive->isChecked(), ui->cbWholeWords->isChecked(),
                                      true))
            {
               d.editor->replace(ui->txtReplaceWith->text());
               count++;
            }
        } else {
            QMessageBox::warning(0, "Search failed!", "Could not find search string within the context.");
        }
        QMessageBox::information(0, "Information!", tr("Total amount of replacements: %1.").arg
                                 (QString().setNum(count)));
    } else {
        QMessageBox::warning(0, "Error!", "You may not replace an empty string!");
    }
}
