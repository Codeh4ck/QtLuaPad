#include "highlighter.h"
#include "mainwindow.h"
#include <QtGui>

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;

    keywordPatterns = getKeywords();

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);

    rule.pattern = QRegExp("\\bdo[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);
    rule.pattern = QRegExp("\\bget[A-Za-z]+\\b");
    highlightingRules.append(rule);
    rule.pattern = QRegExp("\\bset[A-Za-z]+\\b");
    highlightingRules.append(rule);
    rule.pattern = QRegExp("\\bis[A-Za-z]+\\b");
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegExp("--[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::red);
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);
    rule.pattern = QRegExp("\'.*\'");
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("--\\[\\[");
    commentEndExpression = QRegExp(".\\]\\]");



}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {

        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

QStringList Highlighter::getKeywords()
{
    QFile file(QApplication::applicationDirPath() + "/keywords.txt");
    QStringList keywords;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(MainWindow::getInstance(), "Error loading keywords!",
                             tr("Could not load keywords file.\nError string: %1.").arg(file.errorString()),
                             QMessageBox::Ok, QMessageBox::NoButton);
    } else {
        QTextStream in(&file);
        QString line = in.readLine();
        while(!line.isNull())
        {
            keywords << tr("\\b%1\\b").arg(line);
            line = in.readLine();
        }
    }
    return keywords;
}
