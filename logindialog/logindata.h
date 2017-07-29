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


/***************************************************************
   功能:登录框

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

typedef struct UserInfo
{
    QString userId;
    QString userNo;
    QString userName;
    QString passWord;
    QString isAdministrator;
    QString unused;
    QString remark;

}UserInfo;


class LoginData
{
public:
    /************构造函数*************/
    LoginData();


    /************连接数据库*************/
    bool dataCnn();


    /************插入数据*************/
    bool insertData();


    /************查询数据*************/
    bool selectData(QString userName, QString passWord);


    /************更改数据*************/
    bool updateData();


    /************删除数据*************/
    bool deleteData();


private:
    QSqlDatabase db;               //定义数据库对象
    UserInfo userInfo;             //用户信息
};

#endif // DATABASE_H
