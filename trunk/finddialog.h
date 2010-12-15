#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
    class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();

private:
    Ui::FindDialog *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // FINDDIALOG_H
