#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QDialog>
#include <sstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QFileInfo>
#include <QSettings>
#include <QScrollBar>
#include "highlighter.h"

namespace Ui {
class CodeEditor;
}

struct LanguageSettings {
    QString codeExtension;
    QStringList extensions;
    QStringList compileList;
};

class CodeEditor : public QDialog
{
    Q_OBJECT

public:
    explicit CodeEditor(const QString d, const QString windowName, QWidget *parent = 0);
    ~CodeEditor();

private slots:
    void on_compileButton_clicked();
    void on_loadCompilerButton_clicked();
    void procFinished(int, QProcess::ExitStatus);
    void procError(QProcess::ProcessError);
    void on_submitCodeButton_clicked();
    void on_languageSelect_currentIndexChanged(const QString &arg1);
    void on_flagLine_editingFinished();

private:
    Ui::CodeEditor *ui;
    const QDir codeDir;
    const QString codePath;
    QString compilerPath;
    std::string javaFilename;
    QProcess* proc;
    QMap<QString, LanguageSettings> languageSettings;
    void compileProgram();
    void initLanguages();
    void setLayout();

signals:
    void programReady(const QString& pname, const QString& lang);
};

#endif // CODEEDITOR_H
