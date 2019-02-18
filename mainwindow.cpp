#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

void MainWindow::setLayout() {
    QCoreApplication::setApplicationName("uDebug Tool");
    setWindowTitle(QCoreApplication::applicationName());
    for (int i = 0; i < ui->judgeSelect->count(); i++)
        ui->judgeSelect->setItemData(i, QBrush(Qt::white), Qt::TextColorRole);
    ui->problemId->setAlignment(Qt::AlignCenter);
    ui->problemId->setPlaceholderText("Problem ID");

    ui->checkIn->setToolTip("Check current input");
    ui->checkAll->setToolTip("Check all uDebug's input consecutively");
    ui->checkRIG->setToolTip("Check randomly generated inputs");

    ui->hintButton->setIcon(QIcon("images/hint"));
    ui->hintButton->setIconSize(QSize(32, 32));

    movie = new QMovie("images/loader");
    movie->setScaledSize(QSize(32, 32));
    movie->start();
    ui->loadLabel->setMovie(movie);
    ui->loadLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->loadLabel->hide();

    ui->probNameLabel->setOpenExternalLinks(true);

}//setLayout

void MainWindow::setTimeout() {
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup("timeout");
    timeOutValue = settings.value("time").toInt();
    QString txt = "Time limit: ";
    if (timeOutValue >= 100000) {
        txt.append(std::to_string(timeOutValue / 1000).c_str());
        txt.append(" s");
    }//if
    else {
        txt.append(std::to_string(timeOutValue).c_str());
        txt.append(" ms");
    }//else
    ui->timeLimitIn->setText(txt);
}//setTimeout

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    executer(new ExecuteInfo(this)) {
    ui->setupUi(this);
    setLayout();

    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup("judge");
    ui->judgeSelect->setCurrentIndex(settings.value("idx").toInt());

    currLang = "";
    hintsWindow = new HintsWindow(this);
    chainChecker = new InputChainChecker(this);
    connect(chainChecker, SIGNAL(windowClosed()), this, SLOT(terminateChainCheck()));
    rigchecker = new RIGChecker(executer, parent);
    connect(rigchecker, SIGNAL(windowClosed()), this, SLOT(terminateChainCheck()));
    connect(rigchecker, SIGNAL(RIGCheckStart()), this, SLOT(RIGStart()));
    connect(rigchecker, SIGNAL(sendInput(const QByteArray&)), this, SLOT(RIGInputReceived(const QByteArray&)));
    codeEditor = new CodeEditor("executables", "Code Loader", parent);
    connect(codeEditor, SIGNAL(programReady(const QString&, const QString&)), this, SLOT(setProgram(const QString&, const QString&)));
    outHandler = new OutputHandler(this, ui->acOut, ui->yourOut, ui->resultLine);
    connect(outHandler, SIGNAL(chainResult(bool)), this, SLOT(chainResultReceived(bool)));
    connect(outHandler, SIGNAL(comparisonFinished()), this, SLOT(comparisonFinished()));
    connect(ui->acOut->verticalScrollBar(), &QAbstractSlider::valueChanged, ui->yourOut->verticalScrollBar(), &QAbstractSlider::setValue);
    connect(ui->yourOut->verticalScrollBar(), &QAbstractSlider::valueChanged, ui->acOut->verticalScrollBar(), &QAbstractSlider::setValue);
    connect(ui->acOut->horizontalScrollBar(), &QAbstractSlider::valueChanged, ui->yourOut->horizontalScrollBar(), &QAbstractSlider::setValue);
    connect(ui->yourOut->horizontalScrollBar(), &QAbstractSlider::valueChanged, ui->acOut->horizontalScrollBar(), &QAbstractSlider::setValue);
    ui->inputTable->setTableType(TableTypes::InputTable);
    connect(ui->inputTable, SIGNAL(sendInfo(const QString&)), this, SLOT(changeTestcase(const QString&)));
    connect(ui->inputTable, SIGNAL(ready()), this, SLOT(inputFetchingFinished()));
    netmgr = new NetworkManager(this);
    connect(ui->inputTable, SIGNAL(getInfo(const QString&)), netmgr, SLOT(getTestcase(const QString&)));
    connect(netmgr, SIGNAL(acOutputError()), outHandler, SLOT(acOutputErrorOccurred()));
    connect(netmgr, SIGNAL(acOutputArrived(const QByteArray&)), outHandler, SLOT(acOutputReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(testcaseOutputArrived(const QByteArray&)), this, SLOT(testcaseReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(inputsArrived(const QByteArray&)), this, SLOT(inputsReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(hintsArrived(const QByteArray&)), hintsWindow, SLOT(hintsReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(hintOutputArrived(const QByteArray&)), hintsWindow, SLOT(hintReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(probNameReady(const QString&)), this, SLOT(probNameReceived(const QString&)));
    connect(netmgr, SIGNAL(multiOutputProblem()), this, SLOT(multiOutputProblemDetected()));
    connect(netmgr, SIGNAL(problemDescriptionReady(const QString&)), this, SLOT(problemDescriptionReceived(const QString&)));
    programPath = "";
    proc = new QProcess(this);
    connect(proc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(procFinished(int, QProcess::ExitStatus)));
    connect(&timeOut, SIGNAL(timeout()), this, SLOT(procTimedOut()));

    setTimeout();

    installEventFilter(this);
    raise();
}//constructor

MainWindow::~MainWindow() {
    rigchecker->deleteLater();
    codeEditor->deleteLater();
    hintsWindow->deleteLater();
    movie->deleteLater();
}//destructor

//EVENTS
bool MainWindow::eventFilter(QObject *, QEvent *event) {
    if (event && event->type() == QEvent::WindowActivate)
        raise();
    return false;
}//eventFilter

void MainWindow::closeEvent(QCloseEvent*) {
    QCoreApplication::exit();
}//closeEvent

void MainWindow::procTimedOut() {
    timedOut = true;
    proc->kill();
    outHandler->yourProgTimedOut();
}//procTimedOut

void MainWindow::changeTestcase(const QString& testcase) {
    ui->customIn->setPlainText(testcase);
}//changeTestcase

void MainWindow::inputsReceived(const QByteArray& result) {    
    ui->inputTable->addEntries(result);
}//inputsReceived

void MainWindow::inputFetchingFinished() {
    inputsReady = true;
    checkLoader();
}//hintFetchingFinished

void MainWindow::hintFetchingFinished() {
    hintsReady = true;
    checkLoader();
}//hintFetchingFinished

void MainWindow::probNameReceived(const QString &probName) {
    ui->probNameLabel->setText(probName);
}//probNameReceived

void MainWindow::multiOutputProblemDetected() {
    QMessageBox::information(this, tr("Message"), tr("There may be multiple correct outputs for this problem."));
}//multiOutputProblemDetected

void MainWindow::problemDescriptionReceived(const QString &url) {
    ui->probNameLabel->setText(QString("<a href =\"") + url + QString("\">") + ui->probNameLabel->text() + QString("</a>"));
}//problemDescriptionReceived

void MainWindow::testcaseReceived(const QByteArray& result) {
    ui->inputTable->addInfo(result);
}//testcaseReceived

void MainWindow::on_searchProb_clicked() {
    if (ui->judgeSelect->currentIndex() == 0) {
        QMessageBox::information(this, tr("Message"), tr("Please select a judge."));
        return;
    }//if
    if (ui->problemId->text().length() == 0 || !(ui->problemId->text().toStdString().find_first_not_of("0123456789") == std::string::npos)) {
        QMessageBox::information(this, tr("Message"), tr("Please enter a problem ID."));
        return;
    }//if

    ui->probNameLabel->clear();
    rigchecker->clear();
    ui->submitCode->setStyleSheet("QPushButton {background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #797979, stop:0.48 #696969, stop:0.52 #5e5e5e, stop:1 #4f4f4f); border-color: #545454;border-width: 1px;border-radius: 5px;border-style: solid;color: white;}QPushButton:pressed {background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);}");
    ui->customIn->clear();
    ui->inputTable->clear();
    outHandler->clear();

    ui->inputTable->resetting = true;
    hintsWindow->clear();

    netmgr->clear(); //Kill all running network processes

    inputsReady = hintsReady = false;
    procReady = true;
    netmgr->searchInputs(judges[ui->judgeSelect->currentIndex()], ui->problemId->text());
    netmgr->searchHints(judges[ui->judgeSelect->currentIndex()], ui->problemId->text());
    netmgr->scrape(judges[ui->judgeSelect->currentIndex()], ui->problemId->text());
    ui->loadLabel->show();
}//on_searchProb_clicked

bool MainWindow::readyToCheck() {
    if (programPath.length() == 0) {
        QMessageBox::information(this, tr("Message"), tr("Please load a program."));
        return false;
    }//if
    if (ui->judgeSelect->currentIndex() == 0) {
        QMessageBox::information(this, tr("Message"), tr("Please select a judge."));
        return false;
    }//if
    if (ui->problemId->text().length() == 0 || !(ui->problemId->text().toStdString().find_first_not_of("0123456789") == std::string::npos)) {
        QMessageBox::information(this, tr("Message"), tr("Please enter a problem ID."));
        return false;
    }//if
    return true;
}//readyToCheck

void MainWindow::executeProgs(const QString& in) {
    outHandler->clear();

    netmgr->postCustomInput(judges[ui->judgeSelect->currentIndex()], ui->problemId->text(), in);
    ui->acOut->setPlainText("Accepted output\nis being fetched.");

    procTerminate = true;
    proc->terminate();
    proc->close();
    procTerminate = false;
    //start process depending on language (java, python, just executable)

    if (executer->getExecuteInfo(currLang).length() == 0)
        proc->start(programPath);
    else {
        QStringList list;
        if (currLang == "Java")
            list << "-cp", list << QDir::currentPath() + QString("/executables;");
        list << programPath;

        proc->start(executer->getExecuteInfo(currLang), list);
    }//else
    ui->yourOut->setPlainText("Input is being\nprocessed by your pogram.");

    std::stringstream ss;
    std::string line;
    ss << in.toStdString();
    while (getline(ss, line)) {
        line += "\n";
        proc->write(line.c_str());
    }//while

    proc->closeWriteChannel();
    timer.start();
    timedOut = false;
    timeOut.start(timeOutValue);
}//executeProgs

void MainWindow::checkLoader() {
    if (inputsReady && hintsReady && procReady)
        ui->loadLabel->hide();
}//checkLoader

void MainWindow::on_checkIn_clicked() {    
    if (!readyToCheck())
        return;
    procReady = false;
    ui->loadLabel->show();
    RIGCheckRunning = false;
    outHandler->disableChainCheck();
    executeProgs(ui->customIn->toPlainText());
}//on_checkIn_clicked

void MainWindow::on_checkAll_clicked() {    
    if (!readyToCheck())
        return;
    if (!ui->inputTable->isReady()) {
        QMessageBox::information(this, tr("Message"), tr("Please wait until all test cases have been fetched."));
        return;
    }//if
    procReady = false;
    ui->loadLabel->show();
    RIGCheckRunning = false;
    outHandler->enableChainCheck();
    chainChecker->progress(0, ui->inputTable->rowCount());
    chainTerminate = false;
    chainIdx = 1;
    executeNextInTable();
    codeEditor->hide();
    chainChecker->show();
}//on_checkAll_clicked

void MainWindow::on_checkRIG_clicked() {
    if (!readyToCheck())
        return;
    if (!rigchecker->isVisible())
        rigchecker->show();
    rigchecker->raise();
    rigchecker->activateWindow();
}//on_checkRIG_clicked

void MainWindow::RIGInputReceived(const QByteArray& in) {
    ui->customIn->setPlainText(QString::fromLocal8Bit(in));
    executeProgs(in);
}//RIGInputReceived

void MainWindow::RIGStart() {
    RIGCheckRunning = true;
    chainTerminate = false;
    procReady = false;
    ui->loadLabel->show();
    outHandler->enableChainCheck();
    chainChecker->show();
    chainChecker->progress(0, rigchecker->getIterations());
    chainIdx = 1;
    getRIGInput();
}//on_RIGStart_clicked

void MainWindow::executeNextInTable() {
    if (chainIdx <= ui->inputTable->rowCount()) {
        ui->customIn->setPlainText(ui->inputTable->requestInfo(chainIdx - 1));
        executeProgs(ui->customIn->toPlainText());
    }//if
    else {
       procReady = true;
       checkLoader();
       if (hintsReady && inputsReady)
           ui->loadLabel->hide();
       ui->yourOut->clear();
       ui->acOut->clear();
       ui->customIn->clear();
   }//else
}//executeNextInTable

void MainWindow::getRIGInput() {
    if (chainIdx <= rigchecker->getIterations())
        rigchecker->fetchNextInput();
    else {
        procReady = true;
        checkLoader();
        ui->yourOut->clear();
        ui->acOut->clear();
        ui->customIn->clear();
    }//else
}//getRIGInput

void MainWindow::chainResultReceived(const bool success) {
    qDebug() << success;
    if (chainTerminate)
        return;
    if (success) {
        if (RIGCheckRunning) {
            chainChecker->progress(chainIdx++, rigchecker->getIterations());
            getRIGInput();
        }//if
        else {
            chainChecker->progress(chainIdx++, ui->inputTable->rowCount());
            executeNextInTable();
        }//else
    }//if
    else {
        procReady = true;
        checkLoader();
        chainChecker->mismatchFound(chainIdx);
    }//else
}//chainResultReceived

void MainWindow::terminateChainCheck() {
    chainTerminate = true;
    chainChecker->chainTerminated();
    procReady = true;
    checkLoader();
}//terminateChainCheck

void MainWindow::procFinished(int, QProcess::ExitStatus status) {
    timeOut.stop();
    if (status == QProcess::ExitStatus::CrashExit || timedOut) {
        if (!procTerminate && !timedOut)
            outHandler->yourProgCrashed();
    }//if
    else
        outHandler->yourOutputReceived(proc->readAllStandardOutput());
    outHandler->setExecutionTime(timer.elapsed());
    proc->close();
}//procFinished

void MainWindow::comparisonFinished() {
    procReady = true;
    checkLoader();
}//comparisonFinished

void MainWindow::setProgram(const QString& pName, const QString& lang) {
    programPath = pName;
    currLang = lang;
    raise();
    activateWindow();
    ui->submitCode->setStyleSheet("QPushButton {background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #008000, stop:0.48 #006600, stop:0.52 #004d00, stop:1 #003300); border-color: #003300; border-width: 1px;border-radius: 5px;border-style: solid;color: white;}QPushButton:pressed {background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5, stop:0 #dddddd, stop:1 #777777);}");
}//setProgram

void MainWindow::on_filter_clicked() {
    if (ui->filter->text() == "Filter off")
        ui->filter->setText("Filter on");
    else
        ui->filter->setText("Filter off");
    outHandler->toggleFilter();
}//on_filter_clicked

void MainWindow::on_submitCode_clicked() {
    if (!codeEditor->isVisible())
        codeEditor->show();
    codeEditor->raise();
    codeEditor->activateWindow();
}//on_submitCode_clicked

void MainWindow::on_timeLimitIn_editingFinished() {
    QString text = ui->timeLimitIn->text();
    if (text.length() && text.toStdString().find_first_not_of("0123456789") == std::string::npos) {
        timeOutValue = text.toInt();
        QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
        settings.beginGroup("timeout");
        settings.setValue("time", timeOutValue);
    }//if
    QString txt = "Time limit: ";
    if (timeOutValue >= 100000) {
        txt.append(std::to_string(timeOutValue / 1000).c_str());
        txt.append(" s");
    }//if
    else {
        txt.append(std::to_string(timeOutValue).c_str());
        txt.append(" ms");
    }//else
    ui->timeLimitIn->setText(txt);
}//on_timeLimitIn_editingFinished

void MainWindow::on_judgeSelect_currentIndexChanged(int) {
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup("judge");
    settings.setValue("idx", ui->judgeSelect->currentIndex());
}//on_judgeSelect_currentIndexChanged

void MainWindow::on_hintButton_clicked() {
    if (!hintsWindow->isVisible())
        hintsWindow->show();
    hintsWindow->raise();
    hintsWindow->activateWindow();
}//on_hintButton_clicked

void MainWindow::reqHint(const QString& id) {
    netmgr->getHint(id);
}//reqHint
