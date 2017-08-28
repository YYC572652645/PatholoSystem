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

typedef struct RegisterInfo
{
    QString id;           //id号
    QString pCode;        //序号
    QString sn;           //病理号
    QString printQuantity;//打印数量
    QString printed;      //是否打印
    QString createTime;   //创建时间
    QString userId;       //用户id
}RegisterInfo;

class RegisterData
{
public:
    /************构造函数*************/
    RegisterData();

    /************连接数据库*************/
    bool dataCnn();

    /************插入数据*************/
    bool insertData(RegisterInfo & data);

    /************查询最大Id号*************/
    int selectMaxId();

    /************查询数据*************/
    int selectData();

    /************更改数据*************/
    bool updateData();

    /************删除数据*************/
    bool deleteData();

    QList<RegisterInfo>registerInfo; //存储数据

private:
    QSqlDatabase db;                 //定义数据库对象
};

#endif // DATABASE_H
