#include "exceloperate.h"
#include <QFileDialog>
ExcelOperate::ExcelOperate()
{

}

void ExcelOperate::extendExcel(QList<QString>itemName, QList<RegisterInfo> registerInfo)
{
    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheets=NULL;
    workSheet=NULL;


    QString fileName = QFileDialog::getSaveFileName(NULL, "保存文件",".","Excel(*.xlsx *.xls)");
    if(fileName.isEmpty())  return;

    excel = new QAxObject("Excel.Application");            //加载Excel驱动
    excel->setProperty("Visible",false);                   //不显示任何警告信息
    workBooks = excel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Add");
    workBook = excel->querySubObject("ActiveWorkBook");
    workSheets = workBook->querySubObject("Sheets");       //Sheets可换做WorkSheets
    workSheet = workBook->querySubObject("Sheets(int)",1); //读取第一个工作表中的内容

    QAxObject *cell = NULL;

//    for(int i = 1; i < itemName.size() + 1; i ++)
//    {
//        cell = workSheet->querySubObject("Cells(int,int)",1,i); //循环获取单元格中数据
//        cell->setProperty("Value",itemName.at(i - 1));          //写单元格值
//        cell->clear();
//    }


//    /*******************************写入单元格数据***************************/
//    for(int i=2;i<dataBaseCount+2;i++)
//    {
//        for(int j = 1;j < 32; j ++)
//        {
//            cell->clear();
//            cell = workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据

//            dataCount=i-2;

//            switch(j)
//            {
//            case 1:cell->setProperty("Value",data.studentMessage[dataCount].name);     break;    //写单元格值
//            }
//        }
//    }


    workBook->dynamicCall("SaveAs(const Qstring&)",QDir::toNativeSeparators(fileName));//保存文件
    workBook->dynamicCall("Close(Boolen)",false);  //关闭
    excel->dynamicCall("Quit(void)");              //退出


    SAFEDELETE(cell);
    SAFEDELETE(workBooks);
    SAFEDELETE(excel);
    SAFEDELETE(workBook);
    SAFEDELETE(workSheets);
    SAFEDELETE(workSheet);
}
