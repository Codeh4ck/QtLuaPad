#include "questcreator.h"
#include "ui_questcreator.h"
#include "luaeditor.h"

QuestCreator::QuestCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuestCreator)
{
    ui->setupUi(this);
}

QuestCreator::~QuestCreator()
{
    delete ui;
}
