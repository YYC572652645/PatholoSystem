#ifndef REGISTERDATA_H
#define REGISTERDATA_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>
#include "globaldef.h"

class RegisterData
{
public:

    /************构造函数*************/
    RegisterData();

    /************连接数据库*************/
    bool dataCnn();

    /************插入数据*************/
    bool insertRegData(RegisterInfo & data);

    /************查询最大Id号*************/
    int selectMaxId();

    /************查询数据*************/
    int selectData();

    /************查询数据*************/
    int selectBLData(QString blNumber);

    /************更改数据*************/
    bool updateBLData(QString printed, QString id);

    /************删除数据*************/
    bool deleteAllData();

    /************删除数据*************/
    bool deleteRowData(QString id);

    QList<RegisterInfo>registerInfo; //存储数据

private:
    QSqlDatabase db;                 //定义数据库对象
};

#endif // DATABASE_H
