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

    movie = new QMovie("images/loader", QByteArray(), this);
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
    if (timeOutValue >= 100000) { //display in seconds
        txt.append(std::to_string(timeOutValue / 1000).c_str());
        txt.append(" s");
    }//if
    else { //display in milliseconds
        txt.append(std::to_string(timeOutValue).c_str());
        txt.append(" ms");
    }//else
    ui->timeLimitIn->setText(txt);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setLayout();

    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup("judge");
    ui->judgeSelect->setCurrentIndex(settings.value("idx").toInt());

    currLang = "";
    hintsWindow = new HintsWindow(this);
    chainChecker = new InputChainChecker(this);
    connect(chainChecker, SIGNAL(windowClosed()), this, SLOT(terminateChainCheck()));

    rigchecker = new RIGChecker(this);
    connect(rigchecker, SIGNAL(windowClosed()), this, SLOT(terminateChainCheck()));
    connect(rigchecker, SIGNAL(RIGCheckStart()), this, SLOT(RIGStart()));
    connect(rigchecker, SIGNAL(sendInput(const QByteArray&)), this, SLOT(RIGInputReceived(const QByteArray&)));

    codeEditor = new CodeEditor("executables", "Code Loader", this);
    connect(codeEditor, SIGNAL(outputReady(const QByteArray&, const int)), this, SLOT(userOutputReceived(const QByteArray&, const int)));
    connect(codeEditor, SIGNAL(executionFailed(bool)), this, SLOT(executionFailedReceived(bool)));
    connect(codeEditor, SIGNAL(loaderErrorArrived()), this, SLOT(loaderErrorReceived()));

    outHandler = new OutputHandler(this, ui->acOut, ui->userOut, ui->resultLine);
    connect(outHandler, SIGNAL(chainResult(bool)), this, SLOT(chainResultReceived(bool)));
    connect(outHandler, SIGNAL(comparisonFinished()), this, SLOT(comparisonFinished()));
    connect(ui->acOut->verticalScrollBar(), &QAbstractSlider::valueChanged, ui->userOut->verticalScrollBar(), &QAbstractSlider::setValue);
    connect(ui->userOut->verticalScrollBar(), &QAbstractSlider::valueChanged, ui->acOut->verticalScrollBar(), &QAbstractSlider::setValue);
    connect(ui->acOut->horizontalScrollBar(), &QAbstractSlider::valueChanged, ui->userOut->horizontalScrollBar(), &QAbstractSlider::setValue);
    connect(ui->userOut->horizontalScrollBar(), &QAbstractSlider::valueChanged, ui->acOut->horizontalScrollBar(), &QAbstractSlider::setValue);

    connect(ui->inputTable, SIGNAL(sendInfo(const QString&)), this, SLOT(changeTestcase(const QString&)));
    connect(ui->inputTable, SIGNAL(ready()), this, SLOT(inputFetchingFinished()));

    netmgr = new NetworkManager(this);
    connect(ui->inputTable, SIGNAL(getInfo(const QString&)), netmgr, SLOT(getTestcase(const QString&)));
    connect(netmgr, SIGNAL(acOutputArrived(const QByteArray&)), this, SLOT(acOutputReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(testcaseOutputArrived(const QByteArray&)), this, SLOT(testcaseReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(inputsArrived(const QByteArray&)), this, SLOT(inputsReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(hintsArrived(const QByteArray&)), hintsWindow, SLOT(hintsReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(hintOutputArrived(const QByteArray&)), hintsWindow, SLOT(hintReceived(const QByteArray&)));
    connect(netmgr, SIGNAL(probNameReady(const QString&)), this, SLOT(probNameReceived(const QString&)));
    connect(netmgr, SIGNAL(multiOutputProblem()), this, SLOT(multiOutputProblemDetected()));
    connect(netmgr, SIGNAL(problemDescriptionReady(const QString&)), this, SLOT(problemDescriptionReceived(const QString&)));

    setTimeout();

    installEventFilter(this);
    raise();
}

//EVENTS
bool MainWindow::eventFilter(QObject *, QEvent *event) {    
    if (event && event->type() == QEvent::WindowActivate) {
        codeEditor->hide();
        rigchecker->hide();
        return true;
    }//if
    return false;
}

void MainWindow::closeEvent(QCloseEvent*) {
    QCoreApplication::exit();
}

void MainWindow::changeTestcase(const QString& testcase) {
    ui->customIn->setPlainText(testcase);
}

void MainWindow::inputsReceived(const QByteArray& result) {
    if (result.indexOf("error") != -1) {
        QString message = "The problem has not been found.";
        QMessageBox::information(this, tr("Message"), tr(message.toUtf8()));
        problemReady = true;
        inputFetchingFinished();
    }//if
    else
        ui->inputTable->addEntries(result);
}

void MainWindow::inputFetchingFinished() {
    inputsReady = true;
    checkLoader();
}

void MainWindow::hintFetchingFinished() {
    hintsReady = true;
    checkLoader();
}

void MainWindow::probNameReceived(const QString &probName) {
    ui->probNameLabel->setText(probName);
    problemReady = true;
}

void MainWindow::multiOutputProblemDetected() {
    QMessageBox::information(this, tr("Message"), tr("There may be multiple correct outputs for this problem."));
}

void MainWindow::problemDescriptionReceived(const QString &url) {
    ui->probNameLabel->setText(QString("<a href =\"") + url + QString("\">") + ui->probNameLabel->text() + QString("</a>"));
}

void MainWindow::testcaseReceived(const QByteArray& result) {
    ui->inputTable->addInfo(result);
}

void MainWindow::userOutputReceived(const QByteArray& output, const int time) {
    outHandler->userOutputReceived(output);
    outHandler->setExecutionTime(time);
    userOutputReady = true;
    checkLoader();
}

void MainWindow::acOutputReceived(const QByteArray& output) {
    outHandler->acOutputReceived(output);
    acOutputReady = true;
    checkLoader();
}

void MainWindow::on_searchProb_clicked() {
    problemReady = 0;

    if (ui->judgeSelect->currentIndex() == 0) {
        QMessageBox::information(this, tr("Message"), tr("Please select a judge."));
        return;
    }
    if (ui->problemId->text().length() == 0 || !(ui->problemId->text().toStdString().find_first_not_of("0123456789") == std::string::npos)) {
        QMessageBox::information(this, tr("Message"), tr("Please enter a problem ID."));
        return;
    }

    ui->probNameLabel->clear();
    rigchecker->clear();
    ui->customIn->clear();
    ui->inputTable->clear();
    outHandler->clear();

    ui->inputTable->resetting = true;
    hintsWindow->clear();

    netmgr->clear(); //Close all running network processes

    inputsReady = hintsReady = false;
    netmgr->searchInputs(judges[ui->judgeSelect->currentIndex()], ui->problemId->text());
    netmgr->searchHints(judges[ui->judgeSelect->currentIndex()], ui->problemId->text());
    netmgr->scrape(judges[ui->judgeSelect->currentIndex()], ui->problemId->text());
    ui->loadLabel->show();
}

void MainWindow::checkLoader() {
    if (inputsReady && acOutputReady && userOutputReady && hintsReady)
        ui->loadLabel->hide();
}

void MainWindow::execute() {
    outHandler->clear();
    acOutputReady = userOutputReady = false;
    QString input = ui->customIn->toPlainText();
    netmgr->postCustomInput(judges[ui->judgeSelect->currentIndex()], ui->problemId->text(), input);
    codeEditor->execute(input, timeOutValue);
    ui->acOut->setPlainText("Accepted output\nis being fetched.");
}

void MainWindow::on_checkIn_clicked() {    
    if (!problemReady)
        return;    
    ui->loadLabel->show();    
    outHandler->disableChainCheck();
    execute();
}

void MainWindow::on_checkAll_clicked() {    
    if (!problemReady)
        return;
    if (!ui->inputTable->isReady()) {
        QMessageBox::information(this, tr("Message"), tr("Please wait until all test cases have been fetched."));
        return;
    }//if
    ui->loadLabel->show();
    RIGCheckRunning = false;
    outHandler->enableChainCheck();
    chainChecker->progress(0, ui->inputTable->rowCount());
    chainTerminate = false;
    chainIdx = 1;
    executeNextInTable();
    chainChecker->show();
}

void MainWindow::on_checkRIG_clicked() {
    if (!problemReady)
        return;
    if (!rigchecker->isVisible())
        rigchecker->show();
    rigchecker->raise();
    rigchecker->activateWindow();
}

void MainWindow::RIGInputReceived(const QByteArray& in) {
    ui->customIn->setPlainText(QString::fromLocal8Bit(in));
}

void MainWindow::RIGStart() {
    RIGCheckRunning = true;
    chainTerminate = false;
    ui->loadLabel->show();
    outHandler->enableChainCheck();
    chainChecker->show();
    chainChecker->progress(0, rigchecker->getIterations());
    chainIdx = 1;
    getRIGInput();
}

void MainWindow::executeNextInTable() {
    if (chainIdx <= ui->inputTable->rowCount()) {
        ui->customIn->setPlainText(ui->inputTable->requestInfo(chainIdx - 1));
        execute();
    }
    else {
       checkLoader();
       outHandler->clear();
   }
}

void MainWindow::getRIGInput() {
    if (chainIdx <= rigchecker->getIterations())
        rigchecker->fetchNextInput();
    else {
        checkLoader();
        outHandler->clear();
    }
}

void MainWindow::chainResultReceived(const bool success) {
    if (chainTerminate)
        return;
    if (success) {
        if (RIGCheckRunning) {
            chainChecker->progress(chainIdx++, rigchecker->getIterations());
            getRIGInput();
        }
        else {
            chainChecker->progress(chainIdx++, ui->inputTable->rowCount());
            executeNextInTable();
        }
    }
    else {
        checkLoader();
        qDebug() << "MISMATCH";
        chainChecker->mismatchFound(chainIdx);
        terminateChainCheck();
    }
}

void MainWindow::terminateChainCheck() {
    chainTerminate = true;
    chainChecker->chainTerminated();
    checkLoader();
}

void MainWindow::comparisonFinished() {
    checkLoader();
}

void MainWindow::on_filter_clicked() {
    if (ui->filter->text() == "Filter off")
        ui->filter->setText("Filter on");
    else
        ui->filter->setText("Filter off");
    outHandler->toggleFilter();
}

void MainWindow::on_submitCode_clicked() {
    if (!codeEditor->isVisible())
        codeEditor->show();
    codeEditor->raise();
    codeEditor->activateWindow();
}

void MainWindow::on_timeLimitIn_editingFinished() {
    QString text = ui->timeLimitIn->text();
    if (text.length() && text.toStdString().find_first_not_of("0123456789") == std::string::npos) {
        timeOutValue = text.toInt();
        QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
        settings.beginGroup("timeout");
        settings.setValue("time", timeOutValue);
    }
    setTimeout();
}

void MainWindow::on_judgeSelect_currentIndexChanged(int) {
    QSettings settings(QDir::currentPath() + QString("/config.ini"), QSettings::IniFormat);
    settings.beginGroup("judge");
    settings.setValue("idx", ui->judgeSelect->currentIndex());
}

void MainWindow::on_hintButton_clicked() {
    if (!hintsWindow->isVisible())
        hintsWindow->show();
    hintsWindow->raise();
    hintsWindow->activateWindow();
}

void MainWindow::reqHint(const QString& id) {
    netmgr->getHint(id);
}

void MainWindow::loadingFailedReceived() {
    userOutputReady = true;
    outHandler->clear();
}

void MainWindow::executionFailedReceived(bool crashed) {
    if (crashed)
        outHandler->userProgCrashed();
    else
        outHandler->userProgTimedOut();
    userOutputReady = true;
    checkLoader();
}

void MainWindow::loaderErrorReceived() {
    userOutputReady = true;
    checkLoader();
}
