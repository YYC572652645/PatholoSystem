#ifndef MATERIALDATA_H
#define MATERIALDATA_H

/***************************************************************
   功能:取材数据库信息

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>
#include "globaldef.h"

#define MATERIALDATA MaterialData::getInstance()

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

typedef struct DataStatistics
{
    QString date;             //日期
    QString materialTotal;    //取材总例数
    QString embeddingTotal;   //包埋总数
    QString normalMtlTotal;   //常规取材例数
    QString normalEddTotal;   //常规包埋数
    QString frozenMtlTotal;   //冰冻取材例数
    QString frozenEddTotal;   //冰冻包埋数
}DataStatistics;

class MaterialData
{
public:
    /************     单例模式       *************/
    static MaterialData * getInstance()
    {
        if(NULL == instance)
        {
            instance = new MaterialData();
        }

        return instance;
    }

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

    /************    统计数据        *************/
    int selectStatistics(QString beginTime = NULL, QString endTime = NULL);

    /************    更改子类数据     *************/
    bool updateChildData(DataChild data);

    /************    更改父类数据     *************/
    bool updateParentData(DataParent data);

    /************    删除数据         *************/
    bool deleteData(int type, QString id = NULL, QString embedCode = NULL);

    /************    获取子节点数据    *************/
    QList<DataChild> getChildList() const;

    /************    获取父节点数据    *************/
    QList<DataParent> getParentList() const;

    /************    获取统计数据      *************/
    QList<DataStatistics> getStatisticsList() const;

private:
    QSqlDatabase db;                      //数据库对象
    static MaterialData *instance;        //单例模式
    QList<DataParent> parentList;         //父节点数据
    QList<DataChild>  childList;          //子节点数据
    QList<DataStatistics> statisticsList; //统计数据
};

#endif // DATABASE_H
