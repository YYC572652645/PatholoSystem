#include "newmoreslices.h"
#include "ui_newmoreslices.h"

NewMoreSlices::NewMoreSlices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newmoreslices)
{
    ui->setupUi(this);

    this->setWindowTitle("批量编码");

    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
}

NewMoreSlices::~NewMoreSlices()
{
    delete ui;
}

void NewMoreSlices::on_pushButtonOk_clicked()
{
    this->close();
}

void NewMoreSlices::on_pushButtonCancel_clicked()
{
    this->close();
}
