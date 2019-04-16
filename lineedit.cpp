#include "lineedit.h"

LineEdit::LineEdit(QWidget *parent) : QLineEdit(parent) {}

void LineEdit::mousePressEvent(QMouseEvent*) {
    setText("");
}
