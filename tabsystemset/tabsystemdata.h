#ifndef TABSYSTEMDATA_H
#define TABSYSTEMDATA_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>

typedef struct UserData
{
    QString userName;
    QString passWord;
    QString isAdministrator;
    QString authority;
    QString remark;

}UserData;

/***************************************************************
   功能:登录框

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#define SYSTEMDATA TabSystemData::getInstance()

//标本类别设置信息
typedef struct CodeTypeInfo
{
    QString codeTypeID;
    QString codeTypeAbbr;
    QString codeTypeName;

}CodeTypeInfo;

typedef struct PrintData
{
    QString computerID;
    QString computerName;
    QString cinkModel;
    QString printerIP;
    QString printerPort;
    QString printerModel;
    QString remark;
}PrintData;


class TabSystemData
{
public:
    static TabSystemData * getInstance()
    {
        if(NULL == instance)
        {
             instance = new TabSystemData();
        }

        return instance;
    }

    /************     构造函数                      *************/
    TabSystemData();

    /************     连接数据库                     *************/
    bool dataCnn();

    /************     插入数据                       *************/
    bool insertData();

    /************     插入免疫组化染色类型数据          *************/
    bool insertStainTypeData(QString typeName, int type);

    /************     查询免疫组化染色类型数据          *************/
    int selectStainTypeData(int type);

    /************     更改免疫组化染色类型数据          *************/
    bool updateStainTypeData(QString stainTypeName, QString stainTypeID);

    /************     删除免疫组化染色类型数据          *************/
    bool deleteStainTypeData(QString stainTypeID);

    /************     插入免疫组化染色指标数据          *************/
    bool insertStainingData(QString typeName, int type);

    /************     查询免疫组化染色指标数据          *************/
    int selectStainingData(int type);

    /************     更改免疫组化染色指标数据          *************/
    bool updateStainingData(QString stainingName, QString stainingID);

    /************     删除免疫组化染色指标数据          *************/
    bool deleteStainingData(QString stainingID);

    /************     起始病理号设置查询数据           *************/
    bool codeBeginSelectData();

    /************     起始病理号设置更改数据           *************/
    bool codeBeginUpdateData(QString name, QString value);

    /************     标本类别设置查询数据             *************/
    bool codeTypeSelectData();

    /************     标本类别设置更改数据             *************/
    bool codeTypeUpdateData(QString typeAbbreviation, QString typeName, QString typeId);

    /************     标本类别设置删除数据              *************/
    bool codeTypeDeleteData(QString id);

    /************     标本类别设置插入数据              *************/
    bool codeTypeInsertData(QString typeAbbreviation, QString typeName);

    /************     打印机设置插入数据              *************/
    bool printInsertData(PrintData data);

    /************     打印机设置更新数据              *************/
    bool printUpdateData(PrintData data);

    /************     打印机设置删除数据              *************/
    bool printDeleteData(QString id, QString printerName);

    /************     打印机设置查询数据              *************/
    int printSelectData();

    /************     用户设置插入数据                *************/
    bool userInsertData(UserData data);

    /************     用户设置更新数据                *************/
    bool userUpdateData(UserData data);

    /************     用户设置删除数据                *************/
    bool userDeleteData(QString userName);

    /************     用户设置查询数据                *************/
    int userSelectData();

public:
    QMap<QString, QString> getCodeBeginSnSetInfo() const;  //获取起始病理号设置信息
    QList<CodeTypeInfo> getCodeTypeInfo() const;           //获取标本类别设置信息
    QMap<QString, QString> getStainTypeName() const;       //获取免疫组化染色类型信息
    QMap<QString, QString> getStainingName() const;        //获取免疫组化染色指标信息
    QList<PrintData> getPrintList() const;                 //打印机设置信息
    QList<UserData> getUserList() const;                   //用户信息
    QMap<QString, QString> getSpecialingName() const;      //获取特殊染色指标信息
    QMap<QString, QString> getSpecialTypeName() const;     //获取特殊染色类型信息

private:
    QSqlDatabase db;                                       //定义数据库对象
    static TabSystemData * instance;                       //单例模式
    QMap<QString, QString>codeBeginSnSetInfo;              //起始病理号设置
    QList<CodeTypeInfo> codeTypeInfo;                      //标本类别设置信息
    QMap<QString, QString>StainTypeName;                   //免疫组化染色类型
    QMap<QString, QString>StainingName;                    //免疫组化染色指标
    QMap<QString, QString>SpecialTypeName;                 //特殊染色类型
    QMap<QString, QString>SpecialingName;                  //特殊染色指标
    QList<PrintData> printList;                            //打印机设置信息
    QList<UserData>  userList;                             //用户信息

};

#endif // TABSYSTEMDATA_H
