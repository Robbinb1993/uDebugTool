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
#include "hintswindow.h"

const QString judges[10] = {"0", "TOPH", "DS", "CATS", "URI", "FBHC", "LOJ", "GCJ", "UVA", "LA"};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void closeEvent(QCloseEvent* event);
private:    
    Ui::MainWindow *ui;
    NetworkManager* netmgr;
    OutputHandler* outHandler;
    CodeEditor* codeEditor;
    InputChainChecker* chainChecker;
    RIGChecker* rigChecker;
    HintsWindow* hintsWindow;
    QString currLang, inputFile;
    QMovie* movie;
    QTimer *codeEditorShowTimer, *checkAllTimer;
    bool inputsReady = 1, hintsReady = 1, acOutputReady = 1, userOutputReady = 1, problemReady = 0;
    bool procTerminate, allCheckRunning = 0, RIGCheckRunning = 0;
    int timeOutValue;
    int chainIdx;
    QByteArray errorCopy;

    void setLayout();
    void setTimeout();
    bool readyToCheck();
    void executeNextInTable();
    void getRIGInput();
    void checkLoader();
    void execute(const bool firstInput);
    void selectProblemNotification();
    void stopChecking();
    void showChainChecker();
private slots:
    void inputsReceived(const QByteArray&);
    void hintFetchingFinished();
    void inputFetchingFinished();
    void testcaseReceived(const QByteArray&);    
    void changeTestcase(const QString&);
    void on_searchProb_clicked();
    void on_checkIn_clicked();
    void on_checkAll_clicked();
    void RIGStart();
    void on_filter_clicked();
    void on_submitCode_clicked();
    void on_timeLimitIn_editingFinished();
    void on_judgeSelect_currentIndexChanged(int index);
    void on_checkRIG_clicked();
    void RIGInputReceived(const QByteArray&);
    void on_hintButton_clicked();
    void reqHint(const QString&);
    void comparisonFinished();
    void probNameReceived(const QString& probName);
    void multiOutputProblemDetected();
    void problemDescriptionReceived(const QString& url);
    void userOutputReceived(const QByteArray& output, const qint64 time);
    void acOutputReceived(const QByteArray& output);
    void executionFailedReceived(const QByteArray& error, bool crashed);
    void loaderErrorReceived();
    void outputResultReceived(const bool success);
    void chainCheckTerminated();
    void showCodeEditor();
    void showRIGChecker();
    void checkAllStart();
};

#endif // MAINWINDOW_H
