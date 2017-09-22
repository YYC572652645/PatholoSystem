#include "newmorenormalslice.h"
#include "ui_newmorenormalslice.h"

/*******************   构造函数            ***********************/
NewMoreNormalSlice::NewMoreNormalSlice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newmorenormalslice)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);

    this->setWindowTitle("批量新增");
}

/*******************   析构函数            ***********************/
NewMoreNormalSlice::~NewMoreNormalSlice()
{
    delete ui;
}

/*******************   显示窗口            ***********************/
void NewMoreNormalSlice::showWidget()
{
    this->show();
}

/*******************   确定按钮            ***********************/
void NewMoreNormalSlice::on_pushButtonOk_clicked()
{
    QString number = subFinger(ui->lineEditBlNumber->text());

    for(int i = 0; i < ui->spinBoxNumber->value(); i ++)
    {
        DataNormalSlice data;

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
        data.stainTypeName = ui->lineEditRSType->text();
        data.staining      = ui->lineEditRSIndex->text();
        data.other         = ui->lineEditOther->text();
        data.sectioner     = ui->comboBoxQPPeople->currentText();
        data.sectionTime   = ui->dateEditQPTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
        data.stainer       = ui->comboBoxRSPeople->currentText();
        data.stainTime     = ui->dateEditRSTime->dateTime().toString("yyyy-MM-dd hh:mm:ss");
        data.printed       = "0";

        NORMALSLICEDATA->insertData(data);
    }

    emit sendSelect();

    this->close();
}

/*******************   取消按钮            ***********************/
void NewMoreNormalSlice::on_pushButtonCancel_clicked()
{
    this->close();
}

/*******************   去字母    ***********************/
QString NewMoreNormalSlice::subFinger(QString number)
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
