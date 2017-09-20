#include "materialdata.h"
#include"config/qreadini.h"

/***************************构造函数***********************/
MaterialData::MaterialData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/***************************连接数据库*********************/
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


/***************************    插入父类数据     ***********************/
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

/***************************     插入子类数据     ***********************/
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

/***************************查询数据***********************/
int MaterialData::selectData()
{ 
    int count = 0;

    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("select * from Sampling,SamplingRow where  Sampling.SamplingId = SamplingRow.SamplingId;");

    bool success = query.exec(str);

    if(!success) return false;

    parentList.clear();
    childList.clear();

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

        DataChild dataChild;

        dataChild.samplingId        = query.value(11).toString();   //取材ID
        dataChild.sn                = query.value(12).toString();   //序号
        dataChild.embedCode         = query.value(13).toString();   //病理号子序号
        dataChild.tissue            = query.value(14).toString();   //组织名称
        dataChild.printed           = query.value(15).toString();   //是否打印
        dataChild.printTime         = query.value(16).toString();   //打印时间
        dataChild.sampled           = query.value(17).toString();   //是否取材
        dataChild.sampler           = query.value(18).toString();   //取材人
        dataChild.samplingTime      = query.value(19).toString();   //取材时间

        childList.append(dataChild);

        count ++;
    }

    db.close();

    return count;
}

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

/***************************更改数据***********************/
bool MaterialData::updateData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("update  table set('','');");

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

/***************************删除数据***********************/
bool MaterialData::deleteData()
{
    if(!db.isOpen()) db.open();

    QSqlQuery query;

    QString str = QString("delete from table where ;");

    bool success = query.exec(str);  //执行sql语句

    db.close();

    return success;
}

QList<DataChild> MaterialData::getChildList() const
{
    return childList;
}

QList<DataParent> MaterialData::getParentList() const
{
    return parentList;
}

