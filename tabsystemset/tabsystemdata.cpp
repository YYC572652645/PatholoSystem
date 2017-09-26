#include "tabsystemdata.h"
#include "config/qreadini.h"
#include "databasedef.h"
#include "globaldef.h"

TabSystemData * TabSystemData::instance = NULL;

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

/************     插入免疫组化染色类型数据            *************/
bool TabSystemData::insertStainTypeData(QString typeName, int type)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("insert into StainType (StainTypeName, Type) values('%1', '%2');").arg(typeName, QString::number(type));

    bool success = query.exec(str);

    db.close();

    return success;
}

/************     查询免疫组化染色类型数据            *************/
int TabSystemData::selectStainTypeData(int type)
{
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("select * from StainType where Type = '%1';").arg(QString::number(type));

    if(!query.exec(str)) return -1;

    StainTypeName.clear();

    while(query.next())
    {
        StainTypeName[query.value(0).toString()] = query.value(1).toString();;

        count ++;
    }

    db.close();

    return count;
}

/************     更改免疫组化染色类型数据            *************/
bool TabSystemData::updateStainTypeData(QString stainTypeName, QString stainTypeID)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString Str = QString("update  StainType set StainTypeName = '%1' where StainTypeID = '%2';").arg(stainTypeName, stainTypeID);

    bool success = query.exec(Str);

    db.close();

    return success;
}

/************     删除免疫组化染色类型数据            *************/
bool TabSystemData::deleteStainTypeData(QString stainTypeID)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString Str = QString("delete from StainType where StainTypeID = '%2';").arg(stainTypeID);

    bool success = query.exec(Str);

    db.close();

    return success;
}

/************     插入免疫组化染色指标数据            *************/
bool TabSystemData::insertStainingData(QString typeName, int type)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("insert into Staining (StainingName, Type) values('%1', '%2');").arg(typeName, QString::number(type));

    bool success = query.exec(str);

    db.close();

    return success;
}

/************     查询免疫组化染色指标数据            *************/
int TabSystemData::selectStainingData(int type)
{
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("select * from Staining where Type = '%1';").arg(QString::number(type));

    if(!query.exec(str)) return -1;

    StainingName.clear();

    while(query.next())
    {
        StainingName[query.value(0).toString()] = query.value(1).toString();;

        count ++;
    }

    db.close();

    return count;
}

/************     更改免疫组化染色指标数据            *************/
bool TabSystemData::updateStainingData(QString stainingName, QString stainingID)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString Str = QString("update  Staining set StainingName = '%1' where StainTypeID = '%2';").arg(stainingName, stainingID);

    bool success = query.exec(Str);

    db.close();

    return success;
}

/************     删除免疫组化染色指标数据            *************/
bool TabSystemData::deleteStainingData(QString stainingID)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString Str = QString("delete from Staining where StainingID = '%2';").arg(stainingID);

    bool success = query.exec(Str);

    db.close();

    return success;
}

/***************************    起始病理号设置指标数据            ***********************/
bool TabSystemData::codeBeginSelectData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "select * from SystemSetting;";

    if(!query.exec(str)) return false;

    codeBeginSnSetInfo.clear();

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

/************     打印机设置插入数据              *************/
bool TabSystemData::printInsertData(PrintData data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("insert into PrinterOption values('");

    str += data.computerID   + "' , '";

    str += data.computerName + "' , '";

    str += data.printerModel + "' , '";

    str += data.cinkModel    + "' , '";

    str += data.printerIP    + "' , '";

    str += data.printerPort  + "' , '";

    str += data.remark       + "' ) ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/************     打印机设置更新数据              *************/
bool TabSystemData::printUpdateData(PrintData data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update PrinterOption set ");

    str += "ComputerName = '"     + data.computerName + "' , ";

    str += "CinkModel = '"        + data.cinkModel    + "' , ";

    str += "PrinterIP = '"        + data.printerIP    + "' , ";

    str += "PrinterPort = '"      + data.printerPort  + "' , ";

    str += "PrinterModel = '"     + data.printerModel + "' , ";

    str += "Remark = '"           + data.remark       + "'   ";

    str += "where ComputerID = '" + data.computerID   + "' ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/************     打印机设置删除数据              *************/
bool TabSystemData::printDeleteData(QString id, QString printerName)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("delete from PrinterOption where ComputerID = '%1' and PrinterModel = '%2';").arg(id, printerName);

    if(!query.exec(str)) return false;

    db.close();

    return true;
}

/************     打印机设置查询数据              *************/
int TabSystemData::printSelectData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "select * from PrinterOption;";

    if(!query.exec(str)) return -1;

    int count = 0;

    printList.clear();

    //挨个遍历数据
    while(query.next())
    {
        PrintData data;

        data.computerID   = query.value(DAtABASEDEF::COMPUTERID).toString();
        data.computerName = query.value(DAtABASEDEF::COMPUTERNAME).toString();
        data.printerModel = query.value(DAtABASEDEF::PRINTERMODEL).toString();
        data.cinkModel    = query.value(DAtABASEDEF::CINKMODEl).toString();
        data.printerIP    = query.value(DAtABASEDEF::PRINTERIP).toString();
        data.printerPort  = query.value(DAtABASEDEF::PRINTERPORT).toString();
        data.remark       = query.value(DAtABASEDEF::PRINTREMARK).toString();

        count ++;

        printList.append(data);
    }

    db.close();

    return count;
}

/************     用户设置插入数据                *************/
bool TabSystemData::userInsertData(UserData data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("insert into User values ('");

    str += data.userName        + "' , '";

    str += data.passWord        + "' , '";

    str += data.isAdministrator + "' , '";

    str += data.authority       + "' , '";

    str += data.remark          + "' ) ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/************     用户设置更新数据                *************/
bool TabSystemData::userUpdateData(UserData data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update User set ");

    str += "Password = '"         + data.passWord         + "' , ";

    str += "IsAdministrator = '"  + data.isAdministrator  + "' , ";

    str += "Authority = '"        + data.authority        + "' , ";

    str += "Remark = '"           + data.remark           + "'   ";

    str += "where UserName = '"   + data.userName         + "' ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/************     用户设置删除数据                *************/
bool TabSystemData::userDeleteData(QString userName)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("delete from User where UserName = '%1';").arg(userName);

    if(!query.exec(str)) return false;

    db.close();

    return true;
}

/************     用户设置查询数据                *************/
int TabSystemData::userSelectData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "select * from User;";

    if(!query.exec(str)) return -1;

    int count = 0;

    userList.clear();

    while(query.next())
    {
        UserData data;

        data.userName        = query.value(DAtABASEDEF::USERNAME).toString();
        data.passWord        = query.value(DAtABASEDEF::PASSWORD).toString();
        data.isAdministrator = query.value(DAtABASEDEF::ISADMINISTRATOR).toString();
        data.authority       = query.value(DAtABASEDEF::AUTHORITY).toString();
        data.remark          = query.value(DAtABASEDEF::REMARK).toString();
        count ++;

        userList.append(data);
    }

    db.close();

    return count;
}

QMap<QString, QString> TabSystemData::getCodeBeginSnSetInfo() const
{
    return codeBeginSnSetInfo;
}

QList<CodeTypeInfo> TabSystemData::getCodeTypeInfo() const
{
    return codeTypeInfo;
}

QMap<QString, QString> TabSystemData::getStainTypeName() const
{
    return StainTypeName;
}

QMap<QString, QString> TabSystemData::getStainingName() const
{
    return StainingName;
}

QList<PrintData> TabSystemData::getPrintList() const
{
    return printList;
}

QList<UserData> TabSystemData::getUserList() const
{
    return userList;
}

