#include "codeeditor.h"
#include "ui_codeeditor.h"
#include <memory>

void CodeEditor::setLayout() {    
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->compilerOutput->viewport()->setCursor(Qt::ArrowCursor);

    QTextOption option = ui->codeEditor->document()->defaultTextOption();
    option.setTabStop(QFontMetricsF(ui->codeEditor->font()).width(QChar(' ')) * 4);
    ui->codeEditor->document()->setDefaultTextOption(option);
}

CodeEditor::CodeEditor(const QString d, const QString windowName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CodeEditor)
    {
    ui->setupUi(this);

    if (!QDir(d).exists())
        QDir().mkdir(d);

    setWindowTitle(windowName);
    setLayout();

    new SyntaxHighlighter(ui->codeEditor->document());

    sourcecode = nullptr;

    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup("lang");
    ui->languageSelect->setCurrentIndex(settings.value("idx").toInt());    
}

CodeEditor::~CodeEditor() {
    delete ui;
}

void CodeEditor::setSourcecode(const QString& langName) {
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup(langName);
    QString flags = settings.value("flags").toString();
    QString path = settings.value("compilerPath").toString();

    if (sourcecode != nullptr)
        delete sourcecode;
    if (langName == "C" || langName == "C++" || langName == "C#")
        sourcecode = new SourceCodeCType(this, langName);
    else if (langName == "Java")
        sourcecode = new SourceCodeJava(this);
    else if (langName == "Python")
        sourcecode = new SourceCodePython(this);
    else {
        qDebug("Language could not be found");
        sourcecode = new SourceCode(this);
    }
    connect(sourcecode, SIGNAL(outputArrived(const QByteArray&)), this, SLOT(outputReceived(const QByteArray&)));
    connect(sourcecode, SIGNAL(loaderOutputArrived(int, const QByteArray&, const QByteArray&)), this, SLOT(loaderOutputReceived(int, const QByteArray&, const QByteArray&)));

    sourcecode->setFlags(flags);
    sourcecode->setPath(path);

    ui->loaderButton->setText("Load " + sourcecode->getLoaderType());
}

void CodeEditor::execute(const QString& input) {
    qDebug() << "2nd EXECUTE request";
    sourcecode->set(ui->codeEditor->toPlainText());
    sourcecode->execute(input);
}

void CodeEditor::loaderOutputReceived(int ret, const QByteArray& error, const QByteArray& output) {
    if (ret != 0)
        ui->compilerOutput->setPlainText(error + "\n" + output);        
    else
        ui->compilerOutput->setPlainText("Code succesfully " + sourcecode->getLanguageType());
}

void CodeEditor::on_loaderButton_clicked() {
    QString path = QFileDialog::getOpenFileName(this, tr("Select the compiler"), "C://", "*");
    if (int(path.length()) == 0)
        return;    
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup(ui->languageSelect->currentText());
    settings.setValue("compilerPath", path);
    sourcecode->setPath(path);
}

void CodeEditor::on_submitCodeButton_clicked() {
    QString codeFile = QFileDialog::getOpenFileName(this, tr("Select the code file"), "C://", "Code File (*.c *.cc *.cpp *.java)");
    QFile file(codeFile);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&file);
        ui->codeEditor->setPlainText(in.readAll());
    }
}

void CodeEditor::on_languageSelect_currentIndexChanged(const QString& curr) {
    setSourcecode(curr);
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup("lang");
    settings.setValue("idx", ui->languageSelect->currentIndex());
}

void CodeEditor::on_flagLine_editingFinished() {
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    QString flags = ui->flagLine->text();
    settings.beginGroup(ui->languageSelect->currentText());
    settings.setValue("flags", flags);
    sourcecode->setFlags(flags);
}
