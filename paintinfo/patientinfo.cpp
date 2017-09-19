#include "patientinfo.h"
#include "ui_patientinfo.h"
#include "paintdata.h"
#include <QDebug>

/********************       构造函数      ***********************/
PatientInfo::PatientInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::patientinfo)
{
    ui->setupUi(this);

    this->initControl();
}

/********************       析构函数      ***********************/
PatientInfo::~PatientInfo()
{
    delete ui;
}

/********************       初始化控件      ***********************/
void PatientInfo::initControl()
{
    autoSaveBox = new QCheckBox();
    autoSaveBox->setText("自动保存");
    autoSaveBox->setChecked(false);

    labelInfo = new QLabel();
    labelInfo->setText("  患者信息   ");

    ui->toolBar->addWidget(autoSaveBox);
    ui->toolBar->addWidget(labelInfo);

    ui->comboBoxNation->addItem(tr("汉族"));
    ui->comboBoxNation->addItem(tr("回族"));
    ui->comboBoxNation->addItem(tr("蒙古族"));
    ui->comboBoxNation->addItem(tr("藏族"));
    ui->comboBoxNation->addItem(tr("维吾尔族"));
    ui->comboBoxNation->addItem(tr("苗族"));
    ui->comboBoxNation->addItem(tr("彝族"));
    ui->comboBoxNation->addItem(tr("壮族"));
    ui->comboBoxNation->addItem(tr("布依族"));
    ui->comboBoxNation->addItem(tr("朝鲜族"));
    ui->comboBoxNation->addItem(tr("满族"));
    ui->comboBoxNation->addItem(tr("侗族"));
    ui->comboBoxNation->addItem(tr("瑶族"));
    ui->comboBoxNation->addItem(tr("白族"));
    ui->comboBoxNation->addItem(tr("土家族"));
    ui->comboBoxNation->addItem(tr("哈尼族"));
    ui->comboBoxNation->addItem(tr("哈萨克族"));
    ui->comboBoxNation->addItem(tr("傣族"));
    ui->comboBoxNation->addItem(tr("黎族"));
    ui->comboBoxNation->addItem(tr("僳僳族"));
    ui->comboBoxNation->addItem(tr("佤族"));
    ui->comboBoxNation->addItem(tr("畲族"));
    ui->comboBoxNation->addItem(tr("高山族"));
    ui->comboBoxNation->addItem(tr("拉祜族"));
    ui->comboBoxNation->addItem(tr("水族"));
    ui->comboBoxNation->addItem(tr("东乡族"));
    ui->comboBoxNation->addItem(tr("纳西族"));
    ui->comboBoxNation->addItem(tr("景颇族"));
    ui->comboBoxNation->addItem(tr("柯尔克孜族"));
    ui->comboBoxNation->addItem(tr("土族"));
    ui->comboBoxNation->addItem(tr("达斡尔族"));
    ui->comboBoxNation->addItem(tr("仫佬族"));
    ui->comboBoxNation->addItem(tr("羌族"));
    ui->comboBoxNation->addItem(tr("布朗族"));
    ui->comboBoxNation->addItem(tr("撒拉族"));
    ui->comboBoxNation->addItem(tr("毛南族"));
    ui->comboBoxNation->addItem(tr("仡佬族"));
    ui->comboBoxNation->addItem(tr("锡伯族"));
    ui->comboBoxNation->addItem(tr("阿昌族"));
    ui->comboBoxNation->addItem(tr("普米族"));
    ui->comboBoxNation->addItem(tr("塔吉克族"));
    ui->comboBoxNation->addItem(tr("怒族"));
    ui->comboBoxNation->addItem(tr("乌孜别克族"));
    ui->comboBoxNation->addItem(tr("俄罗斯族"));
    ui->comboBoxNation->addItem(tr("鄂温克族"));
    ui->comboBoxNation->addItem(tr("德昂族"));
    ui->comboBoxNation->addItem(tr("保安族"));
    ui->comboBoxNation->addItem(tr("裕固族"));
    ui->comboBoxNation->addItem(tr("京族"));
    ui->comboBoxNation->addItem(tr("塔塔尔族"));
    ui->comboBoxNation->addItem(tr("独龙族"));
    ui->comboBoxNation->addItem(tr("鄂伦春族"));
    ui->comboBoxNation->addItem(tr("赫哲族"));
    ui->comboBoxNation->addItem(tr("门巴族"));
    ui->comboBoxNation->addItem(tr("珞巴族"));
    ui->comboBoxNation->addItem(tr("基诺族"));

    ui->dateTimeEditJieShou->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEditJieShou->setDateTime(QDateTime::currentDateTime());

    ui->dateTimeEditSongJian->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEditSongJian->setDateTime(QDateTime::currentDateTime());

    ui->tabWidget->setCurrentIndex(0);
}

/********************       设置患者Id      ***********************/
void PatientInfo::setPaintId(const QString &value)
{
    paintId = value;
}

/********************       查询数据       ***********************/
void PatientInfo::setSelect()
{

    //如果是自动保存，则保存
    if(autoSaveBox->isChecked())
    {
        on_actionSavePatientInfo_triggered();
    }

    //清除信息
    this->clearInfo();

    PAINTDATA->selectData(regId, paintId);

    DataPaint data = PAINTDATA->getDataPaint();

    ui->lineEditID->setText(data.hisId);
    ui->lineEditName->setText(data.name);
    ui->comboBoxSex->setCurrentText(data.sex);
    ui->lineEditAge->setText(data.age);
    ui->lineEditPhone->setText(data.tel);
    ui->lineEditAddress->setText(data.address);
    ui->comboBoxNation->setCurrentText(data.nationality);
    ui->lineEditNative->setText(data.birthplace);
    ui->comboBoxMarry->setCurrentText(data.marriage);
    ui->lineEditWork->setText(data.job);
    ui->comboBoxMoneyType->setCurrentText(data.feeType);
    ui->lineEditIDCard->setText(data.idCard);
    ui->lineEditFimilyHistory->setText(data.familyHistory);
    ui->lineEditCHuanRan->setText(data.infectiousHistory);
    ui->lineEditAgo->setText(data.pastHistory);
    ui->lineEditChuCao->setText(data.menarche);
    ui->lineEditLast->setText(data.lastMenstruation);
    ui->lineEditBornHistory->setText(data.reproductiveHistory);
    ui->lineEditMenZhen->setText(data.outPatientNo);
    ui->lineEditZhuYuan->setText(data.hospitalizedNo);
    ui->lineEditBingQu->setText(data.inpatientArea);
    ui->lineEditBedNumber->setText(data.bedNo);
    ui->lineEditJianKe->setText(data.fromOffices);
    ui->lineEditJianDoctor->setText(data.fromDoctor);
    ui->dateTimeEditJieShou->setDateTime(QDateTime::fromString(data.sendTime, "yyyy-MM-dd hh:mm:ss"));
    ui->dateTimeEditSongJian->setDateTime(QDateTime::fromString(data.receiveTime, "yyyy-MM-dd hh:mm:ss"));
    ui->lineEditJieShouPeople->setText(data.receiver);
    ui->lineEditQuCaiBuWei->setText(data.site );
    ui->lineEditBiaoBenNumber->setText(data.specimenQt);
    ui->lineEditGuDing->setText(data.fixedMode);
    ui->lineEditZhuSu->setText(data.chiefComplaint);
    ui->lineEditNow->setText(data.currentHistory);
    ui->textEditTiZheng->setText(data.clinical);
}

/********************       设置病理号      ***********************/
void PatientInfo::setRegId(const QString &value)
{
    regId = value;
}

/********************       录入数据       ***********************/
void PatientInfo::on_actionSavePatientInfo_triggered()
{
    DataPaint data;

    data.regID               = regId;
    data.patientID           = paintId;
    data.hisId               = ui->lineEditID->text();
    data.name                = ui->lineEditName->text();
    data.sex                 = ui->comboBoxSex->currentText();
    data.age                 = ui->lineEditAge->text();
    data.tel                 = ui->lineEditPhone->text();
    data.address             = ui->lineEditAddress->text();
    data.nationality         = ui->comboBoxNation->currentText();
    data.birthplace          = ui->lineEditNative->text();
    data.marriage            = ui->comboBoxMarry->currentText();
    data.job                 = ui->lineEditWork->text();
    data.feeType             = ui->comboBoxMoneyType->currentText();
    data.idCard              = ui->lineEditIDCard->text();
    data.familyHistory       = ui->lineEditFimilyHistory->text();
    data.infectiousHistory   = ui->lineEditCHuanRan->text();
    data.pastHistory         = ui->lineEditAgo->text();
    data.menarche            = ui->lineEditChuCao->text();
    data.lastMenstruation    = ui->lineEditLast->text();
    data.reproductiveHistory = ui->lineEditBornHistory->text();
    data.outPatientNo        = ui->lineEditMenZhen->text();
    data.hospitalizedNo      = ui->lineEditZhuYuan->text();
    data.inpatientArea       = ui->lineEditBingQu->text();
    data.bedNo               = ui->lineEditBedNumber->text();
    data.fromOffices         = ui->lineEditJianKe->text();
    data.fromDoctor          = ui->lineEditJianDoctor->text();
    data.sendTime            = ui->dateTimeEditSongJian->text();
    data.receiveTime         = ui->dateTimeEditJieShou->text();
    data.receiver            = ui->lineEditJieShouPeople->text();
    data.site                = ui->lineEditQuCaiBuWei->text();
    data.specimenQt          = ui->lineEditBiaoBenNumber->text();
    data.fixedMode           = ui->lineEditGuDing->text();
    data.chiefComplaint      = ui->lineEditZhuSu->text();
    data.currentHistory      = ui->lineEditNow->text();
    data.clinical            = ui->textEditTiZheng->toPlainText();

    if(!PAINTDATA->insertData(data))
    {
        PAINTDATA->updateData(data);
    }
}

/********************       清除患者信息    ***********************/
void PatientInfo::on_actionClearPatientInfo_triggered()
{
    PAINTDATA->deleteData(regId, paintId);

    clearInfo();
}

/********************       清除信息        ***********************/
void PatientInfo::clearInfo()
{
    ui->lineEditID->clear();
    ui->lineEditName->clear();
    ui->comboBoxSex->setCurrentIndex(0);
    ui->lineEditAge->clear();
    ui->lineEditPhone->clear();
    ui->lineEditAddress->clear();
    ui->comboBoxNation->setCurrentIndex(0);
    ui->lineEditNative->clear();
    ui->comboBoxMarry->setCurrentIndex(0);
    ui->lineEditWork->clear();
    ui->comboBoxMoneyType->setCurrentIndex(0);
    ui->lineEditIDCard->clear();
    ui->lineEditFimilyHistory->clear();
    ui->lineEditCHuanRan->clear();
    ui->lineEditAgo->clear();
    ui->lineEditChuCao->clear();
    ui->lineEditLast->clear();
    ui->lineEditBornHistory->clear();
    ui->lineEditMenZhen->clear();
    ui->lineEditZhuYuan->clear();
    ui->lineEditBingQu->clear();
    ui->lineEditBedNumber->clear();
    ui->lineEditJianKe->clear();
    ui->lineEditJianDoctor->clear();
    ui->lineEditJieShouPeople->clear();
    ui->lineEditQuCaiBuWei->clear();
    ui->lineEditBiaoBenNumber->clear();
    ui->lineEditGuDing->clear();
    ui->lineEditZhuSu->clear();
    ui->lineEditNow->clear();
    ui->textEditTiZheng->clear();

    ui->dateTimeEditJieShou->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEditJieShou->setDateTime(QDateTime::currentDateTime());

    ui->dateTimeEditSongJian->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEditSongJian->setDateTime(QDateTime::currentDateTime());
}
