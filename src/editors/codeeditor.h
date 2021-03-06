#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include "editors/fileeditor.h"
#include <QPlainTextEdit>
#include <QSyntaxHighlighter>

class CodeTextEdit;

class CodeContainer : public QWidget
{
public:
    CodeContainer(CodeTextEdit *editor);

    CodeTextEdit *parent() const;
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_width;
    int m_padding;
    int m_currentLine;
};

class CodeTextEdit : public QPlainTextEdit
{
    Q_OBJECT
    friend CodeContainer;

public:
    CodeTextEdit(QWidget *parent = nullptr);

signals:
    void resized();

protected:
    void resizeEvent(QResizeEvent *event) override;
};

class CodeEditor : public FileEditor
{
public:
    CodeEditor(const ResourceModelIndex &index, QWidget *parent = nullptr);

    bool load() override;
    bool save(const QString &as = QString()) override;

    static QStringList supportedFormats();

private:
    QFile *file;
    CodeTextEdit *editor;
    QSyntaxHighlighter *syntax;
};

#endif // CODEEDITOR_H
