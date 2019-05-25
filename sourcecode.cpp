#include "sourcecode.h"
#include <QString>
#include <QProcess>
#include <QDir>
#include <QTextStream>
#include <QDebug>

SourceCode::SourceCode(QObject *parent) : QObject(parent) {
    executableDirectoryPath = QDir::currentPath() + "/executables";
    setCodeFileName("a");
    executeProc = new QProcess(this);
    connect(executeProc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(executeProcFinished(int, QProcess::ExitStatus)));
    connect(executeProc, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(executeProcError(QProcess::ProcessError)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(procTimedOut()));
    timer.start();
}

void SourceCode::executeProcFinished(int ret, QProcess::ExitStatus status) {
    if (!ret)
        outputArrived(executeProc->readAllStandardOutput(), timeMeasure.elapsed());
    else
        executionFailed(executeProc->readAllStandardError(), !timedOut);
}

void SourceCode::terminate() {
    executeProc->close();
    terminated = 1;
}

void SourceCode::executeProcError(QProcess::ProcessError) {
    executionFailed(executeProc->readAllStandardError(), !timedOut);
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
    QFile file(getCodePath());
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

void SourceCode::setTimer(const int timeOutValue) {
    timedOut = false;
    timeMeasure.start();
    timer.start(timeOutValue);
}

void CompiledSourceCode::runExecutable(const QString &input, const int timeOutValue) {
    getExecuteProc()->start(getExecutablePath());
    getExecuteProc()->write(input.toStdString().c_str());
    getExecuteProc()->closeWriteChannel();
    setTimer(timeOutValue);
}

void SourceCode::terminateExecution() {
    executeProc->terminate();
    executeProc->close();
}

CompiledSourceCode::CompiledSourceCode(QObject *parent) : SourceCode(parent) {
    setType(Compiled);
    compileProc = new QProcess(parent);
    compileProc->setWorkingDirectory(getExecutableDirectoryPath());
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
    compileProc->close();
    QStringList compileList;
    addFlagsToList(compileList);
    createCodeFile();
    compileList << QString(getCodePath());
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
}

void CompiledSourceCode::execute(const QString& input, const int timeOutValue) {
    if (!compiled) {
        inputBuffer = input;
        timeOutValueBuffer = timeOutValue;
        compile();
    }
    else {
        runExecutable(input, timeOutValue);
    }
}

void CompiledSourceCode::setWorkDir(const QString& workDir) {
    SourceCode::setWorkDir(workDir);
    compileProc->setWorkingDirectory(getExecutableDirectoryPath());
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

SourceCodeJava::SourceCodeJava(QObject* parent) : CompiledSourceCode(parent) {
    setExecuterName("java");
    setCodeExtension(".java");
    parserLocation = QDir::currentPath() + "/javaparse/javaparse.jar";
    javaParser = new QProcess(this);
    connect(javaParser, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(javaParsingFinished(int, QProcess::ExitStatus)));
    connect(javaParser, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(javaParsingError(QProcess::ProcessError)));
}

void SourceCodeJava::javaParsingFinished(int ret, QProcess::ExitStatus) {
    if (ret == 0) {
        QTextStream parseStream(javaParser->readAllStandardOutput());
        QString newCode = parseStream.readLine();
        set(newCode);
        QString codeFileName;
        parseStream >> codeFileName;
        setCodeFileName(codeFileName);
        compileAfterPreprocess();
    }
    else
        loaderOutputArrived(ret, javaParser->readAllStandardError(), javaParser->readAllStandardOutput());
}

void SourceCodeJava::javaParsingError(QProcess::ProcessError error) {
    qDebug() << "Java parser error occured." << error;
}

void SourceCodeJava::parseJavaCode() {
    QStringList list;
    list << "-jar";
    list << getParserLocation();
    list << getCode();
    javaParser->start("java", list);
    javaParser->closeWriteChannel();
}

void SourceCodeJava::compile() {
    parseJavaCode();
}

void SourceCodeJava::compileAfterPreprocess() {
    CompiledSourceCode::compile();
}

void SourceCodeJava::runExecutable(const QString& input, const int timeOutValue) {
    getExecuteProc()->close();
    QStringList compileList;
    compileList << "-cp";
    compileList << getExecutableDirectoryPath();
    compileList << getCodeFileName();
    getExecuteProc()->start("java", compileList);
    getExecuteProc()->write(input.toStdString().c_str());
    getExecuteProc()->closeWriteChannel();
    setTimer(timeOutValue);
}

void InterpretedSourceCode::runExecutable(const QString& input, const int timeOutValue) {
    getExecuteProc()->close();
    QStringList interpretList;
    addFlagsToList(interpretList);
    createCodeFile();
    interpretList << getCodePath();
    getExecuteProc()->start(getWorkPath(), interpretList);
    getExecuteProc()->write(input.toStdString().c_str());
    getExecuteProc()->closeWriteChannel();
    setTimer(timeOutValue);
}

void InterpretedSourceCode::execute(const QString& input, const int timeOutValue) {
    runExecutable(input, timeOutValue);
}

