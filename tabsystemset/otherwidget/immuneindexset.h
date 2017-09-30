#ifndef IMMUNEINDEXSET_H
#define IMMUNEINDEXSET_H

/***************************************************************
   功能:免疫组化切片指标设置

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"
#include "printtemplate/templatesetup.h"

namespace Ui {
class immuneindexset;
}

class ImmuneIndexSet : public QWidget
{
    Q_OBJECT

public:
    explicit ImmuneIndexSet(QWidget *parent = 0);
    ~ImmuneIndexSet();

    void showDialog();

private slots:
    void receiveData(QString typeName, int type);          //接收数据
    void on_pushButtonNew_clicked();                       //新建
    void on_pushButtonDelete_clicked();                    //删除
    void on_pushButtonUpdate_clicked();                    //更改
    void on_pushButtonExit_clicked();                      //退出
    void on_tableWidget_clicked(const QModelIndex &index); //列表点击
    void on_pushButtonTemplateSet_clicked();               //设置模板
    void on_pushButtonPrint_clicked();                     //点击打印
    void on_pushButtonPrintAll_clicked();                  //打印所有

private:
    Ui::immuneindexset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值

private:
    int nowRow;                    //当前选中行
    TypeSetDialog *typeSetDialog;  //新建输入框
    TemplateSetUp *templateSetUp;  //打印模板
};

#endif // TYPESET_H
