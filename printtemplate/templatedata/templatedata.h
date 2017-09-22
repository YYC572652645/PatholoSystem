#ifndef DATABASE_H
#define DATABASE_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>

#define TEMPLATEDATA TemplateData::getInstance()

typedef struct DataTemplate
{
    QString templateName;
    QString templateText;
}DataTemplate;


class TemplateData
{
public:

    static TemplateData * getInstance()
    {
        if(NULL == instance)
        {
            instance = new TemplateData();
        }

        return instance;
    }

    /************构造函数*************/
    TemplateData();

    /************连接数据库*************/
    bool dataCnn();

    /************插入数据*************/
    bool insertData(QString name, QString templateText, int type);

    /************查询数据*************/
    int selectData(int type);

    /************更改数据*************/
    bool updateData(QString name, QString templateText, int type);

    /************删除数据*************/
    bool deleteData(QString name, int type);

    QList<DataTemplate> getDataTemplate() const;

private:
    static TemplateData * instance; //单例模式
    QSqlDatabase db;                //定义数据库对象

    QList<DataTemplate> dataTemplate;

};

#endif // DATABASE_H
