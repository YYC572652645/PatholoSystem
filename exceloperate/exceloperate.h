#ifndef EXCELOPERATE_H
#define EXCELOPERATE_H

/***************************************************************
   功能:导出Excel文件

   创建人:殷宇辰

   创建时间:2017-9-20
**************************************************************/

#include <QAxObject>
#include "globaldef.h"
#include "tabmaterial/materialdata.h"
#include <QThread>
#include <QMutex>

class ExcelOperate : public QThread
{
public:
    ExcelOperate();

    void run();                    //线程函数
    void extendExcel();            //导出Excel


    void setItemName(const QList<QString> &value);              //设置表头名称
    void setRegisterInfo(const QList<RegisterInfo> &value);     //设置登记信息
    void setExtendType(int value);                              //设置导出类型
    void setFileName(const QString &value);                     //设置文件名称
    void setChildInfo(const QList<DataChild> &value);           //设置取材信息
    void setStatisticsList(const QList<DataStatistics> &value); //设置统计信息

private:
    QList<QString>itemName;              //表头名称
    QList<RegisterInfo> registerInfo;    //登记信息
    QList<DataChild> childInfo;          //取材信息
    QList<DataStatistics>statisticsList; //统计信息

    int extendType;                      //导出类型
    QString fileName;                    //文件名称
    QMutex mutex;                        //互斥锁

    const static int STARTROW = 2;       //数据开始行数
};

#endif // EXCELOPERATE_H
