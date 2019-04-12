#include <QDebug>
#include "outputhandler.h"

OutputHandler::OutputHandler(QObject *parent, Editor * const ac, Editor * const your, QLineEdit * const line) :
QObject(parent), acOut(ac), yourOut(your), resultLine(line) {
    acOut->setReadOnly(1);
    acOut->viewport()->setCursor(Qt::ArrowCursor);
    acOut->setLineWrapMode(QPlainTextEdit::NoWrap);
    acOut->document()->setDocumentMargin(6);
    acOut->disableHighlight();
    yourOut->setReadOnly(1);
    yourOut->viewport()->setCursor(Qt::ArrowCursor);
    yourOut->setLineWrapMode(QPlainTextEdit::NoWrap);
    yourOut->document()->setDocumentMargin(6);
    yourOut->disableHighlight();
    acReady = yourReady = cleared = filter = false;
    green.setBackground(QBrush(QColor(153, 255, 153)));
    red.setBackground(QBrush(QColor(255, 102, 102)));
    white.setBackground(QBrush(QColor(255, 255, 255)));
}//constructor

void OutputHandler::setExecutionTime(const int t) {
    executionTime = t;
}//setExecutionTime

void OutputHandler::clear() {
    acReady = yourReady = false;
    cleared = true;
    acOut->document()->setDocumentMargin(6);
    yourOut->document()->setDocumentMargin(6);
    acOut->setCurrentCharFormat(white);
    acOut->disableFilter();
    acOut->clear();
    yourOut->setCurrentCharFormat(white);
    yourOut->disableFilter();
    yourOut->clear();

    resultLine->clear();
    resultLine->setStyleSheet("QLabel{background: white;}");
    acOut->setStyleSheet("QPlainTextEdit{background: white;}");
    yourOut->setStyleSheet("QPlainTextEdit{background: white;}");
}//clear

void OutputHandler::enableChainCheck() {
    chainCheck = true;
}//enableChainCheck

void OutputHandler::disableChainCheck() {
    chainCheck = false;
}//disableChainCheck

void OutputHandler::acOutputErrorOccurred() {
    acOut->setPlainText("An error has occurred\nwhile fetching the output.");
}//acOutputErrorOccurred

void OutputHandler::acOutputReceived(const QByteArray& result) {
    QJsonDocument jsonResponse = QJsonDocument::fromJson(result);
    QJsonArray jsonArr = jsonResponse.array();
    QJsonValue v = jsonArr.first();
    acOut->setPlainText(v.toString());
    acReady = true;
    if (yourReady) {
        acTxt = acOut->toPlainText().toStdString();
        yourTxt = yourOut->toPlainText().toStdString();
        compareOutputs();
    }//if
}//acOutputReceived

void OutputHandler::yourProgTimedOut() {
    yourOut->setPlainText("Your program has timed out.");
    comparisonFinished();
}//yourProcTimedOut

void OutputHandler::yourProgCrashed() {
    yourOut->setPlainText("A runtime error occured.");
    comparisonFinished();
}//yourProgCrashed

void OutputHandler::yourOutputReceived(const QByteArray& result) {   
    yourOut->document()->setPlainText(result);
    yourReady = true;
    if (acReady) {
        acTxt = acOut->toPlainText().toStdString();
        yourTxt = yourOut->toPlainText().toStdString();
        compareOutputs();
    }//if
}//onProgFinished

void OutputHandler::compareOutputs() {
    if (!acReady || !yourReady)
        return;

    cleared = false;

    bool correct, yourFinished = false, acFinished = false;
    std::stringstream yourStream(yourTxt), acStream(acTxt);
    yourOut->setPlainText("");
    acOut->setPlainText("");
    int mismatches = 0;

    std::string yourLine, acLine;
    int lineIdx = 0, filterRowsAdded = 0;
    acOut->disable();
    yourOut->disable();

    if (filter) {
        acOut->enableFilter();
        yourOut->enableFilter();
    }//if
    else {
        acOut->disableFilter();
        yourOut->disableFilter();
    }//else

    while (!cleared) {
        lineIdx++;
        if (!yourFinished && !std::getline(yourStream, yourLine))
            yourFinished = true;
        if (!acFinished && !std::getline(acStream, acLine))
            acFinished = true;
        if (yourFinished && acFinished)
            break;

        correct = (yourLine == acLine);
        if (filter && correct)
            continue;
        if (correct)
            yourOut->setCurrentCharFormat(green), acOut->setCurrentCharFormat(green);
        else {
            yourOut->setCurrentCharFormat(red), acOut->setCurrentCharFormat(red), mismatches++;
            if (filter) {
                filterRowsAdded++;
                acOut->setBlockValue(filterRowsAdded, lineIdx);
                yourOut->setBlockValue(filterRowsAdded, lineIdx);
            }//if
        }//else        
        acOut->document()->setDocumentMargin(0);
        yourOut->document()->setDocumentMargin(0);
        acOut->insertPlainText(" ");
        yourOut->insertPlainText(" ");
        acOut->insertPlainText(acLine.c_str());
        yourOut->insertPlainText(yourLine.c_str());
        acOut->insertPlainText("\n");
        yourOut->insertPlainText("\n");
    }//while
    if (filter && acOut->toPlainText().length() == 0) {
        acOut->disableFilter();
        yourOut->disableFilter();
        acOut->setStyleSheet("QPlainTextEdit {background: rgb(153, 255, 153)} QScrollBar {background: rgb(184, 184, 184)}");
        yourOut->setStyleSheet("QPlainTextEdit {background: rgb(153, 255, 153)} QScrollBar {background: rgb(184, 184, 184)}");
        acOut->setCurrentCharFormat(green);
        yourOut->setCurrentCharFormat(green);
        acOut->appendPlainText("Accepted output matches\nyour output.");
        yourOut->appendPlainText(yourTxt.c_str());
    }//if
    else {
        acOut->setStyleSheet("QPlainTextEdit {background: white} QScrollBar {background: rgb(184, 184, 184)}");
        yourOut->setStyleSheet("QPlainTextEdit {background: white} QScrollBar {background: rgb(184, 184, 184)}");
    }//else
    if (!mismatches) {
        resultLine->setStyleSheet("background: rgb(153, 255, 153); color: black; border: none;");
        QString result = "Outputs match! Runtime: ";
        result.append((std::to_string(executionTime)).c_str());
        result .append(" ms.");
        resultLine->setText(result);
    }//if
    else {
        resultLine->setStyleSheet("background: rgb(255, 102, 102); color: black; border: none;");
        QString result = "The outputs are not identical: number of mismatched lines is ";
        result.append(std::to_string(mismatches).c_str());
        result.append(". Runtime: ");
        result.append(std::to_string(executionTime).c_str());
        result.append("ms.");
        resultLine->setText(result);
    }//else
    acOut->enable();
    yourOut->enable();
    acOut->update();
    yourOut->update();

    if (chainCheck) {
        if (!mismatches) {
            chainResult(true);
            return;
        }//if
        chainResult(false);
    }//if
    else
        comparisonFinished();
}//compareOutputs

void OutputHandler::toggleFilter() {
    filter = !filter;
    compareOutputs();
}//toggleFilter
