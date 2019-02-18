#ifndef OUTPUTEDIT_H
#define OUTPUTEDIT_H

#include <QTextEdit>
#include <QMouseEvent>
#include <qDebug>
#include <QWidget>

class QOutputEdit : public QTextEdit
{
    Q_OBJECT
public:
    QOutputEdit(QWidget *parent = 0) : QTextEdit(parent) {}
protected:
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // OUTPUTEDIT_H
