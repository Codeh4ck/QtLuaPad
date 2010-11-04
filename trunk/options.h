#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui {
    class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
   explicit Options(QWidget *parent = 0);
    ~Options();

private:
    Ui::Options *ui;

private slots:
    void on_browseBtn_clicked();
    void on_comboStyle_currentIndexChanged(QString );
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // OPTIONS_H
