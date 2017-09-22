#include "normalslicedata.h"
#include "config/qreadini.h"
#include "databasedef.h"
#include "globaldef.h"

/***************************构造函数***********************/
NormalSliceData::NormalSliceData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/***************************连接数据库*********************/
bool NormalSliceData::dataCnn()
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
bool NormalSliceData::insertData(DataNormalSlice data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = "insert into Section(SectionCode, EmbedCode, StainTypeName, Staining, SectionTime, Sectioner, StainTime, Stainer, PrintNum, Printed, Other) values('";

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

    str += data.other         + "' ) ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/***************************查询数据***********************/
int NormalSliceData::selectData(int type, QString text)
{
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(type == ALLDATA)
    {
        str = QString("select * from Section;");
    }
    else
    {
        str = QString("select * from Section where SectionCode like '%%1%';").arg(text);
    }

    bool success = query.exec(str);

    if(!success) return -1;

    dataList.clear();

    while(query.next())
    {
        DataNormalSlice data;

        data.sectionId     = query.value(DAtABASEDEF::SECTIONID).toString();
        data.sectionCode   = query.value(DAtABASEDEF::SECTIONCODE).toString();
        data.embedCode     = query.value(DAtABASEDEF::EMBEDCODE).toString();
        data.stainTypeName = query.value(DAtABASEDEF::STAINTYPENAME).toString();
        data.staining      = query.value(DAtABASEDEF::STAINING).toString();
        data.sectionTime   = query.value(DAtABASEDEF::SECTIONTIME).toString();
        data.sectioner     = query.value(DAtABASEDEF::SECTIONER).toString();
        data.stainTime     = query.value(DAtABASEDEF::STAINTIME).toString();
        data.stainer       = query.value(DAtABASEDEF::STAINER).toString();
        data.printNum      = query.value(DAtABASEDEF::PRINTNUM).toString();
        data.printed       = query.value(DAtABASEDEF::PRINTED).toString();
        data.other         = query.value(DAtABASEDEF::OTHER).toString();

        dataList.append(data);

        count ++;
    }

    db.close();

    return count;
}

/***************************更改数据***********************/
bool NormalSliceData::updateData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;
    QString Str = QString("update  table set('','');");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************删除数据***********************/
bool NormalSliceData::deleteData(int type, QString id)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(type == ALLDATA)
    {
        str = QString("delete from Section;");
    }
    else
    {
        str = QString("delete from Section where SectionId = '%1';").arg(id);
    }

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

QList<DataNormalSlice> NormalSliceData::getDataList() const
{
    return dataList;
}

