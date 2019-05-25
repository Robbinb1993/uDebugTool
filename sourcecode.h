#ifndef SourceCode_H
#define SourceCode_H

#include <QString>
#include <QProcess>
#include <QObject>
#include <QQueue>
#include <QElapsedTimer>
#include <QTimer>
#include <QDir>

enum SourceCodeType {Compiled, Interpreted};

class SourceCode : public QObject {
    Q_OBJECT
    public:
        explicit SourceCode(QObject*);
        virtual ~SourceCode() {terminate();}
        virtual void execute(const QString&, const int) {}
        virtual void set(const QString& newCode) {code = newCode; terminated = false;}
        void setPath(const QString& newPath) {workPath = newPath;}
        void setFlags(const QString& newFlags) {flags = newFlags;}        
        virtual void terminate();
        virtual void setWorkDir(const QString& workDir) {executableDirectoryPath = QDir::currentPath() + "/" + workDir;}
        QString getLanguageType();
        QString getLoaderType();
    protected:
        void addFlagsToList(QStringList& flagList);
        void createCodeFile();
        void setCodeExtension(const QString& extension) {codeExtension = extension;}
        void setType(const SourceCodeType& t) {type = t;}
        void terminateExecution();
        void setTimer(const int timeOutValue);
        void setCodeFileName(const QString& name) {codeFileName = name;}
        bool hasTerminated() {return terminated;}
        virtual void runExecutable(const QString&, int) {}
        QString getWorkPath() {return workPath;}
        QString getExecutableDirectoryPath() {return executableDirectoryPath;}
        QString getExecutablePath() {return getExecutableDirectoryPath() + "/" + getCodeFileName();}
        QString getCodePath() {return getExecutablePath() + getCodeExtension();}
        QString getCodeExtension() {return codeExtension;}
        QString getCodeFileName() {return codeFileName;}
        QString getFlags() {return flags;}
        QString getCode() {return code;}
        QProcess* getExecuteProc() {return executeProc;}
    private:
        QString flags;
        QString code;
        QString workPath;
        QString codeExtension;
        QString executableDirectoryPath;
        QString codeFileName;
        SourceCodeType type;
        QElapsedTimer timeMeasure;
        QTimer timer;
        QProcess *executeProc;
        bool timedOut;
        bool terminated = 0;
    private slots:
        void executeProcFinished(int, QProcess::ExitStatus);
        void executeProcError(QProcess::ProcessError);
        void procTimedOut();
    signals:
        void outputArrived(const QByteArray& output, const qint64 time);
        void loaderOutputArrived(int ret, const QByteArray& error, const QByteArray& output);
        void executionFailed(const QByteArray& error, bool crashed);
};

class CompiledSourceCode : public SourceCode {
    Q_OBJECT
    public:
        explicit CompiledSourceCode(QObject*);
        virtual ~CompiledSourceCode() override {terminate();}
        void set(const QString &newCode) override;
        void execute(const QString& input, const int timeOutValue) override;
        void terminate() override;
        virtual void setWorkDir(const QString& workDir) override;
    protected:
        void setExecuterName(const QString& name) {executerName = name;}
        virtual void compile();
    private:        
        QProcess *compileProc;
        bool compiled = false;
        QString inputBuffer;
        QString executerName;
        int timeOutValueBuffer;
        virtual void runExecutable(const QString& input, int timeOutValue) override;
        QString getExecuterName() {return executerName;}
    private slots:
        void compileProcFinished(int, QProcess::ExitStatus);
};

class InterpretedSourceCode : public SourceCode {
    Q_OBJECT
    public:
        InterpretedSourceCode(QObject* parent) : SourceCode(parent) {setType(Interpreted);}
        void execute(const QString& input, const int timeOutValue) override;
    private:
        void runExecutable(const QString& input, int timeOutValue) override;
};

class SourceCodeCType : public CompiledSourceCode {
    Q_OBJECT
    public:
        SourceCodeCType(QObject* parent, const QString& type);
};

class SourceCodeJava : public CompiledSourceCode {
    Q_OBJECT
    public:
        explicit SourceCodeJava(QObject* parent);
    private:
        void compile() override;
        void compileAfterPreprocess();
        void runExecutable(const QString& input, int timeOutValue) override;
        void parseJavaCode();
        QString getParserLocation() {return parserLocation;}
        QProcess* javaParser;
        QString parserLocation;
    private slots:
        void javaParsingFinished(int, QProcess::ExitStatus);
        void javaParsingError(QProcess::ProcessError);

};

class SourceCodePython : public InterpretedSourceCode {
    Q_OBJECT
    public:
        explicit SourceCodePython(QObject* parent) : InterpretedSourceCode(parent) {setCodeExtension(".py");}
};


#endif // SourceCode_H
