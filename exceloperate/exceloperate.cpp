#include "exceloperate.h"
#include <QFileDialog>
#include "messagebox/messagedialog.h"
#include "../databasedef.h"
#include "../globaldef.h"

/****************          构造函数                ***************/
ExcelOperate::ExcelOperate()
{

}

/****************          线程运行函数            ***************/
void ExcelOperate::run()
{
    mutex.lock();

    extendExcel();

    mutex.unlock();
}

/****************          导出Excel信息           ***************/
void ExcelOperate::extendExcel()
{
    //创建操作excel对象
    QAxObject *excel      = NULL;
    QAxObject *workBooks  = NULL;
    QAxObject *workBook   = NULL;
    QAxObject *workSheets = NULL;
    QAxObject *workSheet  = NULL;
    QAxObject *cell       = NULL;

    if(fileName.isEmpty())  return;

    //加载Excel驱动
    excel = new QAxObject("Excel.Application");

    //如果加载失败，关闭线程返回
    if(excel->isNull())
    {
        this->terminate();
        return;
    }

    //不显示任何警告信息
    excel->setProperty("Visible", false);
    workBooks = excel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Add");
    workBook = excel->querySubObject("ActiveWorkBook");

    //Sheets可换做WorkSheets
    workSheets = workBook->querySubObject("Sheets");

    //读取第一个工作表中的内容
    workSheet = workBook->querySubObject("Sheets(int)", 1);

    //写入表头信息
    for(int i = 1; i < itemName.size() + 1; i ++)
    {
        cell = workSheet->querySubObject("Cells(int, int)", 1, i);
        cell->setProperty("Value", itemName.at(i - 1));
        cell->clear();
    }

    //写入单元格数据
    for(int i = STARTROW; i < statisticsList.size() + STARTROW; i ++)
    {
        for(int j = 1; j < itemName.size() + 1; j ++)
        {
            cell->clear();
            cell = workSheet->querySubObject("Cells(int, int)", i, j);

            int dataCount = i - STARTROW;


            //登记信息
            if(extendType == GLOBALDEF::REGTYPE)
            {
                switch(j)
                {
                case DATABASEDEF::REGPCODE:        cell->setProperty("Value", registerInfo.at(dataCount).pCode);          break;
                case DATABASEDEF::REGSN:           cell->setProperty("Value", registerInfo.at(dataCount).sn);             break;
                case DATABASEDEF::REGPRINTQUANTITY:cell->setProperty("Value", registerInfo.at(dataCount).printQuantity);  break;
                case DATABASEDEF::REGPRINTED:      cell->setProperty("Value", registerInfo.at(dataCount).printed);        break;
                case DATABASEDEF::REGCREATETIME:   cell->setProperty("Value", registerInfo.at(dataCount).createTime);     break;
                }
            }

            //取材信息
            else if(extendType == GLOBALDEF::MATERIALTYPE)
            {
                switch(j - 1)
                {
                case NUMBERING:        cell->setProperty("Value", childInfo.at(dataCount).embedCode);     break;
                case SERIALNUMBER:     cell->setProperty("Value", childInfo.at(dataCount).sn);            break;
                case ORGANIZATIONNAME: cell->setProperty("Value", childInfo.at(dataCount).tissue);        break;
                case ISPRINTED:        cell->setProperty("Value", childInfo.at(dataCount).printed);       break;
                case PRINTTIME:        cell->setProperty("Value", childInfo.at(dataCount).printTime);     break;
                case ISMATERIAL:       cell->setProperty("Value", childInfo.at(dataCount).sampled);       break;
                case MATERIALTIME:     cell->setProperty("Value", childInfo.at(dataCount).sampler);       break;
                case MATERIALPEOPLE:   cell->setProperty("Value", childInfo.at(dataCount).samplingTime);  break;
                }
            }

            //统计信息
            else
            {
                switch(j - 1)
                {
                case DATABASEDEF::DATE:           cell->setProperty("Value", statisticsList.at(dataCount).date);            break;
                case DATABASEDEF::MATERIALTOTAL:  cell->setProperty("Value", statisticsList.at(dataCount).materialTotal);   break;
                case DATABASEDEF::EMBEDDINGTOTAL: cell->setProperty("Value", statisticsList.at(dataCount).embeddingTotal);  break;
                case DATABASEDEF::NORMALMTLTOTAL: cell->setProperty("Value", statisticsList.at(dataCount).normalMtlTotal);  break;
                case DATABASEDEF::NORMALEDDTOTAL: cell->setProperty("Value", statisticsList.at(dataCount).normalEddTotal);  break;
                case DATABASEDEF::FROZENMTLTOTAL: cell->setProperty("Value", statisticsList.at(dataCount).frozenMtlTotal);  break;
                case DATABASEDEF::FROZENEDDTOTAL: cell->setProperty("Value", statisticsList.at(dataCount).frozenEddTotal);  break;
                }
            }


        }
    }

    workBook->dynamicCall("SaveAs(const Qstring&)", QDir::toNativeSeparators(fileName)); //保存文件
    workBook->dynamicCall("Close(Boolen)", false);                                       //关闭
    excel->dynamicCall("Quit(void)");                                                    //退出
}

/****************          设置表头信息             ***************/
void ExcelOperate::setItemName(const QList<QString> &value)
{
    itemName = value;
}

/****************          设置登记信息             ***************/
void ExcelOperate::setRegisterInfo(const QList<RegisterInfo> &value)
{
    registerInfo = value;
}

/****************          设置导出类型             ***************/
void ExcelOperate::setExtendType(int value)
{
    extendType = value;
}

/****************          设置文件名称             ***************/
void ExcelOperate::setFileName(const QString &value)
{
    fileName = value;
}

/****************          设置取材信息             ***************/
void ExcelOperate::setChildInfo(const QList<DataChild> &value)
{
    childInfo = value;
}

/****************          设置统计信息             ***************/
void ExcelOperate::setStatisticsList(const QList<DataStatistics> &value)
{
    statisticsList = value;
}
