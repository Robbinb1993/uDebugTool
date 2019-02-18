#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include <QPlainTextEdit>
#include <QProcess>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLineEdit>
#include <sstream>
#include "editor.h"

class OutputHandler : public QObject {
    Q_OBJECT
public:
    OutputHandler(QObject* parent, Editor * const, Editor * const, QLineEdit* const);
    void clear();
    void yourOutputReceived(const QByteArray&);
    void yourProgCrashed();
    void yourProgTimedOut();
    void toggleFilter();
    void setExecutionTime(const int t);
    void enableChainCheck();
    void disableChainCheck();
private:
    Editor * const acOut;
    Editor * const yourOut;
    QLineEdit * const resultLine;
    QTextCharFormat green, red, white;
    std::string acTxt, yourTxt;
    int executionTime;
    bool acReady, yourReady, cleared, filter, chainCheck;
    void compareOutputs();
private slots:
    void acOutputReceived(const QByteArray&);
    void acOutputErrorOccurred();
signals:
    void chainResult(const bool success);
    void comparisonFinished();
};

#endif // OUTPUTHANDLER
