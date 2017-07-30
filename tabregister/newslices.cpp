#include "newslices.h"
#include "ui_newslices.h"

NewSlices::NewSlices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newslices)
{
    ui->setupUi(this);

    this->setWindowTitle("标本登记");

    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
}

NewSlices::~NewSlices()
{
    delete ui;
}

void NewSlices::on_pushButtonOk_clicked()
{
    registerData.insertData();

    this->close();
}

void NewSlices::on_pushButtonCancel_clicked()
{
    this->close();
}
