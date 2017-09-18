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

typedef struct DataPaint
{
    QString regID;
    QString patientID;
    QString hisId;
    QString name;
    QString sex;
    QString age;
    QString birthYear;
    QString nationality;
    QString tel;
    QString address;
    QString marriage;
    QString birthplace;
    QString job;
    QString feeType;
    QString idCard;
    QString createTime;
    QString modifyTime;
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
    QString specimenQt;
    QString fixedMode;
    QString chiefComplaint;
    QString currentHistory;
    QString clinical;
}DataPaint;

class PaintData
{
public:
    /************    构造函数      *************/
    PaintData();

    /************    连接数据库    *************/
    bool dataCnn();

    /************     插入数据     *************/
    bool insertData();

    /************     查询数据     *************/
    bool selectData();

    /************     更改数据     *************/
    bool updateData();

    /************     删除数据    *************/
    bool deleteData();

private:
    QSqlDatabase db;               //定义数据库对象
};

#endif // DATABASE_H
