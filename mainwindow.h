#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QScrollBar>
#include <QTime>
#include <QTimer>
#include <QSettings>
#include <QThread>
#include <QIcon>
#include <QMovie>
#include <sstream>
#include "networkmanager.h"
#include "outputhandler.h"
#include "codeeditor.h"
#include "inputchainchecker.h"
#include "rigchecker.h"
#include "executeinfo.h"
#include "hintswindow.h"

const QString judges[10] = {"0", "TOPH", "DS", "CATS", "URI", "FBHC", "LOJ", "GCJ", "UVA", "LA"};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void closeEvent(QCloseEvent* event);
private:    
    Ui::MainWindow *ui;
    QString programPath;
    QProcess* proc;
    NetworkManager* netmgr;
    OutputHandler* outHandler;
    CodeEditor* codeEditor;
    InputChainChecker* chainChecker;
    RIGChecker* rigchecker;
    HintsWindow* hintsWindow;
    QString currLang, inputFile;
    QMovie* movie;
    bool inputsReady, hintsReady, procReady;
    const ExecuteInfo* executer;
    QTime timer;
    QTimer timeOut;
    bool procTerminate, chainTerminate, timedOut, RIGCheckRunning;
    int timeOutValue;
    int chainIdx;

    void setLayout();
    void setTimeout();
    bool readyToCheck();
    void executeProgs(const QString& in);
    void executeNextInTable();
    void getRIGInput();
    void checkLoader();
private slots:
    void inputsReceived(const QByteArray&);
    void hintFetchingFinished();
    void inputFetchingFinished();
    void testcaseReceived(const QByteArray&);    
    void changeTestcase(const QString&);
    void procFinished(int, QProcess::ExitStatus);    
    void setProgram(const QString& pName, const QString& lang);
    void on_searchProb_clicked();
    void on_checkIn_clicked();
    void on_checkAll_clicked();
    void RIGStart();
    void on_filter_clicked();
    void on_submitCode_clicked();
    void procTimedOut();
    void on_timeLimitIn_editingFinished();
    void chainResultReceived(const bool success);
    void terminateChainCheck();
    void on_judgeSelect_currentIndexChanged(int index);
    void on_checkRIG_clicked();
    void RIGInputReceived(const QByteArray&);
    void on_hintButton_clicked();
    void reqHint(const QString&);
    void comparisonFinished();
    void probNameReceived(const QString& probName);
    void multiOutputProblemDetected();
    void problemDescriptionReceived(const QString& url);
};

#endif // MAINWINDOW_H
