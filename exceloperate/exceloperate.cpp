#include "exceloperate.h"
#include <QFileDialog>
#include "messagebox/messagedialog.h"
#include "../databasedef.h"
#include "../globaldef.h"

ExcelOperate::ExcelOperate()
{

}

void ExcelOperate::run()
{
    switch(extendType)
    {
    case GLOBALDEF::REGTYPE:extendRegExcel();
    }
}

void ExcelOperate::extendRegExcel()
{
    /******************        创建操作excel对象      ***************/
    QAxObject *excel = NULL;
    QAxObject *workBooks = NULL;
    QAxObject *workBook = NULL;
    QAxObject *workSheets = NULL;
    QAxObject *workSheet = NULL;
    QAxObject *cell = NULL;

    if(fileName.isEmpty())  return;

    excel = new QAxObject("Excel.Application");                     //加载Excel驱动

    if(excel->isNull()) return;

    excel->setProperty("Visible", false);                           //不显示任何警告信息
    workBooks = excel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Add");
    workBook = excel->querySubObject("ActiveWorkBook");
    workSheets = workBook->querySubObject("Sheets");                //Sheets可换做WorkSheets
    workSheet = workBook->querySubObject("Sheets(int)", 1);         //读取第一个工作表中的内容

    for(int i = 1; i < itemName.size() + 1; i ++)
    {
        cell = workSheet->querySubObject("Cells(int, int)", 1, i);  //循环获取单元格中数据
        cell->setProperty("Value", itemName.at(i - 1));             //写单元格值
        cell->clear();
    }

    const static int STARTROW = 2;    //数据开始行数

    /*******************              写入单元格数据             *******************/
    for(int i = STARTROW; i < registerInfo.size() + STARTROW; i ++)
    {
        for(int j = 1; j < itemName.size() + 1; j ++)
        {
            cell->clear();
            cell = workSheet->querySubObject("Cells(int, int)", i, j); //循环获取单元格中数据

            int dataCount = i - STARTROW;

            switch(j)
            {
            case DAtABASEDEF::REGPCODE:        cell->setProperty("Value", registerInfo.at(dataCount).pCode);          break;
            case DAtABASEDEF::REGSN:           cell->setProperty("Value", registerInfo.at(dataCount).sn);             break;
            case DAtABASEDEF::REGPRINTQUANTITY:cell->setProperty("Value", registerInfo.at(dataCount).printQuantity);  break;
            case DAtABASEDEF::REGPRINTED:      cell->setProperty("Value", registerInfo.at(dataCount).printed);        break;
            case DAtABASEDEF::REGCREATETIME:   cell->setProperty("Value", registerInfo.at(dataCount).createTime);     break;
            }
        }
    }

    workBook->dynamicCall("SaveAs(const Qstring&)", QDir::toNativeSeparators(fileName)); //保存文件
    workBook->dynamicCall("Close(Boolen)", false);                                       //关闭
    excel->dynamicCall("Quit(void)");                                                    //退出
}

void ExcelOperate::setItemName(const QList<QString> &value)
{
    itemName = value;
}

void ExcelOperate::setRegisterInfo(const QList<RegisterInfo> &value)
{
    registerInfo = value;
}

void ExcelOperate::setExtendType(int value)
{
    extendType = value;
}

void ExcelOperate::setFileName(const QString &value)
{
    fileName = value;
}
