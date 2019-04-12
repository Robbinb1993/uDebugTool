#include "sourcecode.h"
#include <QString>
#include <QProcess>
#include <QDir>
#include <QTextStream>
#include <QDebug>
SourceCode::SourceCode(QObject *parent) : QObject(parent) {
    executableDirectoryPath = QDir::currentPath() + "/executables";
    executableFilePath = executableDirectoryPath + "/a";
    executeProc = new QProcess(this);
    connect(executeProc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(executeProcFinished(int, QProcess::ExitStatus)));
    connect(executeProc, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(executeProcError(QProcess::ProcessError)));
}

void SourceCode::executeProcFinished(int, QProcess::ExitStatus status) {
    qDebug() << "finished";
    qDebug() << executeProc->readAllStandardOutput();
    if (status == QProcess::ExitStatus::CrashExit)
        executableCrashed();
    else
        outputArrived(executeProc->readAllStandardOutput());
}

void SourceCode::executeProcError(QProcess::ProcessError) {
    qDebug("execute process error");
}

void SourceCode::addFlagsToList(QStringList& compileList) {
    QTextStream flagStream(&flags);
    QString currFlag;

    while (!flagStream.atEnd()) {
        flagStream >> currFlag;
        compileList << currFlag;
    }
}

void SourceCode::createCodeFile() {
    QFile file;
    file.setFileName(executableFilePath + codeExtension);
    if (file.exists())
        file.remove();
    qDebug() << "Test1";
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        file.write(code.toStdString().c_str());
    }
}

QString SourceCode::getLanguageType() {
    if (type == SourceCodeType::Compiled)
        return "compiled";
    else
        return "interpreted";
}

QString SourceCode::getLoaderType() {
    if (type == SourceCodeType::Compiled)
        return "compiler";
    else
        return "interpreter";
}

void SourceCode::runExecutable(const QString &input) {    
    executeProc->start(executableFilePath);
    executeProc->write(input.toStdString().c_str());
    executeProc->closeWriteChannel();
}

void SourceCode::terminateExecution() {
    executeProc->terminate();
    executeProc->close();
}

void SourceCode::removeExecutables() {
    QStringList extensions;
    extensions << "" << ".exe";
    QFile file;
    foreach (const QString& extension, extensions) {
        file.setFileName(executableDirectoryPath + extension);
        if (file.exists())
            file.remove();
    }//foreach
}

CompiledSourceCode::CompiledSourceCode(QObject *parent) : SourceCode(parent) {
    setType(Compiled);
    compileProc = new QProcess(parent);
    compileProc->setWorkingDirectory(QDir::currentPath() + QString("/executables"));
    connect(compileProc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(compileProcFinished(int, QProcess::ExitStatus)));
}

void CompiledSourceCode::compileProcFinished(int exit, QProcess::ExitStatus e) {
    qDebug() << exit << compileProc->readAllStandardOutput() << compileProc->readAllStandardError() << "!!!!";
    if (exit == 0) {
        compiled = true;        
        runExecutable(inputBuffer);
    }
}

void CompiledSourceCode::compile() {    
    terminateExecution();
    removeExecutables();
    compileProc->terminate();
    compileProc->close();
    QStringList compileList;
    addFlagsToList(compileList);
    createCodeFile();
    compileList << QString(getExecutableFilePath() + getCodeExtension());
    compileProc->start(getWorkPath(), compileList);
    compileProc->closeWriteChannel();
}

void CompiledSourceCode::set(QString const& newCode) {
    compiled = false;
    SourceCode::set(newCode);
    inputBuffer.clear();
}

void CompiledSourceCode::execute(const QString& input) {
    if (!compiled) {
        inputBuffer = input;
        compile();
    }
    else
        runExecutable(input);
}

SourceCodeCType::SourceCodeCType(QObject* parent, const QString& type) : CompiledSourceCode(parent) {
    if (type == "C") {
        setCodeExtension(".c");
    }
    else if (type == "C++") {
        setCodeExtension(".cc");
    }
    else if (type == "C#") {
        setCodeExtension(".cs");
    }
}

