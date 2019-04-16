#ifndef SourceCode_H
#define SourceCode_H

#include <QString>
#include <QProcess>
#include <QObject>
#include <QQueue>
#include <QTime>
#include <QTimer>

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
        QString getLanguageType();
        QString getLoaderType();
    protected:
        void addFlagsToList(QStringList& flagList);
        void createCodeFile();
        void setCodeExtension(const QString& extension) {codeExtension = extension;}
        void setType(const SourceCodeType& t) {type = t;}
        virtual void runExecutable(const QString& input, int timeOutValue);
        void terminateExecution();
        void setTimer(const int timeOutValue);
        bool hasTerminated() {return terminated;}
        QString getWorkPath() {return workPath;}
        QString getExecutableFilePath() {return executableFilePath;}
        QString getCodeExtension() {return codeExtension;}
        QString getFlags() {return flags;}
        QProcess* getExecuteProc() {return executeProc;}
    private:
        QString flags;
        QString code;
        QString workPath;
        QString codeExtension;
        QString executableFilePath;
        SourceCodeType type;
        QTime timeMeasure;
        QTimer timer;
        QProcess *executeProc;
        bool timedOut;
        bool terminated = 0;
    private slots:
        void executeProcFinished(int, QProcess::ExitStatus);
        void executeProcError(QProcess::ProcessError);
        void procTimedOut();
    signals:
        void outputArrived(const QByteArray& output, const int time);
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
    private:
        void compile();
        QProcess *compileProc;
        bool compiled = false;
        QString inputBuffer;
        int timeOutValueBuffer;
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
        explicit SourceCodeJava(QObject* parent) : CompiledSourceCode(parent) {}
};

class SourceCodePython : public InterpretedSourceCode {
    Q_OBJECT
    public:
        explicit SourceCodePython(QObject* parent) : InterpretedSourceCode(parent) {setCodeExtension(".py");}
};


#endif // SourceCode_H
