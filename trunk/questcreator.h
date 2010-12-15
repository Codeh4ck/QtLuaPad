#ifndef QUESTCREATOR_H
#define QUESTCREATOR_H

#include <QMainWindow>

namespace Ui {
    class QuestCreator;
}

class QuestCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuestCreator(QWidget *parent = 0);
    ~QuestCreator();

private:
    Ui::QuestCreator *ui;
};

#endif // QUESTCREATOR_H
