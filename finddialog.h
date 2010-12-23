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

private slots:
    void on_pushButton_clicked();

protected:
    struct FindDialog_p
    {
        LuaEditor* editor;
    } d;
};

#endif // FINDDIALOG_H
