#include "luaeditor.h"
#include <QString>
#include "Qsci/qsciapis.h"
#include "definitions.h"

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

LuaEditor::LuaEditor()
{
    initLexer();

    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    int tabWidth = settings.value("tabwidth", 4).toInt();
    bool folding = settings.value("folding", true).toBool();
    bool wrap = settings.value("wrap", false).toBool();
    bool braceMatch = settings.value("bracematch", true).toBool();
    settings.endGroup();

    this->setLexer(lexer);
    this->setUtf8(true);
    this->setMarginLineNumbers(1, true);
    this->setMarginWidth(1, 35);
    this->setTabIndents(true);
    this->setIndentationGuides(true);
    this->setIndentationsUseTabs(true);
    this->setAutoIndent(true);
    this->setTabWidth(tabWidth);
    (folding)? this->setFolding(QsciScintilla::BoxedTreeFoldStyle) :
            this->setFolding(QsciScintilla::NoFoldStyle);
    (braceMatch)? this->setBraceMatching(QsciScintilla::StrictBraceMatch) :
            this->setBraceMatching(QsciScintilla::NoBraceMatch);
    (wrap)? this->setWrapMode(QsciScintilla::WrapWord) :
            this->setWrapMode(QsciScintilla::WrapNone);
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

    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    bool autoComp = settings.value("autocompletion").toBool();
    QString funcFile = settings.value("funcfile").toString().toLatin1();
    settings.endGroup();

    if(autoComp)
    {
        setAutoCompletionSource(QsciScintilla::AcsAll);
        setAutoCompletionCaseSensitivity(false);
        setAutoCompletionFillupsEnabled(true);
        setAutoCompletionThreshold(2);
        setAutoCompletionShowSingle(true);

        QsciAPIs *apis = new QsciAPIs(lexer);
        xmlDocPtr doc = xmlParseFile(funcFile.toLatin1());
        if(!doc)
        {
            QMessageBox::critical(NULL, "Unable to load keywords!",
                                  tr("Could not load keywords file. No such file or directory."),
                                  QMessageBox::Ok, QMessageBox::NoButton);
            return;
        }

        xmlNodePtr root = xmlDocGetRootElement(doc);
        if (xmlStrcmp(root->name, (const xmlChar*)"functions"))
        {
            QMessageBox::critical(NULL, "Error", tr("Malformed functions file."));
            return;
        }
        for (xmlNodePtr p = root->children; p; p = p->next)
        {
            if(p->type != XML_ELEMENT_NODE)
                continue;

            if(xmlStrcmp(p->name, (const xmlChar*)"function"))
                continue;

            QString func = QString((const char*)p->children->content);
            apis->add(func);
        }
        apis->prepare();
        lexer->setAPIs(apis);
    }
}

void LuaEditor::newFile()
{
    static int sequence = 1;
    isUntitled = true;
    currentFile = tr("newScript%1.lua").arg(sequence++);
    setWindowTitle(tr("%1[*]").arg(currentFile));
    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    QString programmer = settings.value("programmer").toString().toLatin1();
    settings.endGroup();
    setText(tr("-- Created using QtLuaPad on %1\n-- Written by: %2.\n\nfunction onUse(cid, item, frompos, item2, topos)\n\treturn TRUE\nend").arg(QDate::currentDate().toString(), programmer));
    this->setModified(false);
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
    setWindowTitle(tr("%1 - %2[*]").arg(APPNAME, getCurrentFile()));
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
    QString file = QFileDialog::getSaveFileName(this, "Save As...", "", "Lua Scripts (*.lua)");

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

QMessageBox::StandardButton LuaEditor::askToSave()
{
    if(this->isModified())
    {
        QMessageBox::StandardButton ret =
                QMessageBox::warning(0, "Please confirm!",
                tr("Your script with name %1 has been modified\nWould you like to save the changes you've made?").arg(currentFile),
                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        return ret;
    }
    return QMessageBox::NoButton;
}

void LuaEditor::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton ret = askToSave();
    if(ret == QMessageBox::Save)
    {
        save();
        event->accept();
    } else if(ret == QMessageBox::Discard || QMessageBox::NoButton) {
        this->close();
    } else if(ret == QMessageBox::Cancel) {
        event->ignore();
    }
}

void LuaEditor::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Space:
            if (event->modifiers() & Qt::ControlModifier) {
                this->autoCompleteFromAPIs();
            } else {
                QsciScintilla::keyPressEvent(event);
            }
        break;
        case Qt::Key_Return:
            if (event->modifiers() & Qt::ControlModifier) {
                this->autoCompleteFromDocument();
            } else {
                QsciScintilla::keyPressEvent(event);
            }
        break;
        default:
            QsciScintilla::keyPressEvent(event);
    }
}
