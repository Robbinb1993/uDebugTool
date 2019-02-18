#include "inputchainchecker.h"
#include "ui_inputchainchecker.h"

InputChainChecker::InputChainChecker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputChainChecker)
{
    ui->setupUi(this);
    setWindowTitle("Input Chain Check");
    setWindowModality(Qt::WindowModal);
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    installEventFilter(this);
}

InputChainChecker::~InputChainChecker() {
    delete ui;
}

bool InputChainChecker::eventFilter(QObject *, QEvent* e) {
    if (e->type() == QEvent::Type::HideToParent)
        windowClosed();
    else if (e->type() == QEvent::Type::Show)
        ui->closeButton->hide();
    return false;
}//eventFilter

void InputChainChecker::progress(const int idx, const int tot) {
    ui->progressBar->setValue((tot == 0 ? 100 : (idx / double(tot)) * 100));
    QString txt = "";
    if (idx == tot) {
        txt.append("Output is correct for all inputs.");
        ui->closeButton->show();
    }//if
    else {
        txt.append(std::to_string(idx).c_str());
        txt.append(" of ");
        txt.append(std::to_string(tot).c_str());
        txt.append(" inputs have been checked.");
    }//else
    qDebug() << "TEST";
    ui->info->setText(txt);
}//progress

void InputChainChecker::mismatchFound(const int idx) {
    ui->progressBar->setValue(0);
    QString txt = "";
    txt.append("A mismatch has been found in input entry ");
    txt.append(std::to_string(idx).c_str());
    txt.append(".");
    ui->info->setText(txt);
    ui->closeButton->show();
}//mismatchFound

void InputChainChecker::chainTerminated() {
    ui->closeButton->show();
}//chainTerminated

void InputChainChecker::on_closeButton_clicked() {
    close();
}//on_closeButton_clicked
