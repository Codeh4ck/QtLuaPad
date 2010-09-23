#include "luaeditor.h"
#include <QString>

LuaEditor::LuaEditor()
{
    initLexer();
    this->setLexer(lexer);
    this->setUtf8(true);
    this->setMarginLineNumbers(1, true);
    this->setMarginWidth(1, 35);
    this->setTabIndents(true);
    this->setIndentationGuides(true);
    this->setIndentationsUseTabs(true);
    this->setAutoIndent(true);
    this->setTabWidth(4);
    this->setFolding(QsciScintilla::BoxedTreeFoldStyle);
    newFile();
}

void LuaEditor::initLexer()
{
    lexer = new QsciLexerLua;
    lexer->setFoldCompact(false);
    lexer->setColor(QColor(128, 128, 255), 5);
    lexer->setColor(QColor(0, 220, 0), 1);
    lexer->setColor(QColor(0, 220, 0), 2);
    lexer->setColor(QColor(Qt::red), 6);
    lexer->setColor(QColor(Qt::red), 8);
    lexer->setColor(QColor(255, 128, 0), 13);
    lexer->setColor(QColor(51, 102, 255), 15);
    lexer->setColor(QColor(72, 61, 139), 10);
    lexer->setFont(QFont("Courier New", 11, QFont::Bold));
}

void LuaEditor::newFile()
{
    isUntitled = true;
    currentFile = "newScript.lua";
    setWindowTitle("QtLuaPad[*]");
    setText(tr("-- Created using QtLuaPad on %1\n\nfunction onUse(cid, item, frompos, item2, topos)\n\treturn TRUE\nend").arg(QDate::currentDate().toString()));
    connect(this, SIGNAL(textChanged()), this, SLOT(setDocumentModified()));
}

bool LuaEditor::openFile(const QString &file)
{
    QFile f(file);
    if(!f.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Unable to open file!",
                             tr("Could not read file %1.\nError string: %2")
                             .arg(currentFile, f.errorString()), QMessageBox::Ok,
                             QMessageBox::NoButton);
        return false;
    }
    QTextStream stream(&f);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    this->setText(stream.readAll());
    QApplication::restoreOverrideCursor();
    setCurrentFile(file);
    connect(this, SIGNAL(textChanged()), this, SLOT(setDocumentModified()));
    return true;
}

void LuaEditor::setCurrentFile(const QString &file)
{
    currentFile = QFileInfo(file).canonicalFilePath();
    isUntitled = false;
    this->setModified(false);
    this->setWindowModified(false);
    setWindowTitle(tr("QtLuaPad - %1[*]").arg(getCurrentFile()));
}

QString LuaEditor::getStrippedName(const QString &fullPath)
{
    return QFileInfo(fullPath).fileName();
}

QString LuaEditor::getCurrentFile()
{
    return getStrippedName(currentFile);
}

bool LuaEditor::saveAs()
{
    QString file = QFileDialog::getSaveFileName(this, "Save As...");

    if(file.isEmpty())
        return false;

    return saveFile(file);

}

bool LuaEditor::save()
{
    if(this->isUntitled)
        return saveAs();
    else
        return saveFile(currentFile);
}

bool LuaEditor::saveFile(const QString &name)
{
    QFile file(name);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Unable to save file!",
                                  tr("Could not save file %1.\nError string: %2")
                                  .arg(name, file.errorString()), QMessageBox::Ok,
                                  QMessageBox::NoButton);
        return false;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    QTextStream stream(&file);
    stream << this->text();
    setCurrentFile(name);
    QApplication::restoreOverrideCursor();

    return true;
}

void LuaEditor::setDocumentModified()
{
    this->setWindowModified(this->isModified());
}
