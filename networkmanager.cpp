#include "networkmanager.h"

NetworkManager::NetworkManager(QObject *parent) : QObject(parent),
    auth("Basic Um9iYmluYjE5OTM6VjRkM3IxMjM="),
    inputFile("in.txt"),
    curlPath("curl") {
    curlGetInputs = new QProcess(this);
    connect(curlGetInputs, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(getInputsFinished(int, QProcess::ExitStatus)));
    connect(curlGetInputs, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(procError(QProcess::ProcessError)));
    curlPostInput = new QProcess(this);
    connect(curlPostInput, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(getAcOutputFinished(int, QProcess::ExitStatus)));
    connect(curlPostInput, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(inputPostError(QProcess::ProcessError)));
    curlGetTestcase = new QProcess(this);
    connect(curlGetTestcase, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(getTestcaseFinished(int, QProcess::ExitStatus)));
    curlGetHints = new QProcess(this);
    connect(curlGetHints, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(getHintsFinished(int, QProcess::ExitStatus)));
    curlGetHint = new QProcess(this);
    connect(curlGetHint, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(getHintFinished(int, QProcess::ExitStatus)));
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(scrapingDone(QNetworkReply*)));
}//constructor

NetworkManager::~NetworkManager() {
}//destructor

void NetworkManager::clear() {
    curlGetInputs->kill();
    curlPostInput->kill();
    curlGetTestcase->kill();
    curlGetHints->kill();
    curlGetHint->kill();

    curlGetInputs->waitForFinished();
    curlPostInput->waitForFinished();
    curlGetTestcase->waitForFinished();
    curlGetHints->waitForFinished();
    curlGetHint->waitForFinished();
}//clear

void NetworkManager::scrape(const QString judgeName, const QString problemID) {
    QUrl url(QString("https://www.udebug.com/" + judgeName + QString("/") + problemID));
    QNetworkRequest req = QNetworkRequest(url);
    manager->get(req);
}//scrape

void NetworkManager::scrapingDone(QNetworkReply* reply) {
    std::string html = reply->readAll().toStdString();
    std::string needle = "flag-problem-title problem-title\">";
    size_t pos = html.find(needle);
    if (pos != std::string::npos) {
        QString probName = "";
        pos += (int)needle.size();
        while (html[pos] != '<' && pos < (size_t)html.length())
            probName += html[pos++];
        probNameReady(probName);
    }//if
    needle = "type-of-problem\"> ";
    pos = html.find(needle);
    if (pos != std::string::npos)  {
        pos += (int)needle.size();
        if (html[pos] == 'M')
            multiOutputProblem();
    }//if
    needle = "problem-statement-analysis-link";
    pos = html.find(needle);
    if (pos != std::string::npos)  {
        needle = "<a href=\"";
        pos = html.find(needle, pos);
        if (pos != std::string::npos)  {
            QString url = "";
            pos += needle.length();
            while (html[pos] != '\"' && pos < (size_t)html.length())
                url += html[pos++];
            problemDescriptionReady(url);
        }//if
    }//if
    needle = "problem-flagged";
    if ((pos = html.find(needle)) != std::string::npos)
        QMessageBox::information(dynamic_cast<QWidget*>(this->parent()), tr("Message"), tr("This problem has been flagged and is under review. You can still use it though."));
}//scrapingDone

void NetworkManager::searchInputs(const QString& judgeName, const QString& id) {
    curlGetInputs->terminate();
    curlGetInputs->close();
    QStringList args;
    args.append("-X");
    args.append("GET");
    args.append("https://www.udebug.com/input_api/input_list/retrieve.json?judge_alias=" + judgeName + "&problem_id=" + id);
    args.append("-H");
    args.append("accept: application/json");
    args.append("-H");
    args.append("authorization: " + auth);
    curlGetInputs->start(curlPath, args);
}//searchInputs

void NetworkManager::searchHints(const QString& judgeName, const QString& id) {
    curlGetHints->terminate();
    curlGetHints->close();
    QStringList args;
    args.append("-X");
    args.append("GET");
    args.append("https://www.udebug.com/hint_api/hint_list/retrieve.json?judge_alias=" + judgeName + "&problem_id=" + id);
    args.append("-H");
    args.append("accept: application/json");
    args.append("-H");
    args.append("authorization: " + auth);
    curlGetHints->start(curlPath, args);
}//searchInputs

void NetworkManager::getTestcase(const QString& id) {
    curlGetTestcase->terminate();
    curlGetTestcase->close();
    QStringList args;
    args.append("-X");
    args.append("GET");
    args.append("https://www.udebug.com/input_api/input/retrieve.json?input_id=" + id);
    args.append("-H");
    args.append("accept: application/json");
    args.append("-H");
    args.append("authorization: " + auth);
    curlGetTestcase->start(curlPath, args);
}//getTestcase

void NetworkManager::getHint(const QString& id) {
    curlGetHint->terminate();
    curlGetHint->close();
    QStringList args;
    args.append("-X");
    args.append("GET");
    args.append("https://www.udebug.com/hint_api/hint/retrieve.json?hint_id=" + id);
    args.append("-H");
    args.append("accept: application/json");
    args.append("-H");
    args.append("authorization: " + auth);
    curlGetHint->start(curlPath, args);
}//getHint

void NetworkManager::postCustomInput(const QString& judgeName, const QString& id, const QString& testcase) {
    curlPostInput->terminate();
    curlPostInput->close();
    QStringList args;
    QFile in(inputFile);
    in.open(QIODevice::WriteOnly);
    in.resize(0);
    in.write(testcase.toUtf8());
    in.close();
    args.append("-X");
    args.append("POST");
    args.append("https://www.udebug.com/output_api/post_custom_input/output.json");
    args.append("-H");
    args.append("accept: application/json");
    args.append("-H");
    args.append("authorization: " + auth);
    args.append("-H");
    args.append("Content-Type: multipart/form-data");
    args.append("-F");
    args.append("judge_alias=" + judgeName);
    args.append("-F");
    args.append("problem_id=" + id);//test
    args.append("-F");
    args.append("data=@" + inputFile + ";type=text/plain");
    curlPostInput->start(curlPath, args);
}//postCustomInput

void NetworkManager::procError(QProcess::ProcessError error) {
    if (error == QProcess::ProcessError::FailedToStart)
        QMessageBox::information(dynamic_cast<QWidget*>(this->parent()), tr("Message"), tr("Curl could not be found. Make sure Curl is installed."));
}//procError

void NetworkManager::inputPostError(QProcess::ProcessError error) {
    qDebug() << error;
}//inputPostError

void NetworkManager::getInputsFinished(int, QProcess::ExitStatus e) {
    if (e == QProcess::ExitStatus::NormalExit)
        emit(inputsArrived(curlGetInputs->readAllStandardOutput()));
}//getInputsFinished

void NetworkManager::getHintsFinished(int, QProcess::ExitStatus e) {
    if (e == QProcess::ExitStatus::NormalExit)
        emit(hintsArrived(curlGetHints->readAllStandardOutput()));
}//getHintsFinished

void NetworkManager::getAcOutputFinished(int, QProcess::ExitStatus e) {
    qDebug() << e;
    if (e == QProcess::ExitStatus::CrashExit) {
        emit(acOutputError());
    }//if
    else if (e == QProcess::ExitStatus::NormalExit)
        emit(acOutputArrived(curlPostInput->readAllStandardOutput()));
}//getAcOutputFinished

void NetworkManager::getTestcaseFinished(int, QProcess::ExitStatus) {
    emit(testcaseOutputArrived(curlGetTestcase->readAllStandardOutput()));
}//getTestcaseFinished

void NetworkManager::getHintFinished(int, QProcess::ExitStatus) {
    emit(hintOutputArrived(curlGetHint->readAllStandardOutput()));
}//getHintFinished


