#include "newslices.h"
#include "ui_newslices.h"
#include <QDateTime>

/*******************   构造函数    ***********************/
NewSlices::NewSlices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newslices)
{
    ui->setupUi(this);

    this->setWindowTitle("标本登记");

    this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
}

/*******************   析构函数    ***********************/
NewSlices::~NewSlices()
{
    delete ui;
}

/*******************   确定按钮    ***********************/
void NewSlices::on_pushButtonOk_clicked()
{
    SYSTEMDATA->codeTypeSelectData();
    QMap<QString, QString>mapData = SYSTEMDATA->getCodeBeginSnSetInfo();

    RegisterInfo data;

    //序号
    {
        int setBeginNumber = mapData["PCodeBeginSn"].toInt();
        int maxId = registerData.selectMaxId();

        if(maxId >= setBeginNumber)
        {
            data.pCode = QString::number(maxId + 1);
        }
        else
        {
            data.pCode = QString::number(setBeginNumber);
        }
    }

    //病理号
    {
        QDate date = QDate::currentDate();

        QString str;
        str += mapData["CustomPrefix"];
        if(0 != mapData["UsePrefix"].toInt())
        {
            if(ui->comboBoxType->currentIndex() >= dataInfo.size()) return;
            str += dataInfo[ui->comboBoxType->currentIndex()].codeTypeAbbr;
        }

        const static int HUNDREDTIME = 100;
        if(0 != mapData["UseYear"].toInt())
        {
            if(mapData["YearType"].toInt() == 2)
            {
                str += QString::number((date.year() % HUNDREDTIME));
            }
            else
            {
                str += QString::number((date.year()));
            }
        }

        if(0 != mapData["UseMonth"].toInt());
        {
            str += QString::number((date.month()));
        }

        if(0 != mapData["UseDay"].toInt());
        {
            str += QString::number((date.day()));
        }

        str += mapData["Spin"];


        for(int i = 0; i < mapData["SnLength"].toInt() - data.pCode.length(); i++)
        {
            str += "0";
        }

        str += data.pCode;

        data.sn = str;
    }

    data.printQuantity = QString::number(ui->spinBoxPrintNumber->value());
    data.printed       = QString::number(ui->checkBoxPrint->isChecked());
    data.createTime    = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    data.userId        = "1111";

    registerData.insertData(data);

    this->close();
}

/*******************   取消按钮    ***********************/
void NewSlices::on_pushButtonCancel_clicked()
{
    this->close();
}

/*******************   显示对话框    ***********************/
void NewSlices::showDialog()
{
    ui->comboBoxType->clear();

    SYSTEMDATA->codeTypeSelectData();

    dataInfo = SYSTEMDATA->getCodeTypeInfo();

    for(int i = 0; i < dataInfo.size(); i ++)
    {
        ui->comboBoxType->addItem(dataInfo[i].codeTypeAbbr +" "+ dataInfo[i].codeTypeName);
    }

    this->show();
}
