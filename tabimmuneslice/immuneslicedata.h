#ifndef IMMUNESLICEDATA_H
#define IMMUNESLICEDATA_H

/***************************************************************
   功能:免疫组化切片数据库信息

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QString>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QFile>
#include <QIODevice>
#include <QDebug>

#define IMMUNESLICEDATA ImmuneSliceData::getInstance()

typedef struct DataImmuneSlice
{
    QString sectionId;      //id
    QString sectionCode;    //编号
    QString embedCode;      //编号
    QString stainTypeName;  //染色类型
    QString staining;       //染色指标
    QString sectionTime;    //切片时间
    QString sectioner;      //切片人
    QString stainTime;      //染色时间
    QString stainer;        //染色人
    QString printNum;       //打印数量
    QString printed;        //是否打印
    QString cloneNumber;    //克隆号码
}DataImmuneSlice;

class ImmuneSliceData
{
public:
    /************         单例模式         *************/
    static ImmuneSliceData * getInstance()
    {
        if(NULL == instance)
        {
            instance = new ImmuneSliceData();
        }

        return instance;
    }

    /************         构造函数         *************/
    ImmuneSliceData();

    /************         连接数据库         *************/
    bool dataCnn();

    /************         插入数据         *************/
    bool insertData(DataImmuneSlice data);

    /************         查询数据         *************/
    int selectData(int type, QString text);

    /************         更改数据         *************/
    bool updateData(DataImmuneSlice data);

    /************         删除数据         *************/
    bool deleteData(int type, QString id);

    /************         获取数据         *************/
    QList<DataImmuneSlice> getDataList() const;

private:
    QSqlDatabase db;                   //定义数据库对象
    static ImmuneSliceData * instance; //单例模式
    QList<DataImmuneSlice> dataList;   //数据库数据
};

#endif // DATABASE_H
