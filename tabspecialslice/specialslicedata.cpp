#include "specialslicedata.h"
#include"config/qreadini.h"
#include "databasedef.h"
#include "globaldef.h"

SpecialSliceData * SpecialSliceData::instance = NULL;

/***************************构造函数***********************/
SpecialSliceData::SpecialSliceData()
{
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/***************************连接数据库*********************/
bool SpecialSliceData::dataCnn()
{
    //是否为默认连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase(DATACONFIG.dataBaseVersion);         //设置数据库类型
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
bool SpecialSliceData::insertData(DataSpecialSlice data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "insert into SectionSs(SectionCode, EmbedCode, StainTypeName, Staining, SectionTime, Sectioner, StainTime, Stainer, PrintNum, Printed, CloneNo) values('";

    str += data.sectionCode   + "' , '";

    str += data.embedCode     + "' , '";

    str += data.stainTypeName + "' , '";

    str += data.staining      + "' , '";

    str += data.sectionTime   + "' , '";

    str += data.sectioner     + "' , '";

    str += data.stainTime     + "' , '";

    str += data.stainer       + "' , '";

    str += data.printNum      + "' , '";

    str += data.printed       + "' , '";

    str += data.cloneNumber   + "' ) ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/***************************查询数据***********************/
int SpecialSliceData::selectData(int type, QString text)
{
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(type == ALLDATA)
    {
        str = QString("select * from SectionSs;");
    }
    else
    {
        str = QString("select * from SectionSs where SectionCode like '%%1%';").arg(text);
    }

    bool success = query.exec(str);

    if(!success) return -1;

    dataList.clear();

    while(query.next())
    {
        DataSpecialSlice data;

        data.sectionId     = query.value(DAtABASEDEF::SSSECTIONID).toString();
        data.sectionCode   = query.value(DAtABASEDEF::SSSECTIONCODE).toString();
        data.embedCode     = query.value(DAtABASEDEF::SSEMBEDCODE).toString();
        data.stainTypeName = query.value(DAtABASEDEF::SSSTAINTYPENAME).toString();
        data.staining      = query.value(DAtABASEDEF::SSSTAINING).toString();
        data.sectionTime   = query.value(DAtABASEDEF::SSSECTIONTIME).toString();
        data.sectioner     = query.value(DAtABASEDEF::SSSECTIONER).toString();
        data.stainTime     = query.value(DAtABASEDEF::SSSTAINTIME).toString();
        data.stainer       = query.value(DAtABASEDEF::SSSTAINER).toString();
        data.printNum      = query.value(DAtABASEDEF::SSPRINTNUM).toString();
        data.printed       = query.value(DAtABASEDEF::SSPRINTED).toString();
        data.cloneNumber   = query.value(DAtABASEDEF::SSCLONENO).toString();

        dataList.append(data);

        count ++;
    }

    db.close();

    return count;
}

/***************************更改数据***********************/
bool SpecialSliceData::updateData(DataSpecialSlice data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update SectionSs set ");

    str += "SectionCode = '"     + data.sectionCode   + "', ";

    str += "EmbedCode = '"       + data.embedCode     + "', ";

    str += "StainTypeName = '"   + data.stainTypeName + "', ";

    str += "Staining = '"        + data.staining      + "', ";

    str += "SectionTime = '"     + data.sectionTime   + "', ";

    str += "Sectioner = '"       + data.sectioner     + "', ";

    str += "StainTime = '"       + data.stainTime     + "', ";

    str += "Stainer = '"         + data.stainer       + "', ";

    str += "PrintNum = '"        + data.printNum      + "', ";

    str += "Printed = '"         + data.printed       + "', ";

    str += "CloneNo = '"         + data.cloneNumber   + "'  ";

    str += "where SectionId = '" + data.sectionId     + "' ;";

    qDebug()<<str;
    bool success = query.exec(str);

    db.close();

    return success;
}

/***************************删除数据***********************/
bool SpecialSliceData::deleteData(int type, QString id)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(type == ALLDATA)
    {
        str = QString("delete from SectionSs;");
    }
    else
    {
        str = QString("delete from SectionSs where SectionId = '%1';").arg(id);
    }

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

QList<DataSpecialSlice> SpecialSliceData::getDataList() const
{
    return dataList;
}

