#include "paintdata.h"
#include"config/qreadini.h"

PaintData * PaintData::instance = NULL;

/***************************构造函数***********************/
PaintData::PaintData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/***************************连接数据库*********************/
bool PaintData::dataCnn()
{
    //是否为默认连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase(DATACONFIG.dataBaseVersion);       //设置数据库类型
    }

    db.setHostName(DATACONFIG.ip);                                        //设置数据库主机名
    db.setPort(DATACONFIG.port.toInt());                                  //设置端口
    db.setDatabaseName(DATACONFIG.dataBaseName);                          //设置数据库名
    db.setUserName(DATACONFIG.userName);                                  //设置用户名
    db.setPassword(DATACONFIG.passWord);                                  //设置密码
    //如果数据库处于打开状态，则关闭
    if(db.isOpen())
    {
        db.close();
    }
    return db.open();
}

/***************************插入数据***********************/
bool PaintData::insertData(DataPaint data)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString str = "insert into Patient values('";

    str += data.patientID           + "' , '";

    str += data.hisId               + "' , '";

    str += data.name                + "' , '";

    str += data.sex                 + "' , '";

    str += data.age                 + "' , '";

    str += data.nationality         + "' , '";

    str += data.tel                 + "' , '";

    str += data.address             + " ', '";

    str += data.marriage            + "' , '";

    str += data.birthplace          + "' , '";

    str += data.job                 + "' , '";

    str += data.feeType             + "' , '";

    str += data.idCard              + "' , '";

    str += data.familyHistory       + "' , '";

    str += data.infectiousHistory   + "' , '";

    str += data.pastHistory         + "' , '";

    str += data.menarche            + "' , '";

    str += data.lastMenstruation    + "' , '";

    str += data.reproductiveHistory + "' ) ;";

    bool success = query.exec(str);

    if(!success) return success;

    str = "insert into RegPatient values('";

    str += data.regID               + "' , '";

    str += data.patientID           + "' , '";

    str += data.outPatientNo        + "' , '";

    str += data.hospitalizedNo      + "' , '";

    str += data.inpatientArea       + "' , '";

    str += data.bedNo               + "' , '";

    str += data.fromOffices         + "' , '";

    str += data.fromDoctor          + "' , '";

    str += data.sendTime            + "' , '";

    str += data.receiveTime         + "' , '";

    str += data.receiver            + "' , '";

    str += data.site                + "' , '";

    str += data.specimenQt          + "' , '";

    str += data.fixedMode           + "' , '";

    str += data.chiefComplaint      + "' , '";

    str += data.currentHistory      + "' , '";

    str += data.clinical            + "' ) ;";

    success = query.exec(str);

    db.close();

    return success;
}

/***************************查询数据***********************/
int PaintData::selectData(QString regId, QString patientID)
{
    int count = 0;

    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString str = "select * from Patient, RegPatient where Patient.PatientID = RegPatient.PatientID ";

    str += QString("and Patient.PatientID = '%1' and RegPatient.RegID = '%2';").arg(patientID, regId);

    bool success = query.exec(str);

    if(!success) return false;

    DataPaint data;

    while(query.next())
    {
        data.patientID           = query.value(0).toString();
        data.hisId               = query.value(1).toString();
        data.name                = query.value(2).toString();
        data.sex                 = query.value(3).toString();
        data.age                 = query.value(4).toString();
        data.nationality         = query.value(5).toString();
        data.tel                 = query.value(6).toString();
        data.address             = query.value(7).toString();
        data.marriage            = query.value(8).toString();
        data.birthplace          = query.value(9).toString();
        data.job                 = query.value(10).toString();
        data.feeType             = query.value(11).toString();
        data.idCard              = query.value(12).toString();
        data.familyHistory       = query.value(13).toString();
        data.infectiousHistory   = query.value(14).toString();
        data.pastHistory         = query.value(15).toString();
        data.menarche            = query.value(16).toString();
        data.lastMenstruation    = query.value(17).toString();
        data.reproductiveHistory = query.value(18).toString();
        data.regID               = query.value(19).toString();
        data.patientID           = query.value(20).toString();
        data.outPatientNo        = query.value(21).toString();
        data.hospitalizedNo      = query.value(22).toString();
        data.inpatientArea       = query.value(23).toString();
        data.bedNo               = query.value(24).toString();
        data.fromOffices         = query.value(25).toString();
        data.fromDoctor          = query.value(26).toString();
        data.sendTime            = query.value(27).toString();
        data.receiveTime         = query.value(28).toString();
        data.receiver            = query.value(29).toString();
        data.site                = query.value(30).toString();
        data.specimenQt          = query.value(31).toString();
        data.fixedMode           = query.value(32).toString();
        data.chiefComplaint      = query.value(33).toString();
        data.currentHistory      = query.value(34).toString();
        data.clinical            = query.value(35).toString();

        count ++;
    }

    dataPaint = data;

    db.close();

    return count;
}

/***************************更改数据***********************/
bool PaintData::updateData(DataPaint data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "update Patient set ";

    str += "HisId = '"               + data.hisId               + "' , ";

    str += "Name = '"                + data.name                + "' , ";

    str += "Sex = '"                 + data.sex                 + "' , ";

    str += "Age = '"                 + data.age                 + "' , ";

    str += "Nationality = '"         + data.nationality         + "' , ";

    str += "Tel = '"                 + data.tel                 + "' , ";

    str += "Address = '"             + data.address             + " ', ";

    str += "Marriage = '"            + data.marriage            + "' , ";

    str += "Birthplace = '"          + data.birthplace          + "' , ";

    str += "Job = '"                 + data.job                 + "' , ";

    str += "FeeType = '"             + data.feeType             + "' , ";

    str += "IDCard = '"              + data.idCard              + "' , ";

    str += "FamilyHistory = '"       + data.familyHistory       + "' , ";

    str += "InfectiousHistory = '"   + data.infectiousHistory   + "' , ";

    str += "PastHistory = '"         + data.pastHistory         + "' , ";

    str += "Menarche = '"            + data.menarche            + "' , ";

    str += "LastMenstruation = '"    + data.lastMenstruation    + "' , ";

    str += "ReproductiveHistory = '" + data.reproductiveHistory + "'   ";

    str += "where PatientID = '"     + data.patientID           + "' ; ";

    bool success = query.exec(str);

    if(!success) return success;

    str  = "update RegPatient set ";

    str += "OutPatientNo = '"    + data.outPatientNo        + "' , ";

    str += "HospitalizedNo = '"  + data.hospitalizedNo      + "' , ";

    str += "InpatientArea = '"   + data.inpatientArea       + "' , ";

    str += "BedNo = '"           + data.bedNo               + "' , ";

    str += "FromOffices = '"     + data.fromOffices         + "' , ";

    str += "FromDoctor = '"      + data.fromDoctor          + "' , ";

    str += "SendTime = '"        + data.sendTime            + "' , ";

    str += "ReceiveTime = '"     + data.receiveTime         + "' , ";

    str += "Receiver = '"        + data.receiver            + "' , ";

    str += "Site = '"            + data.site                + "' , ";

    str += "SpecimenQt = '"      + data.specimenQt          + "' , ";

    str += "FixedMode = '"       + data.fixedMode           + "' , ";

    str += "ChiefComplaint = '"  + data.chiefComplaint      + "' , ";

    str += "CurrentHistory = '"  + data.currentHistory      + "' , ";

    str += "Clinical = '"        + data.clinical            + "'  ";

    str += "where RegID = '"     + data.regID               + "'  ";

    str += "and PatientID = '"   + data.patientID           + "' ; ";

    success = query.exec(str);

    db.close();

    return success;
}

/***************************删除数据***********************/
bool PaintData::deleteData(QString regId, QString patientID)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("delete from Patient where PatientID = '%1';").arg(patientID);

    bool success = query.exec(str);

    if(!success) return success;

    str = QString("delete from RegPatient where PatientID = '%1' and RegID = '%2';").arg(patientID, regId);

    success = query.exec(str);

    db.close();

    return success;
}

/***************************获取数据***********************/
DataPaint PaintData::getDataPaint() const
{
    return dataPaint;
}



