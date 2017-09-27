#include "normalmaterial.h"
#include "ui_normalmaterial.h"
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

/*******************   设置数据    ***********************/
void NormalMaterial::setData(DataParent data)
{
    ui->lineEditBlNumber->setText(data.pCode);                        //病理号
    ui->lineEditName->setText(data.specimenName);                     //标本名称
    ui->lineEditNumber->setText(data.specimenQuantity);               //标本数量
    ui->lineEditSize->setText(data.specimenSize);                     //标本大小
    ui->lineEditWeight->setText(data.specimenWeight);                 //标本重量
    ui->spinBoxMaterialNumber->setValue(data.samplingCount.toInt());  //取材总数
    ui->comboBoxPeople->setCurrentText(data.sampler);                 //取材人
    ui->textEditRecord->setText(data.note );                          //检测记录
    ui->comboBoxRegPeople->setCurrentText(data.noter);                //记录人
}

/*******************   确定按钮    ***********************/
void NormalMaterial::on_pushButtonOk_clicked()
{
    if(ui->lineEditBlNumber->text().isEmpty()) return;

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
    }

    data.pCode = ui->lineEditBlNumber->text();                                           //病理号

    INICONFIG->writeQCIni(data.pCode);

    data.specimenName = ui->lineEditName->text();                                        //标本名称
    data.specimenQuantity = ui->lineEditNumber->text();                                  //标本数量
    data.specimenSize = ui->lineEditSize->text();                                        //标本大小
    data.specimenWeight = ui->lineEditWeight->text();                                    //标本重量
    data.samplingCount = QString::number(ui->spinBoxMaterialNumber->value());            //取材总数
    data.sampler = ui->comboBoxPeople->currentText();                                    //取材人
    data.note = ui->textEditRecord->toPlainText();                                       //检测记录
    data.noter = ui->comboBoxRegPeople->currentText();                                   //记录人
    data.createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");      //取材时间

    if(!MATERIALDATA->insertParentData(data))
    {
        MATERIALDATA->updateParentData(data);

        emit sendSelect();

        this->close();

        return;
    }

    //获取编码规则
    SYSTEMDATA->codeBeginSelectData();
    QMap<QString, QString>mapData = SYSTEMDATA->getCodeBeginSnSetInfo();

    DataChild dataChild;

    dataChild.samplingId = data.samplingId;               //取材ID
    dataChild.sn = "1";                                   //序号

    {
        dataChild.embedCode = data.pCode;                 //病理号子序号

        if(mapData[HYPHEN] != "0")
        {
            dataChild.embedCode +=  "-";                 //病理号子序号
        }

        switch(mapData[NUMBERTYPE].toInt())
        {
        case 0: dataChild.embedCode +=  "1";  break;      //病理号子序号
        case 1: dataChild.embedCode +=  "a";  break;      //病理号子序号
        case 2: dataChild.embedCode +=  "A";  break;      //病理号子序号
        }
    }

    dataChild.printed = "0";                              //是否打印
    dataChild.sampled = "0";                              //是否取材
    dataChild.sampler =  data.sampler;                    //取材人
    dataChild.samplingTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");;     //取材时间

    MATERIALDATA->insertChildData(dataChild);

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

/*******************   按钮点击            ***********************/
void NormalMaterial::keyPressEvent(QKeyEvent * event)
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
