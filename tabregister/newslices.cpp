#include "newslices.h"
#include "ui_newslices.h"

newslices::newslices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newslices)
{
    ui->setupUi(this);
}

newslices::~newslices()
{
    delete ui;
}
