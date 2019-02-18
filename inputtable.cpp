#include "inputtable.h"

InputTable::InputTable(QWidget *parent = 0) : QTableWidget(parent) {
    connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(onTableRowClicked(const QModelIndex&)));
    setColumnCount(3);
    setHorizontalHeaderItem(0, new QTableWidgetItem(QString("User")));
    setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Date")));
    setHorizontalHeaderItem(2, new QTableWidgetItem(QString("Votes")));
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    setCornerButtonEnabled(0);
    setAlternatingRowColors(1);
    resizeRowsToContents();
    setHorizontalScrollMode(QTableView::ScrollPerPixel);
    setVerticalScrollMode(QTableView::ScrollPerPixel);
    horizontalHeader()->setStyleSheet("QHeaderView::section { color: white; background: #242e33; padding: 3px; text-align: center;}");
    verticalHeader()->setStyleSheet("QHeaderView::section { color: white; background: #242e33; padding: 3px; text-align: center;}");
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setHighlightSections(false);
    verticalHeader()->setHighlightSections(false);
}//constructor

void InputTable::clear() {
    processedUntil = 0;
    pendingInput = -1;
    setRowCount(0);
    input.clear();
    inputID.clear();
}//clear

bool InputTable::ready() {
    return (processedUntil > inputID.size() - 1);
}//ready

QString InputTable::getInput(const int idx) {
    return input[idx];
}//getInput

void InputTable::addInputs(const QByteArray& inputs) {
    clear();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(inputs);
    QJsonObject jsonObj = jsonResponse.object();
    QJsonObject::iterator it;
    if ((it = jsonObj.find("error")) != jsonObj.end()) {
        QString message = "The problem has not been found: ";
        message += (*it).toObject()["message"].toString();
        message += ".";
        QMessageBox::information(this, tr("Message"), tr(message.toUtf8()));
        return;
    }//if
    QJsonArray jsonArr = jsonResponse.array();
    foreach (const QJsonValue& v, jsonArr) {
        insertRow(rowCount());
        QJsonObject jsonObj = v.toObject();
        QString votes = jsonObj["Votes"].toString();
        if (votes.length() == 0)
            votes = "0";
        setItem(rowCount() - 1, 0, new QTableWidgetItem(jsonObj["user"].toString()));
        setItem(rowCount() - 1, 1, new QTableWidgetItem(jsonObj["Date"].toString()));
        setItem(rowCount() - 1, 2, new QTableWidgetItem(votes));
        input.push_back("Test case will be fetched.");
        inputID.push_back(jsonObj["id"].toString());
    }//foreach
    if (jsonArr.empty())
        QMessageBox::information(this, tr("Message"), tr("No inputs exist for this problem."));
    if (!(inputID.empty()))
        getTestcase(inputID[processedUntil]);
}//addInputs

void InputTable::addTestcase(const QByteArray& testcase) {
    QJsonDocument jsonResponse = QJsonDocument::fromJson(testcase);
    QJsonArray jsonArr = jsonResponse.array();    
    QJsonValue v = jsonArr.first();
    input[processedUntil] = v.toString();
    if (processedUntil == pendingInput)
        emit(sendInput(input[processedUntil]));
    if (processedUntil < inputID.size() - 1)
        getTestcase(inputID[++processedUntil]);
    else
        processedUntil++;
}//addTestcase

void InputTable::onTableRowClicked(const QModelIndex& idx) {
    pendingInput = idx.row();
    emit(sendInput(input[idx.row()]));
}//onTableRowClicked
