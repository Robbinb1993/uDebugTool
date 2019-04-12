#ifndef SourceCode_H
#define SourceCode_H

#include <QString>
#include <QProcess>
#include <QObject>
#include <QQueue>

enum SourceCodeType {Compiled, Interpreted};

class SourceCode : public QObject {
    Q_OBJECT
    public:
        explicit SourceCode(QObject*);
        virtual ~SourceCode() {}
        virtual void execute(const QString&) {}
        virtual void set(const QString& newCode) {code = newCode;}
        void setPath(const QString& newPath) {workPath = newPath;}
        void setFlags(const QString& newFlags) {flags = newFlags;}
        QString getLanguageType();
        QString getLoaderType();
    protected:
        void addFlagsToList(QStringList& flagList);
        void createCodeFile();
        void setCodeExtension(const QString& extension) {codeExtension = extension;}
        void setType(const SourceCodeType& t) {type = t;}
        void runExecutable(const QString& input);
        void terminateExecution();
        void removeExecutables();
        QString getWorkPath() {return workPath;}
        QString getExecutableFilePath() {return executableFilePath;}
        QString getCodeExtension() {return codeExtension;}
        QString getFlags() {return flags;}
    private:
        QString flags;
        QString code;
        QString workPath;
        QString codeExtension;
        QString executableDirectoryPath;
        QString executableFilePath;
        QProcess *executeProc;
        SourceCodeType type;
    private slots:
        void executeProcFinished(int, QProcess::ExitStatus);
        void executeProcError(QProcess::ProcessError);
    signals:
        void outputArrived(const QByteArray& output);
        void loaderOutputArrived(int ret, const QByteArray& error, const QByteArray& output);
        void executableCrashed();
};

class CompiledSourceCode : public SourceCode {
    Q_OBJECT
    public:
        explicit CompiledSourceCode(QObject*);
        void set(const QString &newCode) override;
        void execute(const QString& input) override;
    private:
        void compile();        
        QProcess *compileProc;
        bool compiled = false;
        QString inputBuffer;
    private slots:
        void compileProcFinished(int, QProcess::ExitStatus);
};

class InterpretedSourceCode : public SourceCode {
    Q_OBJECT
    public:
        InterpretedSourceCode(QObject* parent) : SourceCode(parent) {setType(Interpreted);}
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
        explicit SourceCodePython(QObject* parent) : InterpretedSourceCode(parent) {}
};


#endif // SourceCode_H
