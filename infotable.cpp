#include "infotable.h"

InfoTable::InfoTable(QWidget *parent, const QString& info) : QTableWidget(parent) {
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

    infoType = info;
}//constructor

void InfoTable::clear() {
    processedUntil = 0;
    resetting = false;
    pendingEntry = -1;
    setRowCount(0);
    info.clear();
    infoID.clear();
}//clear

bool InfoTable::isReady() {
    return (processedUntil > infoID.size() - 1);
}//isReady

QString InfoTable::requestInfo(const int idx) {
    return info[idx];
}//requestInfo

void InfoTable::addEntries(const QByteArray& entries) {
    clear();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(entries);
    QJsonObject jsonObj = jsonResponse.object();
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

        info.push_back(infoType + " will be fetched.");
        infoID.push_back(jsonObj["id"].toString());
    }//foreach

    if (!(infoID.empty()))
        getInfo(infoID[processedUntil]);
    else
        ready();
}//addEntries

void InfoTable::addInfo(const QByteArray& response) {
    if (resetting)
        return;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
    QJsonArray jsonArr = jsonResponse.array();    
    QJsonValue v = jsonArr.first();
    info[processedUntil] = v.toString();
    if (processedUntil == pendingEntry)
        emit(sendInfo(info[processedUntil]));
    if (processedUntil < infoID.size() - 1)
        getInfo(infoID[++processedUntil]);
    else {
        processedUntil++;
        ready();
    }//else
}//addInfo

void InfoTable::onTableRowClicked(const QModelIndex& idx) {
    pendingEntry = idx.row();
    emit(sendInfo(info[idx.row()]));
}//onTableRowClicked
