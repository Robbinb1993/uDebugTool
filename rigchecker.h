#ifndef RIGCHECKER_H
#define RIGCHECKER_H

#include <QDialog>
#include "codeeditor.h"

namespace Ui {
class RIGChecker;
}

class RIGChecker : public QDialog
{
    Q_OBJECT

public:
    explicit RIGChecker(QWidget *parent = 0);
    void fetchNextInput();
    int getIterations();
    void clear();
    ~RIGChecker();

protected:
    bool eventFilter(QObject *, QEvent *);

private slots:
    void on_loadRIG_clicked();
    void on_iterationsLine_editingFinished();
    void setRIG(const QString& pName, const QString& lang);
    void on_check_clicked();
    void procFinished(int, QProcess::ExitStatus);

private:
    Ui::RIGChecker *ui;
    CodeEditor* codeEditor;
    QString programPath, currLang;
    QProcess* proc;
    int iterations;

signals:
    void RIGCrash();
    void sendInput(const QByteArray& in);
    void RIGCheckStart();
    void windowClosed();
};

#endif // RIGCHECKER_H
