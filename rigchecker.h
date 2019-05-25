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
    void fetchNextInput(const bool firstInput);
    int getIterations();
    void clear();
    void terminate();
    virtual void hide() {QDialog::hide(); codeEditor->hide();}
    ~RIGChecker();
private slots:
    void on_loadRIG_clicked();
    void on_iterationsLine_editingFinished();
    void setRIG();
    void on_check_clicked();
    void executionFailedReceived(const QByteArray&, bool crashed);
    void RIGOutputReceived(const QByteArray& output, const qint64);
    void loaderErrorReceived();
private:
    Ui::RIGChecker *ui;
    CodeEditor* codeEditor;
    int iterations;
    void showCodeEditor();
signals:
    void RIGCrash();
    void sendInput(const QByteArray& in);
    void RIGCheckStart();
    void terminateRIG();
};

#endif // RIGCHECKER_H
