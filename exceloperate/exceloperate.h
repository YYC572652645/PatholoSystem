#ifndef EXCELOPERATE_H
#define EXCELOPERATE_H
#include <QAxObject>
#include "globaldef.h"
#include "singleton/singleton.h"

#define EXCEL  Singleton<ExcelOperate>::getInstance()

class ExcelOperate
{
public:
    ExcelOperate();
    void extendExcel(QList<QString> itemName, QList<RegisterInfo> registerInfo);  //导出Excel

private:

    /********************创建操作excel对象*****************/
    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *workSheets;
    QAxObject *workSheet;
};

#endif // EXCELOPERATE_H
