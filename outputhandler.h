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
    void acOutputReceived(const QByteArray&);
    void userOutputReceived(const QByteArray&);
    void userProgCrashed();
    void userProgTimedOut();
    void toggleFilter();
    void setExecutionTime(const qint64 t);
private:
    Editor * const acOut;
    Editor * const userOut;
    QLineEdit * const resultLine;
    QTextCharFormat green, red, white;
    std::string acTxt, userTxt;
    qint64 executionTime;
    bool acReady, userReady, cleared, filter;
    void compareOutputs();
signals:
    void outputResult(const bool success);
    void comparisonFinished();
};

#endif // OUTPUTHANDLER
