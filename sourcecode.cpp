#include "sourcecode.h"
#include <QString>
#include <QProcess>
#include <QDir>
#include <QTextStream>
#include <QDebug>

SourceCode::SourceCode(QObject *parent) : QObject(parent) {
    QString executableDirectoryPath = QDir::currentPath() + "/executables";
    executableFilePath = executableDirectoryPath + "/a";
    executeProc = new QProcess(this);
    connect(executeProc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(executeProcFinished(int, QProcess::ExitStatus)));
    connect(executeProc, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(executeProcError(QProcess::ProcessError)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(procTimedOut()));
}

void SourceCode::executeProcFinished(int, QProcess::ExitStatus status) {
    qDebug() << timeMeasure.elapsed();
    if (status == QProcess::ExitStatus::NormalExit)
        outputArrived(executeProc->readAllStandardOutput(), timeMeasure.elapsed());
    else
        executionFailed(!timedOut);
}

void SourceCode::terminate() {
    executeProc->close();
    terminated = 1;
}

void SourceCode::executeProcError(QProcess::ProcessError) {
    qDebug("execute process error");
    executionFailed(!timedOut);
}

void SourceCode::procTimedOut() {
    timedOut = true;
    executeProc->close();
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

void SourceCode::runExecutable(const QString &input, int timeOutValue) {
    executeProc->start(executableFilePath);
    executeProc->write(input.toStdString().c_str());
    executeProc->closeWriteChannel();
    timedOut = false;
    timeMeasure.start();
    timer.start(timeOutValue);
}

void SourceCode::terminateExecution() {
    executeProc->terminate();
    executeProc->close();
}

CompiledSourceCode::CompiledSourceCode(QObject *parent) : SourceCode(parent) {
    setType(Compiled);
    compileProc = new QProcess(parent);
    compileProc->setWorkingDirectory(QDir::currentPath() + QString("/executables"));
    connect(compileProc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(compileProcFinished(int, QProcess::ExitStatus)));
}

void CompiledSourceCode::compileProcFinished(int exit, QProcess::ExitStatus) {
    if (!hasTerminated())
        loaderOutputArrived(exit, compileProc->readAllStandardError(), compileProc->readAllStandardOutput());
    if (exit == 0) {
        compiled = true;        
        runExecutable(inputBuffer, timeOutValueBuffer);
    }
}

void CompiledSourceCode::compile() {    
    terminateExecution();
    compileProc->terminate();
    compileProc->close();
    QStringList compileList;
    addFlagsToList(compileList);
    createCodeFile();
    compileList << QString(getExecutableFilePath() + getCodeExtension());
    compileProc->start(getWorkPath(), compileList);
    compileProc->closeWriteChannel();
}

void CompiledSourceCode::terminate() {
    SourceCode::terminate();
    compileProc->close();
}

void CompiledSourceCode::set(QString const& newCode) {
    compiled = false;
    SourceCode::set(newCode);
    inputBuffer.clear();
}

void CompiledSourceCode::execute(const QString& input, const int timeOutValue) {
    if (!compiled) {
        inputBuffer = input;
        timeOutValueBuffer = timeOutValue;
        compile();
    }
    else
        runExecutable(input, timeOutValue);
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

