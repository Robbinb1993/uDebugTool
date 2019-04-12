#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class NetworkManager : public QObject {
    Q_OBJECT
public:
    NetworkManager(QObject*);
    ~NetworkManager();
    void searchInputs(const QString&, const QString&);
    void searchHints(const QString&, const QString&);
    void getHint(const QString&);
    void postCustomInput(const QString&, const QString&, const QString&);
    void scrape(const QString judgeName, const QString problemID);
    void clear();

private:
    QProcess *curlGetInputs, *curlPostInput, *curlGetTestcase, *curlGetHints, *curlGetHint;    
    QNetworkAccessManager* manager;
    const QString auth, inputFile, curlPath;
private slots:
    void getTestcase(const QString&);
    void getInputsFinished(int, QProcess::ExitStatus);
    void getAcOutputFinished(int, QProcess::ExitStatus);
    void getTestcaseFinished(int, QProcess::ExitStatus);
    void getHintsFinished(int, QProcess::ExitStatus);
    void getHintFinished(int, QProcess::ExitStatus);
    void procError(QProcess::ProcessError);
    void inputPostError(QProcess::ProcessError);
    void scrapingDone(QNetworkReply* reply);
signals:
    void inputsArrived(const QByteArray&);
    void acOutputArrived(const QByteArray&);
    void hintsArrived(const QByteArray&);
    void hintOutputArrived(const QByteArray&);
    void testcaseOutputArrived(const QByteArray&);
    void probNameReady(const QString& probName);
    void multiOutputProblem();
    void problemDescriptionReady(const QString& url);
};

#endif // NETWORKMANAGER_H
