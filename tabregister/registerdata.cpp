#include "registerdata.h"
#include "config/qreadini.h"
#include "databasedef.h"
#include "globaldef.h"

/********************         构造函数              ******************/
RegisterData::RegisterData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/********************         连接数据库             ******************/
bool RegisterData::dataCnn()
{
    //是否为默认连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase(DATACONFIG.dataBaseVersion);      //设置数据库类型
    }

    db.setHostName(DATACONFIG.ip);                                        //设置数据库主机名
    db.setPort(DATACONFIG.port.toInt());                                  //设置端口
    db.setDatabaseName(DATACONFIG.dataBaseName);                          //设置数据库名
    db.setUserName(DATACONFIG.userName);                                  //设置用户名
    db.setPassword(DATACONFIG.passWord);                                  //设置密码

    if(db.isOpen()) db.close();                                           //如果数据库处于打开状态，则关闭
    return db.open();
}

/********************         插入数据               ******************/
bool RegisterData::insertRegData(RegisterInfo & data)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString str = QString("insert into Reg(PCode,Sn,PrintQuantity,Printed,CreateTime) values('");

    str +=  data.pCode         + "','";

    str +=  data.sn            + "','";

    str +=  data.printQuantity + "','";

    str +=  data.printed       + "','";

    str +=  data.createTime    + "');";


    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/********************         查询最大ID             ******************/
int RegisterData::selectMaxId()
{
    int maxId = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("select PCode from Reg where Id in( select max(Id) from Reg);");

    bool success = query.exec(str);  //执行sql语句

    if(!success)  return GLOBALDEF::DATAERROR;

    if(query.next()) maxId = query.value(0).toInt();

    db.close();

    return maxId;
}

/********************         查询数据               ******************/
int RegisterData::selectData()
{ 
    int count = 0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString str = QString("select * from Reg;");

    bool success = query.exec(str);  //执行sql语句

    if(!success)  return GLOBALDEF::DATAERROR;

    registerInfo.clear();

    while(query.next())        //挨个遍历数据
    {
        RegisterInfo data;

        data.id            = query.value(DATABASEDEF::REGID).toString();
        data.pCode         = query.value(DATABASEDEF::REGPCODE).toString();
        data.sn            = query.value(DATABASEDEF::REGSN).toString();
        data.printQuantity = query.value(DATABASEDEF::REGPRINTQUANTITY).toString();
        data.printed       = query.value(DATABASEDEF::REGPRINTED).toString();
        data.createTime    = query.value(DATABASEDEF::REGCREATETIME).toString();

        registerInfo.append(data);

        count ++;
    }

    db.close();

    return count;
}

/********************         根据病理号查询数据       ******************/
int RegisterData::selectBLData(QString blNumber)
{
    int count = 0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString str = QString("select * from Reg where Sn like '%%1%';").arg(blNumber);

    bool success = query.exec(str);  //执行sql语句

    if(!success)  return GLOBALDEF::DATAERROR;

    registerInfo.clear();

    while(query.next())        //挨个遍历数据
    {
        RegisterInfo data;

        data.id            = query.value(DATABASEDEF::REGID).toString();
        data.pCode         = query.value(DATABASEDEF::REGPCODE).toString();
        data.sn            = query.value(DATABASEDEF::REGSN).toString();
        data.printQuantity = query.value(DATABASEDEF::REGPRINTQUANTITY).toString();
        data.printed       = query.value(DATABASEDEF::REGPRINTED).toString();
        data.createTime    = query.value(DATABASEDEF::REGCREATETIME).toString();

        registerInfo << data;

        count ++;
    }

    db.close();

    return count;
}

/********************         更改数据                ******************/
bool RegisterData::updateBLData(QString printed, QString id)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update Reg set Printed = '%1' where Id = '%2';").arg(printed, id);

    bool success = query.exec(str);

    db.close();

    return success;
}

/********************         删除数据                ******************/
bool RegisterData::deleteAllData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("delete from Reg");

    bool success = query.exec(str);

    db.close();

    return success;
}

/********************         删除数据                ******************/
bool RegisterData::deleteRowData(QString id)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;
    QString Str = QString("delete from Reg where Id = '%1'").arg(id);
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

