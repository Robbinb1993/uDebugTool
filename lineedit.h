#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>
#include <QDebug>

class LineEdit : public QLineEdit {
    Q_OBJECT
    public:
        explicit LineEdit(QWidget *parent = nullptr);
    protected:
        void mousePressEvent(QMouseEvent*);
};

#endif // LINEEDIT_H
