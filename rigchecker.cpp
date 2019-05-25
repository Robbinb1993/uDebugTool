#include "rigchecker.h"
#include "ui_rigchecker.h"
#include <QMessageBox>

RIGChecker::RIGChecker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RIGChecker) {
    ui->setupUi(this);
    setWindowTitle("RIG Checker");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

    codeEditor = new CodeEditor("rig", "Random Input Generator Loader", "rig", parent);
    connect(codeEditor, SIGNAL(outputReady(const QByteArray&, const qint64)), this, SLOT(RIGOutputReceived(const QByteArray&, const qint64)));
    connect(codeEditor, SIGNAL(executionFailed(const QByteArray&, bool)), this, SLOT(executionFailedReceived(const QByteArray&, bool)));
    connect(codeEditor, SIGNAL(loaderErrorArrived()), this, SLOT(loaderErrorReceived()));

    iterations = 1;
    ui->loadRIG->setDefault(false);
    ui->loadRIG->setAutoDefault(false);
    ui->check->setDefault(false);
    ui->check->setAutoDefault(false);
}

RIGChecker::~RIGChecker() {
    delete ui;
}

void RIGChecker::terminate() {
    codeEditor->terminate();
}

void RIGChecker::RIGOutputReceived(const QByteArray& output, const qint64) {
    sendInput(output);
}

void RIGChecker::executionFailedReceived(const QByteArray& error, bool crashed) {
    if (crashed)
        QMessageBox::information(this, tr("Message"), tr("The random input generator has crashed."));
    else
        QMessageBox::information(this, tr("Message"), tr("The random input generator has timed out."));
    terminateRIG();
}

void RIGChecker::showCodeEditor() {
    codeEditor->show();
    codeEditor->raise();
    codeEditor->activateWindow();
    codeEditor->showNormal();
}

void RIGChecker::loaderErrorReceived() {
    hide();
    showCodeEditor();
}

void RIGChecker::clear() {
    ui->loadRIG->setStyleSheet("QPushButton {background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f); border-color: #545454;border-width: 1px;border-radius: 5px;border-style: solid;color: white;}QPushButton:pressed {background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);}");
}

int RIGChecker::getIterations() {
    return iterations;
}

void RIGChecker::on_loadRIG_clicked() {
    showCodeEditor();
}

void RIGChecker::on_iterationsLine_editingFinished() {
    QString text = ui->iterationsLine->text();
    if (text.length() && text.toStdString().find_first_not_of("0123456789") == std::string::npos)
        iterations = text.toInt();
    QString txt = "Total iterations: ";
    txt.append(std::to_string(iterations).c_str());
    ui->iterationsLine->setText(txt);
}

void RIGChecker::setRIG() {
    ui->loadRIG->setStyleSheet("QPushButton {background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #008000, stop:0.48 #006600, stop:0.52 #004d00, stop:1 #003300); border-color: #003300; border-width: 1px;border-radius: 5px;border-style: solid;color: white;}QPushButton:pressed {background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);}");
    raise();
    activateWindow();
}

void RIGChecker::on_check_clicked() {
    codeEditor->hide();
    hide();
    RIGCheckStart();
}

void RIGChecker::fetchNextInput(const bool firstInput) {
    codeEditor->execute("", 10000, firstInput);
}

