#include "codeeditor.h"
#include "ui_codeeditor.h"

void CodeEditor::setLayout() {    
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->compilerOutput->viewport()->setCursor(Qt::ArrowCursor);

    QTextOption option = ui->codeEditor->document()->defaultTextOption();
    option.setTabStop(QFontMetricsF(ui->codeEditor->font()).width(QChar(' ')) * 4);
    ui->codeEditor->document()->setDefaultTextOption(option);
}//setLayout

CodeEditor::CodeEditor(const QString d, const QString windowName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CodeEditor),
    codeDir(QDir(QDir::currentPath() + QString("/") + d)),
    codePath(codeDir.path() + QString("/yourCode")) {
    ui->setupUi(this);

    if (!QDir(d).exists())
        QDir().mkdir(d);

    setWindowTitle(windowName);
    setLayout();
    initLanguages();

    new SyntaxHighlighter(ui->codeEditor->document());
    compilerPath = "";

    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup("lang");
    ui->languageSelect->setCurrentIndex(settings.value("idx").toInt());

    proc = new QProcess(this);
    proc->setWorkingDirectory(codeDir.path());
    connect(proc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(procFinished(int, QProcess::ExitStatus)));
    connect(proc, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(procError(QProcess::ProcessError)));
}//constructor

CodeEditor::~CodeEditor() {
    delete ui;
}//destructor

void CodeEditor::initLanguages() {
    //Language: C
    LanguageSettings settings;
    settings.codeExtension = ".c";
    settings.compileList << "-o" << codePath << QString(codePath + settings.codeExtension);
    settings.extensions << "" << ".exe";
    languageSettings["C"] = settings;
    //Language: C++
    settings = LanguageSettings();
    settings.codeExtension = ".cc";
    settings.compileList << "-o" << codePath << QString(codePath + settings.codeExtension);
    settings.extensions << "" << ".exe";
    languageSettings["C++"] = settings;
    //Language: C#
    settings = LanguageSettings();
    settings.codeExtension = ".cs";
    settings.compileList << QString(codePath + settings.codeExtension);
    settings.extensions << "" << ".exe";
    languageSettings["C#"] = settings;
    //Language: Java
    settings = LanguageSettings();
    settings.codeExtension = ".java";
    settings.extensions << ".class";
    languageSettings["Java"] = settings;
}//initLanguages

void CodeEditor::procError(QProcess::ProcessError error) {
    if (error == QProcess::ProcessError::FailedToStart)
        ui->compilerOutput->setPlainText("The compiler failed to start. Is the path correct?");
    else if (error == QProcess::ProcessError::Crashed)
        ui->compilerOutput->setPlainText("The compiler has crashed...");
    else if (error == QProcess::ProcessError::Timedout)
        ui->compilerOutput->setPlainText("The compiler timed out.");
    else
        ui->compilerOutput->setPlainText("An error has occurred.");
}//procError

void CodeEditor::procFinished(int, QProcess::ExitStatus) {
    ui->compilerOutput->setPlainText("");
    QString path = codePath;
    QFile file;
    LanguageSettings& settings = languageSettings[ui->languageSelect->currentText()];

    bool found = false;
    if (ui->languageSelect->currentText() == "Java") {
        QStringList classFilter("*.class");
        QDir directory(codeDir.path());
        QStringList classFiles = directory.entryList(classFilter);
        if (!classFiles.empty()) {
            found = true;
            programReady(javaFilename.length() ? QString(javaFilename.c_str()) : QString("Main"), "Java");
        }//if
    }//if
    else {
        foreach (const QString& extension, settings.extensions) {
            file.setFileName(path + extension);
            if (file.exists()) {
                qDebug() << file.fileName();
                found = true;
                programReady(codePath + extension, ui->languageSelect->currentText());
                break;
            }//if
        }//foreach
    }//else
    if (!found)
        ui->compilerOutput->setPlainText("Error\n");
    else
        ui->compilerOutput->setPlainText("Success: program has been loaded.\n");

    qDebug() << proc->readAll();

    ui->compilerOutput->appendPlainText(proc->readAllStandardError() + "\n" + proc->readAllStandardOutput());
    ui->compilerOutput->verticalScrollBar()->setValue(0);
}//procFinished

void CodeEditor::compileProgram() {
    if (ui->languageSelect->currentIndex() == 0) {
        QMessageBox::information(this, tr("Message"), tr("Please select a programming language."));
        return;
    }//if
    if (compilerPath.length() == 0) {
        QMessageBox::information(this, tr("Message"), tr("Please load a compiler."));
        return;
    }//if
    ui->compilerOutput->setPlainText("Compiling program...");

    LanguageSettings& settings = languageSettings[ui->languageSelect->currentText()];

    QFile file;

    //Remove all class files and java files if language is Java
    if (ui->languageSelect->currentText() == "Java") {
        QStringList classFilter;
        classFilter << "*.class" << "*.java";
        QDir directory(codeDir.path());
        QStringList classFiles = directory.entryList(classFilter);
        for (QString c : classFiles) {
            file.setFileName(codeDir.path() + QString("/") + c);
            file.remove();
        }//for
    }//if

    //Remove executables
    QString path = codePath;
    qDebug() << path;
    QStringList extensions;
    extensions << "" << ".exe";
    foreach (const QString& extension, extensions) {
        file.setFileName(path + extension);
        if (file.exists())
            file.remove();
    }//foreach

    //Close any running compiling process
    proc->terminate();
    proc->close();

    //Set the flags
    QStringList list;
    std::stringstream SS;
    std::string flag;
    SS << ui->flagLine->text().toStdString();
    while (SS >> flag)
        list << QString(flag.c_str());

    //Write editor contents to code file
    QString editorText = ui->codeEditor->toPlainText();
    QString code = ui->codeEditor->toPlainText();

    //JAVA START
    if (ui->languageSelect->currentText() == "Java") {
        //Filter package if it exists for easier compiling/executing
        int sidx, idx, eidx;
        if ((sidx = code.indexOf("package")) != -1) {
            idx = sidx;
            while (code[idx] != ';' && idx < (int)code.length())
                idx++;
            eidx = idx;
            code = "";
            for (int i = 0; i < (int)editorText.length(); i++) {
                if (i < sidx || i > eidx)
                    code += editorText[i];
            }//for
        }//if

        std::stringstream ss;
        std::string prv = "", curr, prvClass = "";
        bool found = false;
        ss << code.toStdString();
        file.setFileName(codeDir.path() + QString("/") + "Main.java");
        javaFilename = "";
        while (ss >> curr) {
            if (curr == "class") {
                if (ss >> curr) {
                    if (curr.back() == '{')
                        curr.pop_back();
                    prvClass = curr;
                }//if                
            }//if
            else if (prv == "void" && curr.length() >= 4 && curr.substr(0, 4) == "main" && !(curr.length() > 4 && curr[4] != '(')) {
                javaFilename = prvClass;
                found = true;
                break;
            }//if
            prv = curr;
        }//while
        if (found) {
            list << codeDir.path() + QString("/") + QString(javaFilename.c_str()) + QString(".java");
            file.setFileName(codeDir.path() + QString("/") + QString(javaFilename.c_str()) + QString(".java"));
        }//if
        else
            list << QString(codeDir.path() + QString("/") + "Main.java");
    }//if
    //JAVA END
    else
        file.setFileName(codePath + settings.codeExtension);

    if (file.exists())
        file.remove();
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << code;
    }//if

    list << settings.compileList;

    //Execute the compiling process
    proc->start(compilerPath, list);
    proc->closeWriteChannel();
}//compileProgram

void CodeEditor::on_compileButton_clicked() {
    QFontMetrics metrics(ui->codeEditor->font());
    compileProgram();
}//on_compileButton_clicked

void CodeEditor::on_loadCompilerButton_clicked() {
    QString path = QFileDialog::getOpenFileName(this, tr("Select the compiler"), "C://", "*");
    if ((int)path.length() == 0)
        return;
    compilerPath = path;
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup(ui->languageSelect->currentText());
    settings.setValue("compilerPath", compilerPath);
}//on_loadCompilerButton_clicked

void CodeEditor::on_submitCodeButton_clicked() {
    QString codeFile = QFileDialog::getOpenFileName(this, tr("Select the code file"), "C://", "Code File (*.c *.cc *.cpp *.java)");
    QFile file(codeFile);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&file);
        ui->codeEditor->setPlainText(in.readAll());
    }//if
}//on_submitCodeButton_clicked

void CodeEditor::on_languageSelect_currentIndexChanged(const QString &curr) {
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup(curr);
    compilerPath = settings.value("compilerPath").toString();
    ui->flagLine->setText(settings.value("flags").toString());
    QSettings settings2(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings2.beginGroup("lang");
    settings2.setValue("idx", ui->languageSelect->currentIndex());
}//on_languageSelect_currentIndexChanged

void CodeEditor::on_flagLine_editingFinished() {
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup(ui->languageSelect->currentText());
    settings.setValue("flags", ui->flagLine->text());
}//on_flagLine_editingFinished
