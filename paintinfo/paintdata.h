#ifndef PAINTDATA_H
#define PAINTDATA_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>

/***************************************************************
   功能:病人信息

   创建人:殷宇辰

   创建时间:2017-9-21
**************************************************************/

#define PAINTDATA  PaintData::getInstance()

typedef struct DataPaint
{
    QString regID;
    QString patientID;
    QString hisId;
    QString name;
    QString sex;
    QString age;
    QString nationality;
    QString tel;
    QString address;
    QString marriage;
    QString birthplace;
    QString job;
    QString feeType;
    QString idCard;
    QString familyHistory;
    QString infectiousHistory;
    QString pastHistory;
    QString menarche;
    QString lastMenstruation;
    QString reproductiveHistory;
    QString outPatientNo;
    QString hospitalizedNo;
    QString inpatientArea;
    QString bedNo;
    QString fromOffices;
    QString fromDoctor;
    QString sendTime;
    QString receiveTime;
    QString receiver;
    QString site;
    QString specimenQt;
    QString fixedMode;
    QString chiefComplaint;
    QString currentHistory;
    QString clinical;
}DataPaint;

class PaintData
{
public:

    /************         单例模式         *************/
    static PaintData * getInstance();

    /************         构造函数         *************/
    PaintData();

    /************         连接数据库       *************/
    bool dataCnn();

    /************         插入数据         *************/
    bool insertData(DataPaint data);

    /************         查询数据         *************/
    int selectData(QString regId, QString patientID);

    /************         更改数据         *************/
    bool updateData(DataPaint data);

    /************         删除数据         *************/
    bool deleteData(QString regId, QString patientID);

    /************         获取数据         *************/
    DataPaint getDataPaint() const;

private:
    QSqlDatabase db;                  //定义数据库对象
    static PaintData * instance;      //单例模式
    DataPaint dataPaint;              //数据存取
};

#endif // DATABASE_H
