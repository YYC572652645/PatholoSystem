#ifndef EXCELOPERATE_H
#define EXCELOPERATE_H
#include <QAxObject>
#include "globaldef.h"
#include "singleton/singleton.h"
#include <QThread>
#include <QMutex>

class ExcelOperate : public QThread
{
public:
    ExcelOperate();

    void run();

    void extendRegExcel();

    void setItemName(const QList<QString> &value);

    void setRegisterInfo(const QList<RegisterInfo> &value);

    void setExtendType(int value);

    void setFileName(const QString &value);

private:
    QList<QString>itemName;
    QList<RegisterInfo> registerInfo;
    int extendType;
    QString fileName;
};

#endif // EXCELOPERATE_H
