#include "normalmaterial.h"
#include "ui_normalmaterial.h"
#include "materialdata.h"
#include <QDateTime>
#include <config/qreadini.h>
#include "../tabsystemset/tabsystemdata.h"
#include "../../globaldef.h"

/*******************   构造函数    ***********************/
NormalMaterial::NormalMaterial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::normalmaterial)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("常规取材"));

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
}


/*******************   析构函数    ***********************/
NormalMaterial::~NormalMaterial()
{
    delete ui;
}

/*******************   显示信息    ***********************/
void NormalMaterial::showWidget(QString number, QString id)
{
    this->id = id;
    ui->lineEditBlNumber->setText(number);

    this->show();
}

/*******************   显示信息    ***********************/
void NormalMaterial::showWidget()
{
    this->show();
}

/*******************   确定按钮    ***********************/
void NormalMaterial::on_pushButtonOk_clicked()
{
    DataParent data;

    if(!this->id.isEmpty())
    {
        data.samplingId = this->id;                                                      //取材ID
    }
    else
    {
        QString pCode = MATERIALDATA->selectCode(ui->lineEditBlNumber->text());

        data.samplingId = pCode;

        if(pCode.isEmpty())
        {
            data.samplingId = subFinger(ui->lineEditBlNumber->text());
        }

        if(data.samplingId.isEmpty())
        {
            data.samplingId = ui->lineEditBlNumber->text();
        }

        INICONFIG->writeQCIni(data.samplingId);
    }

    data.pCode = ui->lineEditBlNumber->text();                                           //病理号
    data.specimenName = ui->lineEditName->text();                                        //标本名称
    data.specimenQuantity = ui->lineEditNumber->text();                                  //标本数量
    data.specimenSize = ui->lineEditSize->text();                                        //标本大小
    data.specimenWeight = ui->lineEditWeight->text();                                    //标本重量
    data.samplingCount = QString::number(ui->spinBoxMaterialNumber->value());            //取材总数
    data.sampler = ui->comboBoxPeople->currentText();                                    //取材人
    data.note = ui->textEditRecord->toPlainText();                                       //检测记录
    data.noter = ui->comboBoxRegPeople->currentText();                                   //记录人
    data.createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");  //取材时间

    MATERIALDATA->insertParentData(data);

    //获取编码规则
    SYSTEMDATA->codeTypeSelectData();
    QMap<QString, QString>mapData = SYSTEMDATA->getCodeBeginSnSetInfo();

    DataChild dataChild;

    dataChild.samplingId = data.samplingId;               //取材ID
    dataChild.sn = "1";                                   //序号

    {
        dataChild.embedCode = data.pCode;                 //病理号子序号

        if(mapData[HYPHEN].toInt() != 0)
        {
            dataChild.embedCode +=  "-";                 //病理号子序号
        }

        switch(mapData[NUMBERTYPE].toInt())
        {
        case 0: dataChild.embedCode +=  "1";              //病理号子序号
        case 1: dataChild.embedCode +=  "a";              //病理号子序号
        case 2: dataChild.embedCode +=  "A";              //病理号子序号
        }
    }

    dataChild.printed = "0";                              //是否打印
    dataChild.sampled = "0";                              //是否取材
    dataChild.sampler =  data.sampler;                    //取材人
    dataChild.samplingTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");;     //取材时间

    MATERIALDATA->insertChildData(dataChild);


    qDebug()<<"11111111111111111111111111111111111";
    emit sendSelect();

    this->close();
}

/*******************   取消按钮    ***********************/
void NormalMaterial::on_pushButtonCancel_clicked()
{
    this->close();
}

/*******************   去字母    ***********************/
QString NormalMaterial::subFinger(QString number)
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
