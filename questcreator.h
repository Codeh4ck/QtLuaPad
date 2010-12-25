#ifndef QUESTCREATOR_H
#define QUESTCREATOR_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
	class QuestCreator;
}

class QuestCreator : public QDialog
{
	Q_OBJECT

	public:
		explicit QuestCreator(QWidget *parent = 0);
		~QuestCreator();

	private:
		Ui::QuestCreator *ui;

	private slots:
		void onBrowseClicked();
		void onItemsContainerClicked();
		void onAddItemClicked();
		void onRemoveItemClicked();
		void onClearListClicked();
		void onSaveQuestClicked();
		void onCloseWindowClicked();
};

#endif // QUESTCREATOR_H
