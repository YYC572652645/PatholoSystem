#include "materialdata.h"
#include"config/qreadini.h"
#include "databasedef.h"

MaterialData * MaterialData::instance = NULL;

/****************          构造函数                 ***************/
MaterialData::MaterialData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/****************          连接数据库                ***************/
bool MaterialData::dataCnn()
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

/****************          插入父类数据              ***************/
bool MaterialData::insertParentData(DataParent data)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString str = "insert into Sampling values('";

    str += data.samplingId       + "' , '";

    str += data.pCode            + "' , '";

    str += data.specimenName     + "' , '";

    str += data.specimenQuantity + "' , '";

    str += data.specimenSize     + "' , '";

    str += data.specimenWeight   + "' , '";

    str += data.samplingCount    + "' , '";

    str += data.sampler          + "' , '";

    str += data.note             + "' , '";

    str += data.noter            + "' , '";

    str += data.createTime       + "') ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/****************          插入子类数据              ***************/
bool MaterialData::insertChildData(DataChild data)
{
    if(!db.isOpen())  db.open();

    QSqlQuery query;

    QString str = "insert into SamplingRow values('";

    str += data.samplingId       + "' , '";

    str += data.sn               + "' , '";

    str += data.embedCode        + "' , '";

    str += data.tissue           + "' , '";

    str += data.printed          + "' , '";

    str += data.printTime        + "' , '";

    str += data.sampled          + "' , '";

    str += data.sampler          + "' , '";

    str += data.samplingTime     + "') ;";

    bool success = query.exec(str);

    db.close();

    return success;
}

/****************          查询数据                 ***************/
bool MaterialData::selectData(int type, QString number)
{ 
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(type == ALLDATA)
    {
        str = QString("select * from Sampling;");
    }
    else
    {
        str = QString("select * from Sampling where PCode like '%%1%';").arg(number);
    }

    bool success = query.exec(str);

    if(!success) return success;

    parentList.clear();

    while(query.next())
    {
        DataParent dataParent;

        dataParent.samplingId       = query.value(0).toString();    //取材ID
        dataParent.pCode            = query.value(1).toString();    //病理号
        dataParent.specimenName     = query.value(2).toString();    //标本名称
        dataParent.specimenQuantity = query.value(3).toString();    //标本数量
        dataParent.specimenSize     = query.value(4).toString();    //标本大小
        dataParent.specimenWeight   = query.value(5).toString();    //标本重量
        dataParent.samplingCount    = query.value(6).toString();    //取材总数
        dataParent.sampler          = query.value(7).toString();    //取材人
        dataParent.note             = query.value(8).toString();    //检测记录
        dataParent.noter            = query.value(9).toString();    //记录人
        dataParent.createTime       = query.value(10).toString();   //取材时间

        parentList.append(dataParent);
    }

    childList.clear();

    if(type == ALLDATA)
    {
        str = QString("select * from SamplingRow;");
    }
    else
    {
        str = QString("select * from SamplingRow where EmbedCode like '%%1%';").arg(number);
    }

    success = query.exec(str);

    if(!success) return success;

    while(query.next())
    {
        DataChild dataChild;

        dataChild.samplingId        = query.value(0).toString();   //取材ID
        dataChild.sn                = query.value(1).toString();   //序号
        dataChild.embedCode         = query.value(2).toString();   //病理号子序号
        dataChild.tissue            = query.value(3).toString();   //组织名称
        dataChild.printed           = query.value(4).toString();   //是否打印
        dataChild.printTime         = query.value(5).toString();   //打印时间
        dataChild.sampled           = query.value(6).toString();   //是否取材
        dataChild.sampler           = query.value(7).toString();   //取材人
        dataChild.samplingTime      = query.value(8).toString();   //取材时间

        childList.append(dataChild);
    }

    db.close();

    return success;
}

/****************          查询病理号                ***************/
QString MaterialData::selectCode(QString blNumber)
{
    QString pCode;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("select PCode from Reg where Sn = '%1';").arg(blNumber);

    bool success = query.exec(str);

    if(!success) return false;

    if(query.next())
    {
        pCode = query.value(0).toString();
    }

    db.close();

    return pCode;
}

/****************          查询包埋数                ***************/
int MaterialData::selectBaoMai(QString blNumber)
{
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("select count(*) from SamplingRow where SamplingId = '%1';").arg(blNumber);

    bool success = query.exec(str);

    if(!success) return false;

    if(query.next())
    {
        count = query.value(0).toInt();
    }

    db.close();

    return count;
}

/****************          查询统计数据               ***************/
int MaterialData::selectStatistics(QString beginTime, QString endTime)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    if(beginTime.isEmpty())
    {
        str = QString("select strftime('%Y-%m-%d',CreateTime), count(*), sum(SamplingCount), count(*),sum(SamplingCount) from Sampling group by strftime('%Y-%m-%d',CreateTime);");
    }
    else
    {
        str = QString("select strftime('%Y-%m-%d',CreateTime), count(*), sum(SamplingCount), count(*),sum(SamplingCount) from Sampling where CreateTime >= '%1' and CreateTime <= '%2'").arg(beginTime, endTime);
    }

    bool success = query.exec(str);

    if(!success) return -1;

    int count = 0;

    statisticsList.clear();

    while(query.next())
    {
        DataStatistics data;

        data.date           = query.value(DATABASEDEF::DATE).toString();              //日期
        data.materialTotal  = query.value(DATABASEDEF::MATERIALTOTAL).toString();     //取材总例数
        data.embeddingTotal = query.value(DATABASEDEF::EMBEDDINGTOTAL).toString();    //包埋总数
        data.normalMtlTotal = query.value(DATABASEDEF::NORMALMTLTOTAL).toString();    //常规取材例数
        data.normalEddTotal = query.value(DATABASEDEF::NORMALEDDTOTAL).toString();    //常规包埋数

        statisticsList.append(data);

        count ++;
    }

    db.close();

    return count;
}

/****************          更改子类数据               ***************/
bool MaterialData::updateChildData(DataChild data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update  SamplingRow set ");

    str += "Tissue = '"           +  data.tissue       + "', ";

    str += "Printed = '"          +  data.printed      + "', ";

    str += "Sampled = '"          +  data.sampled      + "', ";

    str += "Operator = '"         +  data.sampler      + "', ";

    str += "PrintTime = '"        +  data.printTime    + "', ";

    str += "SamplingTime = '"     +  data.samplingTime + "'  ";

    str += "where EmbedCode = '"  +  data.embedCode     + "'; ";

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/****************          更改父类数据               ***************/
bool MaterialData::updateParentData(DataParent data)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update  Sampling set ");

    str += "SpecimenName = '"      +  data.specimenName     + "', ";

    str += "SpecimenQuantity = '"  +  data.specimenQuantity + "', ";

    str += "SpecimenSize = '"      +  data.specimenSize     + "', ";

    str += "SpecimenWeight = '"    +  data.specimenWeight   + "',  ";

    str += "SamplingCount = '"     +  data.samplingCount    + "',  ";

    str += "Sampler = '"           +  data.sampler          + "',  ";

    str += "Note = '"              +  data.note             + "',  ";

    str += "Noter = '"             +  data.noter            + "',  ";

    str += "CreateTime = '"        +  data.createTime       + "'  ";

    str += "where PCode = '"       +  data.pCode            + "'; ";

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/****************          删除所有数据               ***************/
bool MaterialData::deleteData(int type, QString id, QString embedCode)
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str;

    bool success = false;

    if(type == ALLDATA)
    {
        str = QString("delete from Sampling;");

        success = query.exec(str);

        str = QString("delete from SamplingRow;");

        success = query.exec(str);
    }
    else if(type == BLDATA)
    {
        str = QString("delete from Sampling where SamplingId = '%1';").arg(id);

        success = query.exec(str);

        str = QString("delete from SamplingRow where SamplingId = '%1';").arg(id);

        success = query.exec(str);
    }
    else
    {
        str = QString("delete from SamplingRow where SamplingId = '%1' and EmbedCode = '%2';").arg(id, embedCode);

        success = query.exec(str);
    }

    db.close();

    return success;
}

/****************          获取子节点数据             ***************/
QList<DataChild> MaterialData::getChildList() const
{
    return childList;
}

/****************          获取父节点数据             ***************/
QList<DataParent> MaterialData::getParentList() const
{
    return parentList;
}

/****************          获取统计数据               ***************/
QList<DataStatistics> MaterialData::getStatisticsList() const
{
    return statisticsList;
}

