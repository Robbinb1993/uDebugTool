#include <QDebug>
#include "outputhandler.h"
#include <QCoreApplication>

OutputHandler::OutputHandler(QObject *parent, Editor * const ac, Editor * const user, QLineEdit * const line) :
QObject(parent), acOut(ac), userOut(user), resultLine(line) {
    acOut->setReadOnly(1);
    acOut->viewport()->setCursor(Qt::ArrowCursor);
    acOut->setLineWrapMode(QPlainTextEdit::NoWrap);
    acOut->document()->setDocumentMargin(6);
    acOut->disableHighlight();
    userOut->setReadOnly(1);
    userOut->viewport()->setCursor(Qt::ArrowCursor);
    userOut->setLineWrapMode(QPlainTextEdit::NoWrap);
    userOut->document()->setDocumentMargin(6);
    userOut->disableHighlight();
    acReady = userReady = cleared = filter = false;
    green.setBackground(QBrush(QColor(153, 255, 153)));
    red.setBackground(QBrush(QColor(255, 102, 102)));
    white.setBackground(QBrush(QColor(255, 255, 255)));
}

void OutputHandler::setExecutionTime(const qint64 time) {
    executionTime = time;
}

void OutputHandler::clear() {
    acReady = userReady = false;
    cleared = true;
    acOut->document()->setDocumentMargin(6);
    userOut->document()->setDocumentMargin(6);
    acOut->setCurrentCharFormat(white);
    acOut->disableFilter();
    acOut->clear();
    userOut->setCurrentCharFormat(white);
    userOut->disableFilter();
    userOut->clear();

    resultLine->clear();
    resultLine->setStyleSheet("QLabel{background: white;}");
    acOut->setStyleSheet("QPlainTextEdit{background: white;}");
    userOut->setStyleSheet("QPlainTextEdit{background: white;}");
}

void OutputHandler::acOutputReceived(const QByteArray& result) {
    QJsonDocument jsonResponse = QJsonDocument::fromJson(result);
    QJsonArray jsonArr = jsonResponse.array();
    QJsonValue v = jsonArr.first();
    acOut->setPlainText(v.toString());
    acReady = true;
    if (userReady) {
        acTxt = acOut->toPlainText().toStdString();
        userTxt = userOut->toPlainText().toStdString();
        compareOutputs();
    }
}

void OutputHandler::userProgTimedOut() {
    userOut->setPlainText("User program has timed out.");
    acOut->clear();
    comparisonFinished();
}

void OutputHandler::userProgCrashed() {
    userOut->setPlainText("An error has occurred\nduring execution.");
    acOut->clear();
    comparisonFinished();
}

void OutputHandler::userOutputReceived(const QByteArray& result) {
    userOut->document()->setPlainText(result);
    userReady = true;
    if (acReady) {
        acTxt = acOut->toPlainText().toStdString();
        userTxt = userOut->toPlainText().toStdString();
        compareOutputs();
    }
}

void OutputHandler::compareOutputs() {
    if (!acReady || !userReady)
        return;

    cleared = false;

    bool correct, userFinished = false, acFinished = false;
    std::stringstream userStream(userTxt), acStream(acTxt);

    userOut->setPlainText("");
    acOut->setPlainText("");
    int mismatches = 0;

    std::string userLine, acLine;
    int lineIdx = 0, filterRowsAdded = 0;
    acOut->disable();
    userOut->disable();

    if (filter) {
        acOut->enableFilter();
        userOut->enableFilter();
    }
    else {
        acOut->disableFilter();
        userOut->disableFilter();
    }

    while (!cleared) {
        lineIdx++;

        if (lineIdx % 50 == 0)
            QCoreApplication::processEvents();

        if (!userFinished && !std::getline(userStream, userLine))
            userFinished = true;
        if (!acFinished && !std::getline(acStream, acLine))
            acFinished = true;
        if (userFinished && acFinished)
            break;

        correct = (userLine == acLine);
        if (filter && correct)
            continue;
        if (correct) {
            userOut->setCurrentCharFormat(green);
            acOut->setCurrentCharFormat(green);
        }
        else {
            userOut->setCurrentCharFormat(red);
            acOut->setCurrentCharFormat(red);
            mismatches++;
            if (filter) {
                filterRowsAdded++;
                acOut->setBlockValue(filterRowsAdded, lineIdx);
                userOut->setBlockValue(filterRowsAdded, lineIdx);
            }
        }
        acOut->document()->setDocumentMargin(0);
        userOut->document()->setDocumentMargin(0);
        acOut->insertPlainText(" ");
        userOut->insertPlainText(" ");
        acOut->insertPlainText(acLine.c_str());
        userOut->insertPlainText(userLine.c_str());
        acOut->insertPlainText("\n");
        userOut->insertPlainText("\n");
    }
    if (filter && acOut->toPlainText().length() == 0) {
        acOut->disableFilter();
        userOut->disableFilter();
        acOut->setStyleSheet("QPlainTextEdit {background: rgb(153, 255, 153)} QScrollBar {background: rgb(184, 184, 184)}");
        userOut->setStyleSheet("QPlainTextEdit {background: rgb(153, 255, 153)} QScrollBar {background: rgb(184, 184, 184)}");
        acOut->setCurrentCharFormat(green);
        userOut->setCurrentCharFormat(green);
        acOut->appendPlainText("Accepted output matches\nuser output.");
        userOut->appendPlainText(userTxt.c_str());
    }
    else {
        acOut->setStyleSheet("QPlainTextEdit {background: white} QScrollBar {background: rgb(184, 184, 184)}");
        userOut->setStyleSheet("QPlainTextEdit {background: white} QScrollBar {background: rgb(184, 184, 184)}");
    }
    if (!mismatches) {
        resultLine->setStyleSheet("background: rgb(153, 255, 153); color: black; border: none;");
        QString result = "Outputs match! Runtime: ";
        result.append((std::to_string(executionTime)).c_str());
        result .append(" ms.");
        resultLine->setText(result);
    }
    else {
        resultLine->setStyleSheet("background: rgb(255, 102, 102); color: black; border: none;");
        QString result = "The outputs are not identical: number of mismatched lines is ";
        result.append(std::to_string(mismatches).c_str());
        result.append(". Runtime: ");
        result.append(std::to_string(executionTime).c_str());
        result.append("ms.");
        resultLine->setText(result);
    }
    acOut->enable();
    userOut->enable();
    acOut->update();
    userOut->update();
    outputResult(!mismatches);
}

void OutputHandler::toggleFilter() {
    filter = !filter;
    compareOutputs();
}
