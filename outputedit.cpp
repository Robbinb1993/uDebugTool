#include "outputedit.h"

void QOutputEdit::mouseReleaseEvent(QMouseEvent* event) {
    QTextEdit::mouseReleaseEvent(event);
    qDebug() << "clicked";


}
