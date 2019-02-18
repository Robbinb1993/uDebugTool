#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QDialog>

namespace Ui {
class texteditor;
}

class texteditor : public QDialog
{
    Q_OBJECT

public:
    explicit texteditor(QWidget *parent = 0);
    ~texteditor();

private:
    Ui::texteditor *ui;
};

#endif // TEXTEDITOR_H
