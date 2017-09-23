#include "newspecialslice.h"
#include "ui_newspecialslice.h"
#include "globaldef.h"
#include "tabsystemset/tabsystemdata.h"

/*******************   构造函数    ***********************/
NewSpecialSlice::NewSpecialSlice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newspecialslice)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);

    this->setWindowTitle("新建切片");
}

/*******************   析构函数    ***********************/
NewSpecialSlice::~NewSpecialSlice()
{
    delete ui;
}

/*******************   显示界面    ***********************/
void NewSpecialSlice::showWidget()
{
    this->setComboBoxInfo();

    ui->dateEditQPTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditQPTime->setDateTime(QDateTime::currentDateTime());

    ui->dateEditRSTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditRSTime->setDateTime(QDateTime::currentDateTime());

    this->show();
}

/*******************   显示界面    ***********************/
void NewSpecialSlice::showWidget(DataSpecialSlice data)
{
    this->setComboBoxInfo();

    ui->lineEditCodeNumber->setText(data.embedCode);
    ui->spinBoxPrintNumber->setValue(data.printNum.toInt());
    ui->comboBoxColorType->setCurrentText(data.stainTypeName);
    ui->comboBoxColorIndex->setCurrentText(data.staining);
    ui->lineEditClone->setText(data.cloneNumber);
    ui->comboBoxQPPeople->setCurrentText(data.sectioner);

    ui->dateEditQPTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditQPTime->setDateTime(QDateTime::fromString(data.sectionTime, "yyyy-MM-dd hh:mm:ss"));
    ui->comboBoxRSPeople->setCurrentText(data.stainer);

    ui->dateEditRSTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateEditRSTime->setDateTime(QDateTime::fromString(data.stainTime, "yyyy-MM-dd hh:mm:ss"));

    this->show();
}

/*******************   确定按钮    ***********************/
void NewSpecialSlice::on_pushButtonOk_clicked()
{
    DataSpecialSlice data;

    data.embedCode     = ui->lineEditCodeNumber->text();
    data.sectionCode   = ui->lineEditCodeNumber->text();
    data.printNum      = QString::number(ui->spinBoxPrintNumber->value());
    data.stainTypeName = ui->comboBoxColorType->currentText();
    data.staining      = ui->comboBoxColorIndex->currentText();
    data.cloneNumber   = ui->lineEditClone->text();
    data.sectioner     = ui->comboBoxQPPeople->currentText();
    data.sectionTime   = ui->dateEditQPTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    data.stainer       = ui->comboBoxRSPeople->currentText();
    data.stainTime     = ui->dateEditRSTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    data.printed       = "0";

    SPECIALSLICEDATA->insertData(data);

    emit sendSelect();

    this->close();
}

/*******************   取消按钮    ***********************/
void NewSpecialSlice::on_pushButtonCancel_clicked()
{
    this->close();
}

/*******************   设置信息    ***********************/
void NewSpecialSlice::setComboBoxInfo()
{
    ui->comboBoxColorType->clear();
    ui->comboBoxColorIndex->clear();

    int count = SYSTEMDATA->selectStainTypeData(GLOBALDEF::SECONDTYPE);  //查询标本类别信息

    if(count == GLOBALDEF::ERROR) return;

    QMap<QString, QString> mapData =  SYSTEMDATA->getStainTypeName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        ui->comboBoxColorType->addItem(mapData[mapData.keys().at(i)]);
    }

    mapData.clear();

    count = SYSTEMDATA->selectStainingData(GLOBALDEF::SECONDTYPE);

    if(count == GLOBALDEF::ERROR) return;

    mapData =  SYSTEMDATA->getStainingName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        ui->comboBoxColorIndex->addItem(mapData[mapData.keys().at(i)]);
    }
}
