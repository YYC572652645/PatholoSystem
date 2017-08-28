#include "registerdata.h"
#include "config/qreadini.h"
#include "databasedef.h"
#include "globaldef.h"

/***************************构造函数***********************/
RegisterData::RegisterData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}


/***************************连接数据库*********************/
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
    //如果数据库处于打开状态，则关闭
    if(db.isOpen())
    {
        db.close();
    }
    return db.open();
}

/***************************插入数据***********************/
bool RegisterData::insertData(RegisterInfo & data)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString str = QString("insert into Reg values('");
    str +=  data.id            + "','";
    str +=  data.pCode         + "','";
    str +=  data.sn            + "','";
    str +=  data.printQuantity + "','";
    str +=  data.printed       + "','";
    str +=  data.createTime    + "','";
    str +=  data.userId        + "');";

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

int RegisterData::selectMaxId()
{
    int maxId = 0;
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("select max(Id) from Reg;");

    bool success = query.exec(str);  //执行sql语句

    if(!success)  return GLOBALDEF::ERROR;

    if(query.next()) maxId = query.value(0).toInt();

    db.close();

    return maxId;
}

/***************************查询数据***********************/
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

    if(!success)  return GLOBALDEF::ERROR;

    while(query.next())        //挨个遍历数据
    {
        RegisterInfo data;

        data.id            = query.value(DAtABASEDEF::REGID).toString();
        data.pCode         = query.value(DAtABASEDEF::REGPCODE).toString();
        data.sn            = query.value(DAtABASEDEF::REGSN).toString();
        data.printQuantity = query.value(DAtABASEDEF::REGPRINTQUANTITY).toString();
        data.printed       = query.value(DAtABASEDEF::REGPRINTED).toString();
        data.createTime    = query.value(DAtABASEDEF::REGCREATETIME).toString();
        data.userId        = query.value(DAtABASEDEF::REGUSERID).toString();

        registerInfo << data;

        count ++;
    }

    db.close();

    return count;
}

/***************************更改数据***********************/
bool RegisterData::updateData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("update  table set('','');");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************删除数据***********************/
bool RegisterData::deleteData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("delete from table where ;");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

