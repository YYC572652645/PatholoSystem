#ifndef DATABASE_H
#define DATABASE_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>
#include "globaldef.h"
#include <../singleton/singleton.h>

#define MATERIALDATA Singleton<MaterialData>::getInstance()

typedef struct DataParent
{
    QString samplingId;       //取材ID
    QString pCode;            //病理号
    QString specimenName;     //标本名称
    QString specimenQuantity; //标本数量
    QString specimenSize;     //标本大小
    QString specimenWeight;   //标本重量
    QString samplingCount;    //取材总数
    QString sampler;          //取材人
    QString note;             //检测记录
    QString noter;            //记录人
    QString createTime;       //取材时间
}DataParent;


typedef struct DataChild
{
    QString samplingId;       //取材ID
    QString sn;               //序号
    QString embedCode;        //病理号子序号
    QString tissue;           //组织名称
    QString printed;          //是否打印
    QString printTime;        //打印时间
    QString sampled;          //是否取材
    QString sampler;          //取材人
    QString samplingTime;     //取材时间
}DataChild;


class MaterialData
{
public:
    /************     构造函数       *************/
    MaterialData();

    /************    连接数据库      *************/
    bool dataCnn();

    /************    插入父类数据    *************/
    bool insertParentData(DataParent data);

    /************    插入子类数据    *************/
    bool insertChildData(DataChild data);

    /************    查询数据        *************/
    bool selectData(int type, QString number = NULL);

    /************    查询编号        **************/
    QString selectCode(QString blNumber);

    /************    查询包埋数量     *************/
    int selectBaoMai(QString blNumber);

    /************    更改子类数据     *************/
    bool updateChildData(DataChild data);

    /************    更改父类数据     *************/
    bool updateParentData(DataParent data);

    /************    删除数据         *************/
    bool deleteData(int type, QString id = NULL, QString embedCode = NULL);

    QList<DataChild> getChildList() const;

    QList<DataParent> getParentList() const;

private:
    QSqlDatabase db;               //定义数据库对象

    QList<DataParent> parentList;
    QList<DataChild>  childList;
};

#endif // DATABASE_H
