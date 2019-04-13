#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <sstream>
#include <memory>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QFileInfo>
#include <QSettings>
#include <QScrollBar>
#include "highlighter.h"
#include "sourcecode.h"

namespace Ui {
class CodeEditor;
}

class CodeEditor : public QDialog
{
    Q_OBJECT

public:
    explicit CodeEditor(const QString d, const QString windowName, QWidget *parent = nullptr);
    ~CodeEditor();
    void execute(const QString& input, const int timeOutValue);

private slots:
    void on_loaderButton_clicked();
    void on_submitCodeButton_clicked();
    void on_languageSelect_currentIndexChanged(const QString &arg1);
    void on_flagLine_editingFinished();
    void loaderOutputReceived(int ret, const QByteArray& error, const QByteArray& output);
    void outputReceived(const QByteArray& output, const int time) {outputReady(output, time);}
    void executionFailArrived(bool crashed) {executionFailed(crashed);}
private:
    Ui::CodeEditor *ui;
    SourceCode *sourcecode;
    void setLayout();
    void setSourcecode(const QString& langName);
signals:
    void outputReady(const QByteArray& output, const int time);
    void executionFailed(bool crashed);
    void loaderErrorArrived();
};

#endif // CODEEDITOR_H
