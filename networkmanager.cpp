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
}

NetworkManager::~NetworkManager() {
    clear();
}

void NetworkManager::clear() {
    curlGetInputs->close();
    curlPostInput->close();
    curlGetTestcase->close();
    curlGetHints->close();
    curlGetHint->close();
}

void NetworkManager::scrape(const QString judgeName, const QString problemID) {
    QUrl url(QString("https://www.udebug.com/" + judgeName + QString("/") + problemID));
    QNetworkRequest req = QNetworkRequest(url);
    manager->get(req);
}

void NetworkManager::scrapingDone(QNetworkReply* reply) {
    std::string html = reply->readAll().toStdString();
    std::string needle = "flag-problem-title problem-title\">";
    size_t pos = html.find(needle);
    if (pos != std::string::npos) {
        QString probName = "";
        pos += int(needle.size());
        while (html[pos] != '<' && pos < size_t(html.length()))
            probName += html[pos++];
        probNameReady(probName);
    }
    needle = "type-of-problem\"> ";
    pos = html.find(needle);
    if (pos != std::string::npos)  {
        pos += (int)needle.size();
        if (html[pos] == 'M')
            multiOutputProblem();
    }
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
        }
    }
    needle = "problem-flagged";
    if ((pos = html.find(needle)) != std::string::npos)
        QMessageBox::information(dynamic_cast<QWidget*>(this->parent()), tr("Message"), tr("This problem has been flagged and is under review. You can still use it though."));
}

void NetworkManager::searchInputs(const QString& judgeName, const QString& id) {
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
}

void NetworkManager::searchHints(const QString& judgeName, const QString& id) {
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
}

void NetworkManager::getTestcase(const QString& id) {
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
}

void NetworkManager::getHint(const QString& id) {
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
}

void NetworkManager::postCustomInput(const QString& judgeName, const QString& id, const QString& testcase) {
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
}

void NetworkManager::procError(QProcess::ProcessError error) {
    if (error == QProcess::ProcessError::FailedToStart)
        QMessageBox::information(dynamic_cast<QWidget*>(this->parent()), tr("Message"), tr("Curl could not be found. Make sure Curl is installed."));
}

void NetworkManager::inputPostError(QProcess::ProcessError error) {
}

void NetworkManager::getInputsFinished(int, QProcess::ExitStatus e) {
    if (e == QProcess::ExitStatus::NormalExit)
        inputsArrived(curlGetInputs->readAllStandardOutput());
}

void NetworkManager::getHintsFinished(int, QProcess::ExitStatus e) {
    if (e == QProcess::ExitStatus::NormalExit)
        hintsArrived(curlGetHints->readAllStandardOutput());
}

void NetworkManager::getAcOutputFinished(int, QProcess::ExitStatus e) {
    if (e == QProcess::ExitStatus::NormalExit)
        acOutputArrived(curlPostInput->readAllStandardOutput());
}

void NetworkManager::getTestcaseFinished(int, QProcess::ExitStatus) {
    testcaseOutputArrived(curlGetTestcase->readAllStandardOutput());
}

void NetworkManager::getHintFinished(int, QProcess::ExitStatus) {
    hintOutputArrived(curlGetHint->readAllStandardOutput());
}


