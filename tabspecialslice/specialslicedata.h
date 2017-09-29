#ifndef SPECIALSLICEDATA_H
#define SPECIALSLICEDATA_H

/***************************************************************
   功能:特染切片数据库信息

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

#define SPECIALSLICEDATA SpecialSliceData::getInstance()

typedef struct DataSpecialSlice
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
}DataSpecialSlice;

class SpecialSliceData
{
public:

    /************    单例模式       *************/
    static SpecialSliceData * getInstance()
    {
        if(NULL == instance)
        {
            instance = new SpecialSliceData();
        }

        return instance;
    }

    /************    构造函数       *************/
    SpecialSliceData();

    /************    连接数据库       *************/
    bool dataCnn();

    /************    插入数据       *************/
    bool insertData(DataSpecialSlice data);

    /************    查询数据       *************/
    int selectData(int type, QString text);

    /************    更改数据       *************/
    bool updateData(DataSpecialSlice data);

    /************    删除数据       *************/
    bool deleteData(int type, QString id);

    /************    获取数据       *************/
    QList<DataSpecialSlice> getDataList() const;

private:
    QSqlDatabase db;                    //定义数据库对象
    static SpecialSliceData * instance; //单例模式
    QList<DataSpecialSlice> dataList;   //数据库数据
};

#endif // DATABASE_H
