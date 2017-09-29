#ifndef SPECIALINDEXSETSET_H
#define SPECIALINDEXSETSET_H

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"
#include "printtemplate/templatesetup.h"

namespace Ui {
class specialindexset;
}

class SpeciaIndexSet : public QWidget
{
    Q_OBJECT

public:
    explicit SpeciaIndexSet(QWidget *parent = 0);          //构造函数
    ~SpeciaIndexSet();                                     //析构函数
    void showDialog();                                     //显示界面

private slots:
    void receiveData(QString typeName, int type);          //接收数据
    void on_pushButtonNew_clicked();                       //新建
    void on_pushButtonDelete_clicked();                    //删除
    void on_pushButtonUpdate_clicked();                    //更改
    void on_pushButtonExit_clicked();                      //退出
    void on_tableWidget_clicked(const QModelIndex &index); //点击列表
    void on_pushButtonPrint_clicked();                     //打印
    void on_pushButtonPrintAll_clicked();                  //打印所有
    void on_pushButtonTemplateSet_clicked();               //模板设置

private:
    Ui::specialindexset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值

private:
    int nowRow;                    //当前选中行
    TypeSetDialog *typeSetDialog;  //新建输入框
    TemplateSetUp *templateSetUp;  //打印模板
};

#endif // TYPESET_H
