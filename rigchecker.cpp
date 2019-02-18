#include "rigchecker.h"
#include "ui_rigchecker.h"

RIGChecker::RIGChecker(const ExecuteInfo *e, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RIGChecker),
    executer(e) {
    ui->setupUi(this);
    setWindowTitle("RIG Checker");
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    codeEditor = new CodeEditor("rig", "Random Input Generator Loader", parent);
    connect(codeEditor, SIGNAL(programReady(const QString&, const QString&)), this, SLOT(setRIG(const QString&, const QString&)));
    iterations = 1;
    currLang = programPath = "";
    ui->loadRIG->setDefault(false);
    ui->loadRIG->setAutoDefault(false);
    ui->check->setDefault(false);
    ui->check->setAutoDefault(false);

    proc = new QProcess(this);
    connect(proc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(procFinished(int, QProcess::ExitStatus)));

    installEventFilter(this);
}//constructor

bool RIGChecker::eventFilter(QObject *, QEvent* e) {
    if (e->type() == QEvent::Type::HideToParent)
        windowClosed();
    return false;
}//eventFilter

RIGChecker::~RIGChecker() {
    delete ui;
}//destructor

void RIGChecker::clear() {
    ui->loadRIG->setStyleSheet("QPushButton {background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f); border-color: #545454;border-width: 1px;border-radius: 5px;border-style: solid;color: white;}QPushButton:pressed {background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);}");
}//clear

int RIGChecker::getIterations() {
    return iterations;
}//getIterations

void RIGChecker::on_loadRIG_clicked() {
    if (!codeEditor->isVisible())
        codeEditor->show();
    codeEditor->raise();
    codeEditor->activateWindow();
}//loadRIG

void RIGChecker::on_iterationsLine_editingFinished() {
    QString text = ui->iterationsLine->text();
    if (text.length() && text.toStdString().find_first_not_of("0123456789") == std::string::npos)
        iterations = text.toInt();
    QString txt = "Total iterations: ";
    txt.append(std::to_string(iterations).c_str());
    ui->iterationsLine->setText(txt);
}//on_iterationsLine_editingFinished

void RIGChecker::setRIG(const QString &pName, const QString &lang) {
    programPath = pName;
    currLang = lang;
    ui->loadRIG->setStyleSheet("QPushButton {background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #008000, stop:0.48 #006600, stop:0.52 #004d00, stop:1 #003300); border-color: #003300; border-width: 1px;border-radius: 5px;border-style: solid;color: white;}QPushButton:pressed {background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);}");
    raise();
    activateWindow();
}//setRIG

void RIGChecker::on_check_clicked() {
    if (programPath.length() == 0) {
        QMessageBox::information(this, tr("Message"), tr("Please load a RIG."));
        return;
    }//if
    codeEditor->hide();
    hide();
    RIGCheckStart();
}//on_check_clicked

void RIGChecker::fetchNextInput() {
    proc->terminate();
    proc->close();
    //start process depending on language (java, python, just executable)
    if (executer->getExecuteInfo(currLang).length() == 0)
        proc->start(programPath);
    else {
        QStringList list;
        if (currLang == "Java")
            list << "-cp", list << QDir::currentPath() + QString("/rig:");
        list << programPath;
        proc->start(executer->getExecuteInfo(currLang), list);
    }//else
    proc->closeWriteChannel();
}//fetchNextInput

void RIGChecker::procFinished(int, QProcess::ExitStatus status) {
    if (status == QProcess::ExitStatus::CrashExit)
        RIGCrash();
    else
        sendInput(proc->readAllStandardOutput());
    proc->close();
}//procFinished
