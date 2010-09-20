#include "mdichild.h"
#include "mainwindow.h"
#include <QtGui>
#include <QFile>

MdiChild::MdiChild()
{
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    updateLineNumberAreaWidth(0);

    highlightCurrentLine();
    highlighter = new Highlighter(this->document());

    setAttribute(Qt::WA_DeleteOnClose);

    QSettings settings("Delirium", "QtLuaPad");
    settings.beginGroup("QtLuaPad_Opt");
    progName = settings.value("progName").toString().toLatin1();
    wordWrap = settings.value("wordWrap").toBool();
    wordWrap ? this->setWordWrapMode(QTextOption::WordWrap) :
            this->setWordWrapMode(QTextOption::NoWrap);
    settings.endGroup();
    setFont(QFont("Courier New", 10, QFont::Normal));
    newFile();
    statusBar = new QStatusBar(this);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}

void MdiChild::newFile()
{
    static int sequence = 1;

    isUntitled = true;
    curFile = tr("script%1.lua").arg(sequence++);
    setWindowTitle(curFile + "[*]");
    setPlainText(tr("-- Created using QtLuaPad on %1.\n-- Script written by: %2.")
                 .arg(QDate::currentDate().toString(), progName));
    document()->setModified(false);
    connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentModified()));
}

void MdiChild::documentModified()
{
    setWindowModified(document()->isModified());
}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, "MdiChild::loadFile()",
                             tr("Could not load script %1:\n%2.").arg(fileName, file.errorString()),
                             QMessageBox::Ok, QMessageBox::NoButton);
        return false;
    } else {

        QTextStream stream(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        setPlainText(stream.readAll());
        delete highlighter;
        highlighter = new Highlighter(document());
        QApplication::restoreOverrideCursor();
        setCurrentFile(fileName);
        connect(document(), SIGNAL(contentsChanged()),
                this, SLOT(documentModified()));
        return true;
    }
}

bool MdiChild::save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As..."), curFile);
    if(fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, tr("MdiChild::saveFile()"),
                             tr("Cannot save script %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream stream(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    stream << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return strippedName(curFile);
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool MdiChild::maybeSave()
{
    if (document()->isModified()) {
        QMessageBox::StandardButton ret;
        QString name = userFriendlyCurrentFile() == "" ? "Your new script" : "'" + userFriendlyCurrentFile() + "'";
        ret = QMessageBox::warning(this, tr("Attention!"),
                     tr("%1 has been modified.\n"
                        "Would you like to save your changes?")
                     .arg(name),
                     QMessageBox::Save | QMessageBox::Discard
                     | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

int MdiChild::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

void MdiChild::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void MdiChild::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void MdiChild::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void MdiChild::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::blue).lighter(193);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}


void MdiChild::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width() - 1, fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
