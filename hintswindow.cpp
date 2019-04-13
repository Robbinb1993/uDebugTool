#include "hintswindow.h"
#include "ui_hintswindow.h"

HintsWindow::HintsWindow(QWidget *parent) :
    QDialog(nullptr),
    ui(new Ui::HintsWindow) {
    ui->setupUi(this);
    setWindowTitle("Hints");
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->hintText->viewport()->setCursor(Qt::ArrowCursor);
    ui->hintText->setOpenExternalLinks(true);
    connect(ui->hintTable, SIGNAL(sendInfo(const QString&)), this, SLOT(changeHint(const QString&)));
    connect(ui->hintTable, SIGNAL(getInfo(const QString&)), parent, SLOT(reqHint(const QString&)));
    connect(ui->hintTable, SIGNAL(ready()), parent, SLOT(hintFetchingFinished()));
}//constructor

HintsWindow::~HintsWindow() {
    delete ui;
}//destructor

void HintsWindow::clear() {
    ui->hintText->clear();
    ui->hintTable->resetting = true;
}//clear

void HintsWindow::hintsReceived(const QByteArray& result) {
    ui->hintTable->addEntries(result);
}//hintsReceived

void HintsWindow::hintReceived(const QByteArray& result) {
    ui->hintTable->addInfo(result);
}//hintsReceived

void HintsWindow::changeHint(const QString& hint) {
    ui->hintText->setText(hint);
}//changeHint
