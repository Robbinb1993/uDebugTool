#include "texteditor.h"
#include "ui_texteditor.h"

texteditor::texteditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::texteditor)
{
    ui->setupUi(this);
}

texteditor::~texteditor()
{
    delete ui;
}
