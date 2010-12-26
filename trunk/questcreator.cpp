#include "questcreator.h"
#include "ui_questcreator.h"

QuestCreator::QuestCreator(QWidget *parent) : QDialog(parent), ui(new Ui::QuestCreator)
{
	ui->setupUi(this);

	// Simple hack to make QDialog not resizeable.
	setMinimumSize(521, 480);
	setMaximumSize(521, 480);

	// Another 'hack', this one is to remove system menu buttons from window title bar.
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

	// Connect controls with functions.
	connect(ui->BrowsePathButton, SIGNAL(clicked()), this, SLOT(onBrowseClicked()));
	connect(ui->ItemsInContainer, SIGNAL(clicked()), this, SLOT(onItemsContainerClicked()));
	connect(ui->ItemsAddItem, SIGNAL(clicked()), this, SLOT(onAddItemClicked()));
	connect(ui->ItemsRemoveItem, SIGNAL(clicked()), this, SLOT(onRemoveItemClicked()));
	connect(ui->ItemsClearList, SIGNAL(clicked()), this, SLOT(onClearListClicked()));
	connect(ui->SaveQuestButton, SIGNAL(clicked()), this, SLOT(onSaveQuestClicked()));
	connect(ui->CloseWindowButton, SIGNAL(clicked()), this, SLOT(onCloseWindowClicked()));
}

QuestCreator::~QuestCreator()
{
	delete ui;
}

void QuestCreator::onBrowseClicked()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if(dir != "")
		ui->SavePathEdit->setText(dir);
}

void QuestCreator::onItemsContainerClicked()
{
	ui->ContainerIDEdit->setEnabled(ui->ItemsInContainer->isChecked() ? true : false);
}

void QuestCreator::onAddItemClicked()
{
	if(ui->ItemsAddIDEdit->text() != "" && ui->ItemsAddCountEdit->text() != "")
	{
		QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->ItemsList);
		newItem->setText(0, ui->ItemsAddIDEdit->text());
		newItem->setText(1, ui->ItemsAddCountEdit->text());
	}
}

void QuestCreator::onRemoveItemClicked()
{
	delete ui->ItemsList->currentItem();
}

void QuestCreator::onClearListClicked()
{
	ui->ItemsList->clear();
}

void QuestCreator::onSaveQuestClicked()
{
	if(ui->FileNameEdit->text() == "" || ui->SavePathEdit->text() == "")
	{
		QMessageBox::critical(this, "Quest Creator", "Couldn't save quest, file name or save path is empty.");
		return;
	}

	QString result;
	QTextStream quest(&result);
	quest << "local items = {";

	for(int i = 0; i < ui->ItemsList->columnCount(); i++)
	{
		QTreeWidgetItem *item = ui->ItemsList->takeTopLevelItem(i);
		if(item != NULL)
		{
			quest << "\n\t[" << QString::number(i + 1) << "] = {" << item->text(0) << ", " << item->text(1) << "},";
			ui->ItemsList->addTopLevelItem(item); // I don't know why, but when I call takeTopLevelItem(int) function then element is being removed from list, that's why I add it back to list here.
		}
	}

	quest << "\n}";
	quest << "\n\nfunction onUse(cid, item, fromPosition, itemEx, toPosition)";
	quest << "\n\tif getCreatureStorage(cid, " << ui->StorageKeyEdit->text() << ") > -1) then";
	quest << "\n\t\tdoPlayerSendTextMessage(cid, MESSAGE_INFO_DESCR, \"" << ui->FailureMessageEdit->text() << "\")";
	quest << "\n\t\treturn true";
	quest << "\n\tend";
	quest << "\n";

	if(ui->ItemsInContainer->isChecked())
		quest << "\n\tlocal container = doPlayerAddItem(cid, " << ui->ContainerIDEdit << ", 1)";

	quest << "\n\tfor _, item in ipairs(items) do";
	if(ui->ItemsInContainer->isChecked())
		quest << "\n\t\tdoAddContainerItem(container, item[1], item[2])";
	else
		quest << "\n\t\tdoPlayerAddItem(cid, item[1], item[2])";

	quest << "\n\tend";
	quest << "\n\n\tdoPlayerSendTextMessage(cid, MESSAGE_INFO_DESCR, \"" << ui->SuccessMessageEdit->text() << "\")";
	quest << "\n\tdoCreatureSetStorage(cid, " << ui->StorageKeyEdit->text() << ", 1)";
	quest << "\n\treturn true";
	quest << "\nend";

	if(!ui->FileNameEdit->text().contains(".lua"))
		ui->FileNameEdit->setText(ui->FileNameEdit->text() + ".lua");

	QFile questFile(ui->SavePathEdit->text() + "\\" + ui->FileNameEdit->text());
	if(!questFile.exists())
	{
		if(questFile.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			questFile.write(result.toUtf8(), result.length());
			questFile.close();

			QMessageBox *message = new QMessageBox(this);
			message->setIcon(QMessageBox::Information);
			message->setText("Quest has been saved.\nFor .XML entry please press 'Show Details...'.");

			if(ui->AssignMethodCombo->currentText() == "Item ID")
				message->setDetailedText("<action itemid=\"" + QString::number(ui->ItemIDSpin->value()) + "\" event=\"script\" value=\"" + ui->FileNameEdit->text() + "\" />");
			else if(ui->AssignMethodCombo->currentText() == "Action ID")
				message->setDetailedText("<action actionid=\"" + QString::number(ui->AIDSpin->value()) + "\" event=\"script\" value=\"" + ui->FileNameEdit->text() + "\" />");
			else
				message->setDetailedText("<action uniqueid=\"" + QString::number(ui->UIDSpin->value()) + "\" event=\"script\" value=\"" + ui->FileNameEdit->text() + "\" />");
	
			message->exec();
			delete message;
		}
		else
			QMessageBox::critical(this, "Quest Creator", "Couldn't save quest, failed to open file.");
	}
	else
		QMessageBox::critical(this, "Quest Creator", "Couldn't save quest, file already exists.");
}

void QuestCreator::onCloseWindowClicked()
{
	delete this;
}
