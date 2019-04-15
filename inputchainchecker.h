#ifndef INPUTCHAINCHECKER_H
#define INPUTCHAINCHECKER_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class InputChainChecker;
}

class InputChainChecker : public QDialog
{
    Q_OBJECT

public:
    explicit InputChainChecker(QWidget *parent = nullptr);
    ~InputChainChecker();
    void mismatchFound(const int idx);
    void progress(const int idx, const int tot);
protected:
    bool eventFilter(QObject *, QEvent *);
private:
    Ui::InputChainChecker *ui;
signals:
    void windowClosed();
private slots:
    void on_closeButton_clicked();
};

#endif // INPUTCHAINCHECKER_H
