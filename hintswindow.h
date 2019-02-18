#ifndef HINTSWINDOW_H
#define HINTSWINDOW_H

#include <QDialog>

namespace Ui {
class HintsWindow;
}

class HintsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HintsWindow(QWidget *parent = 0);
    void clear();
    ~HintsWindow();

private:
    Ui::HintsWindow *ui;

private slots:
    void hintsReceived(const QByteArray&);
    void hintReceived(const QByteArray&);
    void changeHint(const QString& hint);


};

#endif // HINTSWINDOW_H
