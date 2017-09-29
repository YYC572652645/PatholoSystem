#include "logindata.h"
#include "config/qreadini.h"
#include "databasedef.h"
#include "globaldef.h"

/****************          构造函数              ***************/
LoginData::LoginData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/****************          连接数据库             ***************/
bool LoginData::dataCnn()
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
    if(db.isOpen()) db.close();

    return db.open();
}

/****************          查询数据               ***************/
bool LoginData::selectData(QString userName, QString passWord)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;
    QString str = "select * from User where UserName = '"  + userName + "';";

    if(!query.exec(str)) return false;

    int count = 0;

    while(query.next())
    {
        userInfo.userName        = query.value(DATABASEDEF::USERNAME).toString();
        userInfo.passWord        = query.value(DATABASEDEF::PASSWORD).toString();
        userInfo.isAdministrator = query.value(DATABASEDEF::ISADMINISTRATOR).toString();
        userInfo.authority       = query.value(DATABASEDEF::AUTHORITY).toString();
        userInfo.remark          = query.value(DATABASEDEF::REMARK).toString();
        count ++;
    }

    db.close();

    if(userInfo.isAdministrator == GLOBALDEF::UNUSED)
    {
        return true;
    }
    else if(userInfo.passWord == passWord && !userInfo.passWord.isEmpty())
    {
        return true;
    }

    return false;
}

/****************          修改数据               ***************/
bool LoginData::updateData(QString userName, QString passWord)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update User set Password = '%1' where UserName = '%2';").arg(passWord, userName);

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/****************          获取用户信息            ***************/
UserInfo LoginData::getUserInfo() const
{
    return userInfo;
}


