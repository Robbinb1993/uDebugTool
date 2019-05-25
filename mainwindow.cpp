#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

void MainWindow::setTimeout() {
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup("timeout");
    timeOutValue = settings.value("time").toInt();
    QString txt = "Time limit: ";
    if (timeOutValue >= 100000) { //display in seconds
        txt.append(std::to_string(timeOutValue / 1000).c_str());
        txt.append(" s");
    }
    else { //display in milliseconds
        txt.append(std::to_string(timeOutValue).c_str());
        txt.append(" ms");
    }
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
    connect(chainChecker, SIGNAL(windowClosed()), this, SLOT(chainCheckTerminated()));

    rigChecker = new RIGChecker(this);
    connect(rigChecker, SIGNAL(RIGCheckStart()), this, SLOT(RIGStart()));
    connect(rigChecker, SIGNAL(sendInput(const QByteArray&)), this, SLOT(RIGInputReceived(const QByteArray&)));

    codeEditor = new CodeEditor("executables", "Code Loader", "executables", this);
    connect(codeEditor, SIGNAL(outputReady(const QByteArray&, const qint64)), this, SLOT(userOutputReceived(const QByteArray&, const qint64)));
    connect(codeEditor, SIGNAL(executionFailed(const QByteArray&, bool)), this, SLOT(executionFailedReceived(const QByteArray&, bool)));
    connect(codeEditor, SIGNAL(loaderErrorArrived()), this, SLOT(loaderErrorReceived()));

    outHandler = new OutputHandler(this, ui->acOut, ui->userOut, ui->resultLine);
    connect(outHandler, SIGNAL(outputResult(bool)), this, SLOT(outputResultReceived(bool)));
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

    codeEditorShowTimer = new QTimer(this);
    codeEditorShowTimer->setSingleShot(true);
    connect(codeEditorShowTimer, SIGNAL(timeout()), SLOT(showCodeEditor()));

    checkAllTimer = new QTimer(this);
    checkAllTimer->setSingleShot(true);
    connect(checkAllTimer, SIGNAL(timeout()), SLOT(checkAllStart()));

    setTimeout();

    installEventFilter(this);
    raise();
}

bool MainWindow::eventFilter(QObject *, QEvent *event) {    
    if (event && event->type() == QEvent::WindowActivate) {
        codeEditor->hide();
        rigChecker->hide();
        return true;
    }
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
    }
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

void MainWindow::userOutputReceived(const QByteArray& output, const qint64 time) {
    if (!userOutputReady) {
        outHandler->setExecutionTime(time);
        outHandler->userOutputReceived(output);
        userOutputReady = true;
        checkLoader();
    }
}

void MainWindow::acOutputReceived(const QByteArray& output) {
    if (!acOutputReady) {
        acOutputReady = true;
        outHandler->acOutputReceived(output);
        checkLoader();
    }
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
    rigChecker->clear();
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

void MainWindow::stopChecking() {
    allCheckRunning = RIGCheckRunning = false;
    acOutputReady = userOutputReady = true;
    chainChecker->hide();
    rigChecker->hide();
    checkLoader();
}

void MainWindow::execute(const bool firstInput) {
    outHandler->clear();
    acOutputReady = userOutputReady = false;
    QString input = ui->customIn->toPlainText();
    netmgr->postCustomInput(judges[ui->judgeSelect->currentIndex()], ui->problemId->text(), input);
    ui->acOut->setPlainText("Accepted output is being fetched.");
    ui->userOut->setPlainText("Your output is being calculated.");
    codeEditor->execute(input, timeOutValue, firstInput);
}

void MainWindow::selectProblemNotification() {
    QMessageBox::information(this, tr("Message"), tr("Please select a problem."));
}

void MainWindow::on_checkIn_clicked() {
    if (!problemReady) {
        selectProblemNotification();
        return;
    }
    ui->loadLabel->show();
    RIGCheckRunning = false;
    allCheckRunning = false;
    execute(true);
}

void MainWindow::showChainChecker() {
    chainChecker->show();
    chainChecker->raise();
    chainChecker->setFocus();
    chainChecker->showNormal();
}

void MainWindow::showRIGChecker() {
    rigChecker->show();
    rigChecker->raise();
    rigChecker->setFocus();
    rigChecker->showNormal();
}

void MainWindow::checkAllStart() {
    ui->loadLabel->show();
    RIGCheckRunning = false;
    allCheckRunning = true;
    chainIdx = 1;
    executeNextInTable();
    chainChecker->progress(0, ui->inputTable->rowCount());
    showChainChecker();
}

void MainWindow::on_checkAll_clicked() {
    if (!problemReady) {
        selectProblemNotification();
        return;        
    }
    if (!ui->inputTable->isReady()) {
        QMessageBox::information(this, tr("Message"), tr("Please wait until all test cases have been fetched."));
        return;
    }
    checkAllTimer->start(250);
}

void MainWindow::on_checkRIG_clicked() {
    if (!problemReady) {
        selectProblemNotification();
        return;
    }
    showRIGChecker();
}

void MainWindow::RIGInputReceived(const QByteArray& in) {
    ui->customIn->setPlainText(QString::fromLocal8Bit(in));
    execute(chainIdx == 1);
}

void MainWindow::RIGStart() {
    RIGCheckRunning = true;
    allCheckRunning = true;
    ui->loadLabel->show();    
    chainChecker->progress(0, rigChecker->getIterations());
    showChainChecker();
    chainIdx = 1;
    getRIGInput();
}

void MainWindow::executeNextInTable() {
    if (chainIdx <= ui->inputTable->rowCount()) {
        ui->customIn->setPlainText(ui->inputTable->requestInfo(chainIdx - 1));
        userOutputReady = acOutputReady = false;
        execute(chainIdx == 1);
    }
    else {
       checkLoader();
       outHandler->clear();
   }
}

void MainWindow::getRIGInput() {
    if (chainIdx <= rigChecker->getIterations())
        rigChecker->fetchNextInput(chainIdx == 1);
    else {
        checkLoader();
        outHandler->clear();
    }
}

void MainWindow::outputResultReceived(const bool success) {
    if (allCheckRunning) {
        if (success) {
            if (RIGCheckRunning) {
                chainChecker->progress(chainIdx++, rigChecker->getIterations());
                getRIGInput();
            }
            else {
                chainChecker->progress(chainIdx++, ui->inputTable->rowCount());
                executeNextInTable();
            }
            return;
        }
        else
            chainChecker->mismatchFound(chainIdx);
    }
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
    showCodeEditor();
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

void MainWindow::executionFailedReceived(const QByteArray&, bool crashed) {
    if (crashed) {
        outHandler->userProgCrashed();
        codeEditorShowTimer->start(200);
    }
    else
        outHandler->userProgTimedOut();
    if (allCheckRunning)
        chainChecker->mismatchFound(chainIdx);
    stopChecking();
}

void MainWindow::showCodeEditor() {
    codeEditor->show();
    codeEditor->raise();
    codeEditor->setFocus();
    codeEditor->showNormal();
}

void MainWindow::loaderErrorReceived() {
    stopChecking();
    //timer calls showCodeEditor function
    codeEditorShowTimer->start(200); //timer used so that rigchecker window and chainchecker window have time to close
}

void MainWindow::chainCheckTerminated() {
    stopChecking();
    codeEditor->terminate();
    rigChecker->terminate();
}
