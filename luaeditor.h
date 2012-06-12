#ifndef LUAEDITOR_H
#define LUAEDITOR_H

#define QSCINTILLA_DLL
#include <QtGui>
#include <QCompleter>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerlua.h>

class MainWindow;

class LuaEditor : public QsciScintilla
{
    Q_OBJECT
public:
    LuaEditor();

    static LuaEditor *getInstance()
    {
        static LuaEditor e;
        return &e;
    }

    void initLexer();
    QsciLexerLua *getLexer() { return lexer; }
    void newFile();
    bool openFile(const QString &file);
    bool save();
    bool saveAs();
    bool saveFile(const QString &name);
    QString currentFileP() { return currentFile; }
    QMessageBox::StandardButton askToSave();
    bool loadWordsFromFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void setDocumentModified();
private:
    QsciLexerLua *lexer;
    bool isUntitled;
    QString currentFile;
    void setCurrentFile(const QString &file);
    QString getStrippedName(const QString &fullPath);
    QString getCurrentFile();
    QStringList completerEntries;
};

#endif // LUAEDITOR_H
