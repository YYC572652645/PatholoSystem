#include "newmoreimmuneslice.h"
#include "ui_newmoreimmuneslice.h"
#include "globaldef.h"
#include "tabsystemset/tabsystemdata.h"

/*******************   构造函数           ***********************/
NewMoreImmuneSlice::NewMoreImmuneSlice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newmoreimmuneslice)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);

    this->setWindowTitle("批量新增");
}

/*******************   析构函数            ***********************/
NewMoreImmuneSlice::~NewMoreImmuneSlice()
{
    delete ui;
}

/*******************   显示窗口            ***********************/
void NewMoreImmuneSlice::showWidget()
{
    this->setComboBoxInfo();
    this->show();
}

/*******************   确定按钮            ***********************/
void NewMoreImmuneSlice::on_pushButtonOk_clicked()
{
    QString number = subFinger(ui->lineEditBlNumber->text());

    for(int i = 0; i < ui->spinBoxNumber->value(); i ++)
    {
        DataImmuneSlice data;

        QString codeNumber = ui->lineEditBlNumber->text();
        if(ui->radioButtonAddBLNumber->isChecked())
        {
            if(i < 10)
            {
                codeNumber += "-" + tr("0%1").arg(i + 1);
            }
            else
            {
                codeNumber += "-" + QString::number(i + 1);
            }
        }
        else if(ui->radioButtonAddBlAndCode->isChecked())
        {
            codeNumber = codeNumber.left(codeNumber.size() - number.size());

            codeNumber += QString::number(number.toInt() + i + 1) + "-01";
        }
        else if(ui->radioButtonAddBlAndCancel->isChecked())
        {
            codeNumber = codeNumber.left(codeNumber.size() - number.size());

            codeNumber += QString::number(number.toInt() + i + 1);
        }
        else if(ui->radioButtonAddAll->isChecked())
        {
            codeNumber = codeNumber.left(codeNumber.size() - number.size());

            codeNumber += QString::number(number.toInt() + i + 1);

            if(i < 10)
            {
                codeNumber += "-" + tr("0%1").arg(i + 1);
            }
            else
            {
                codeNumber += "-" + QString::number(i + 1);
            }
        }

        data.embedCode     = codeNumber;
        data.sectionCode   = codeNumber;
        data.printNum      = QString::number(ui->spinBoxPrintNumber->value());
        data.stainTypeName = ui->comboBoxColorType->currentText();
        data.staining      = ui->comboBoxColorIndex->currentText();
        data.cloneNumber   = ui->lineEditClone->text();
        data.sectioner     = ui->comboBoxQPPeople->currentText();
        data.sectionTime   = ui->dateEditQPTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
        data.stainer       = ui->comboBoxRSPeople->currentText();
        data.stainTime     = ui->dateEditRSTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
        data.printed       = "0";

        IMMUNESLICEDATA->insertData(data);
    }

    emit sendSelect();

    this->close();
}

/*******************   取消按钮            ***********************/
void NewMoreImmuneSlice::on_pushButtonCancel_clicked()
{
    this->close();
}

/*******************   去字母              ***********************/
QString NewMoreImmuneSlice::subFinger(QString number)
{
    int  count = 0;
    for(int i = number.size() - 1; i >= 0; i --)
    {
        if(number.at(i).isNumber())
        {
            count ++;
        }
        else
        {
            break;
        }
    }

    return number.right(count);
}

/*******************   设置信息             ***********************/
void NewMoreImmuneSlice::setComboBoxInfo()
{
    ui->comboBoxColorType->clear();
    ui->comboBoxColorIndex->clear();

    int count = SYSTEMDATA->selectStainTypeData(GLOBALDEF::FIRSTTYPE);

    if(count == GLOBALDEF::ERROR) return;

    QMap<QString, QString> mapData =  SYSTEMDATA->getStainTypeName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        ui->comboBoxColorType->addItem(mapData[mapData.keys().at(i)]);
    }

    mapData.clear();

    count = SYSTEMDATA->selectStainingData(GLOBALDEF::FIRSTTYPE);

    if(count == GLOBALDEF::ERROR) return;

    mapData =  SYSTEMDATA->getStainingName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        ui->comboBoxColorIndex->addItem(mapData[mapData.keys().at(i)]);
    }
}

/*******************   按钮点击             ***********************/
void NewMoreImmuneSlice::keyPressEvent(QKeyEvent * event)
{
    static QString strNumber;
    if(event->key() == Qt::Key_Return)
    {
        ui->lineEditBlNumber->setText(strNumber);
        strNumber.clear();
    }
    else
    {
        strNumber += event->text();
    }
}

