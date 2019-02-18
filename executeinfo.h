#ifndef EXECUTEINFO_H
#define EXECUTEINFO_H

#include <QObject>
#include <QMap>

class ExecuteInfo : public QObject {
    Q_OBJECT
public:
    ExecuteInfo(QObject* parent = nullptr) : QObject(parent) {
        executer["C"] = "";
        executer["C++"] = "";
        executer["C#"] = "";
        executer["Java"] = "java";
    }//constructor
    QString getExecuteInfo(const QString lang) const {
        return executer[lang];
    }//getExecuteInfo
private:
    QMap<QString, QString> executer;
};

#endif // EXECUTEINFO_H
