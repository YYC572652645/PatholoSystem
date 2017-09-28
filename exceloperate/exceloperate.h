#ifndef EXCELOPERATE_H
#define EXCELOPERATE_H
#include <QAxObject>
#include "globaldef.h"
#include "tabmaterial/materialdata.h"
#include <QThread>
#include <QMutex>

class ExcelOperate : public QThread
{
public:
    ExcelOperate();

    void run();

    void extendRegExcel();         //导出登记信息

    void extendSampleExcel();      //导出取材信息

    void extendStatisticsExcel();  //导出取材统计信息

    void setItemName(const QList<QString> &value);

    void setRegisterInfo(const QList<RegisterInfo> &value);

    void setExtendType(int value);

    void setFileName(const QString &value);

    void setChildInfo(const QList<DataChild> &value);

    void setStatisticsList(const QList<DataStatistics> &value);

private:
    QList<QString>itemName;
    QList<RegisterInfo> registerInfo;
    QList<DataChild> childInfo;
    QList<DataStatistics>statisticsList;

    int extendType;
    QString fileName;

    QMutex mutex;
};

#endif // EXCELOPERATE_H
