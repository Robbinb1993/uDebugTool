#ifndef INPUTTABLE_H
#define INPUTTABLE_H

#include <QTableWidget>
#include <QHeaderView>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QDebug>

class InputTable : public QTableWidget {
    Q_OBJECT

public:
    InputTable(QWidget*);
    void clear();
    void addInputs(const QByteArray&);
    void addTestcase(const QByteArray&);
    bool ready();
    QString getInput(const int idx);
private:
    QVector<QString> input;
    QVector<QString> inputID;
    int processedUntil, pendingInput;    
public slots:

private slots:
    void onTableRowClicked(const QModelIndex&);
signals:
    void sendInput(const QString&);
    void getTestcase(const QString&);
};

#endif // INPUTTABLE_H
