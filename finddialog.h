#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class LuaEditor;

namespace Ui {
    class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();
    void setEditor(LuaEditor*);
    LuaEditor* editor() const;

private:
    Ui::FindDialog *ui;
    bool foundFirst;
    QString oldText;

protected:
    struct FindDialog_p
    {
        LuaEditor* editor;
    } d;

private slots:
    void on_pushButton_clicked();
    void on_findNext_clicked();
};

#endif // FINDDIALOG_H
