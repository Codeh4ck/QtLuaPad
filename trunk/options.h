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

    static Options *getInstance()
    {
        static Options opt;
        return &opt;
    }

    void loadOptions();

private:
    Ui::Options *ui;
    void setOptions();

private slots:
    void on_doneBtn_clicked();
};

#endif // OPTIONS_H
