#include "newnormalslice.h"
#include "ui_newnormalslice.h"

/*******************   构造函数    ***********************/
NewNormalSlice::NewNormalSlice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newnormalslice)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);

    this->setWindowTitle("新建切片");
}

/*******************   析构函数    ***********************/
NewNormalSlice::~NewNormalSlice()
{
    delete ui;
}

/*******************   显示界面    ***********************/
void NewNormalSlice::showWidget()
{
    ui->dateEditQPTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditQPTime->setDateTime(QDateTime::currentDateTime());

    ui->dateEditRSTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditRSTime->setDateTime(QDateTime::currentDateTime());

    this->show();
}

/*******************   显示界面    ***********************/
void NewNormalSlice::showWidget(DataNormalSlice data)
{
    ui->lineEditCodeNumber->setText(data.embedCode);
    ui->spinBoxPrintNumber->setValue(data.printNum.toInt());
    ui->lineEditColorType->setText(data.stainTypeName);
    ui->lineEditColorIndex->setText(data.staining);
    ui->lineEditOther->setText(data.other);
    ui->comboBoxQPPeople->setCurrentText(data.sectioner);

    ui->dateEditQPTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditQPTime->setDateTime(QDateTime::fromString(data.sectionTime, "yyyy-MM-dd hh:mm:ss"));
    ui->comboBoxRSPeople->setCurrentText(data.stainer);

    ui->dateEditRSTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditRSTime->setDateTime(QDateTime::fromString(data.stainTime, "yyyy-MM-dd hh:mm:ss"));

    this->show();
}

/*******************   确定按钮    ***********************/
void NewNormalSlice::on_pushButtonOk_clicked()
{
    DataNormalSlice data;

    data.embedCode     = ui->lineEditCodeNumber->text();
    data.sectionCode   = ui->lineEditCodeNumber->text();
    data.printNum      = QString::number(ui->spinBoxPrintNumber->value());
    data.stainTypeName = ui->lineEditColorType->text();
    data.staining      = ui->lineEditColorIndex->text();
    data.other         = ui->lineEditOther->text();
    data.sectioner     = ui->comboBoxQPPeople->currentText();
    data.sectionTime   = ui->dateEditQPTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    data.stainer       = ui->comboBoxRSPeople->currentText();
    data.stainTime     = ui->dateEditRSTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    data.printed       = "0";

    NORMALSLICEDATA->insertData(data);

    emit sendSelect();

    this->close();
}

/*******************   取消按钮    ***********************/
void NewNormalSlice::on_pushButtonCancel_clicked()
{
    this->close();
}

/*******************   按钮点击    ***********************/
void NewNormalSlice::keyPressEvent(QKeyEvent * event)
{
    static QString strNumber;
    if(event->key() == Qt::Key_Return)
    {
        ui->lineEditCodeNumber->setText(strNumber);
        strNumber.clear();
    }
    else
    {
        strNumber += event->text();
    }
}
