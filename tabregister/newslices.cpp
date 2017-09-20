#include "newslices.h"
#include "ui_newslices.h"
#include <QDateTime>
#include "config/qreadini.h"

/*******************   构造函数    ***********************/
NewSlices::NewSlices(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newslices)
{
    ui->setupUi(this);

    this->setWindowTitle("标本登记");

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
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
        int setBeginNumber = mapData[PCODEBEGINSN].toInt();
        int maxId = registerData.selectMaxId();

        if(INICONFIG->getStartNumber().toInt() > maxId)
        {
            data.pCode = QString::number(setBeginNumber);
        }
        else
        {
            data.pCode = QString::number(maxId + 1);
        }

        INICONFIG->writeIni(data.pCode);
    }

    //病理号
    {
        QDate date = QDate::currentDate();

        QString str;
        str += mapData[CUSTOMPREFIX];
        if(0 != mapData[USERPREFIX].toInt())
        {
            if(ui->comboBoxType->currentIndex() >= dataInfo.size()) return;
            str += dataInfo[ui->comboBoxType->currentIndex()].codeTypeAbbr;
        }

        const static int HUNDREDTIME = 100;
        if(0 != mapData[USEYEAR].toInt())
        {
            if(mapData[YEARTYPE].toInt() == 2)
            {
                str += QString::number((date.year() % HUNDREDTIME));
            }
            else
            {
                str += QString::number((date.year()));
            }
        }

        if(0 != mapData[USEMONTH].toInt());
        {
            str += QString::number((date.month()));
        }

        if(0 != mapData[USEDAY].toInt());
        {
            str += QString::number((date.day()));
        }

        str += mapData[SPIN];

        for(int i = 0; i < mapData[SNLENGTH].toInt() - data.pCode.length(); i++)
        {
            str += "0";
        }

        str += data.pCode;

        data.sn = str;
    }

    //打印数量
    data.printQuantity = QString::number(ui->spinBoxPrintNumber->value());

    //是否打印
    data.printed       = QString::number(ui->checkBoxPrint->isChecked());

    if(ui->checkBoxPrint->isChecked())
    {
        emit printBLNumber(ui->spinBoxPrintNumber->value(), data.sn);
    }

    //打印时间
    data.createTime    = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    //录入数据库
    registerData.insertRegData(data);

    //发送更新信号
    emit signalSelect(ALLDATA, true);

    //关闭窗口
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
