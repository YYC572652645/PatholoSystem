#include "templatedata.h"
#include "../../config/qreadini.h"
#include "../globaldef.h"

/****************          构造函数              ***************/
TemplateData::TemplateData()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/****************          连接数据库            ***************/
bool TemplateData::dataCnn()
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

/****************          插入数据              ***************/
bool TemplateData::insertData(QString name, QString templateText, int type)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString Str = QString("insert into PrintTemplate values('%1','%2', '%3');").arg(name, templateText, QString::number(type));

    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/****************          查询数据              ***************/
int TemplateData::selectData(int type)
{
    int count = 0;
    if(!db.isOpen()) db.open();

    QSqlQuery query;
    QString str = QString("select * from PrintTemplate where Type = '%1';").arg(QString::number(type));
    bool success = query.exec(str);
    if(!success)  return count;

    dataTemplate.clear();

    while(query.next())
    {
        DataTemplate data;

        data.templateName = query.value(TEMPLATENAME).toString();
        data.templateText = query.value(TEMPLATETEXT).toString();

        dataTemplate.append(data);
        count ++;
    }

    db.close();

    return count;
}

/****************          更改数据              ***************/
bool TemplateData::updateData(QString name, QString templateText, int type)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString Str = QString("update  PrintTemplate set Template = '%1' where Name = '%2' and Type = '%3';").arg(templateText, name, QString::number(type));

    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/****************          删除数据              ***************/
bool TemplateData::deleteData(QString name, int type)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("delete from PrintTemplate where Name = '%1' and Type = '%2';").arg(name, QString::number(type));
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/****************          获取信息              ***************/
QList<DataTemplate> TemplateData::getDataTemplate() const
{
    return dataTemplate;
}


