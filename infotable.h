#ifndef INFOTABLE_H
#define INFOTABLE_H

#include <QTableWidget>
#include <QHeaderView>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QDebug>
#include <QFontDatabase>
#include <QDir>

class InfoTable : public QTableWidget {
    Q_OBJECT

public:
    InfoTable(QWidget*, const QString&);
    void clear();
    void addEntries(const QByteArray&);
    void addInfo(const QByteArray&);
    bool isReady();
    QString requestInfo(const int idx);
    bool resetting;
private:
    QVector<QString> info;
    QVector<QString> infoID;
    QString infoType;
    bool finishedFetching;
    int processedUntil, pendingEntry;
private slots:
    void onTableRowClicked(const QModelIndex&);
signals:
    void sendInfo(const QString&);
    void getInfo(const QString&);
    void ready();
};

#endif // INFOTABLE_H
