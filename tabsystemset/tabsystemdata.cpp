#include "tabsystemdata.h"
#include "config/qreadini.h"
#include "databasedef.h"
#include "globaldef.h"

/***************************构造函数***********************/
TabSystemData::TabSystemData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/***************************连接数据库*********************/
bool TabSystemData::dataCnn()
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
    if(db.isOpen())
    {
        db.close();
    }
    return db.open();
}

/***************************    插入数据                        ***********************/
bool TabSystemData::insertData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("insert into table values('','');");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************    起始病理号设置查询数据            ***********************/
bool TabSystemData::codeBeginSelectData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "select * from SystemSetting;";

    if(!query.exec(str)) return false;

    while(query.next())        //挨个遍历数据
    {
        codeBeginSnSetInfo[query.value(DAtABASEDEF::CODEBEGINNAME).toString()] = query.value(DAtABASEDEF::CODEBEGINVALUE).toString();
    }

    db.close();

    return true;
}

/***************************    起始病理号设置更改数据            ***********************/
bool TabSystemData::codeBeginUpdateData(QString name, QString value)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString Str = QString("update  SystemSetting set Value = '%1' where Name = '%2';").arg(value, name);

    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************    标本类别设置查询数据              ***********************/
bool TabSystemData::codeTypeSelectData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "select * from PCodeType;";

    if(!query.exec(str)) return false;

    codeTypeInfo.clear();

    //挨个遍历数据
    while(query.next())
    {
        CodeTypeInfo codeData;

        codeData.codeTypeID = query.value(DAtABASEDEF::CODETYPEID).toString();
        codeData.codeTypeAbbr = query.value(DAtABASEDEF::CODETYPEABBR).toString();
        codeData.codeTypeName = query.value(DAtABASEDEF::CODETYPENAME).toString();

        codeTypeInfo.append(codeData);
    }

    db.close();

    return true;
}

/***************************    标本类别设置更改数据              ***********************/
bool TabSystemData::codeTypeUpdateData(QString typeAbbreviation, QString typeName, QString typeId)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;
    QString Str = QString("update  PCodeType set PCodeTypeAbbr = '%1', PCodeTypeName = '%2' where PCodeTypeID = '%3';").arg(typeAbbreviation, typeName, typeId);

    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************    标本类别设置删除数据              ***********************/
bool TabSystemData::codeTypeDeleteData(QString id)
{
    if(id.isEmpty()) return false;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString Str = QString("delete from PCodeType where PCodeTypeID = '%1';").arg(id);

    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************    标本类别设置插入数据              ***********************/
bool TabSystemData::codeTypeInsertData(QString typeAbbreviation, QString typeName)
{
    if(typeAbbreviation.isEmpty() || typeName.isEmpty()) return false;
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString str = QString("insert into pCodeType(PCodeTypeAbbr, PCodeTypeName) values('%1','%2');").arg(typeAbbreviation, typeName);

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

QMap<QString, QString> TabSystemData::getCodeBeginSnSetInfo() const
{
    return codeBeginSnSetInfo;
}

QList<CodeTypeInfo> TabSystemData::getCodeTypeInfo() const
{
    return codeTypeInfo;
}

