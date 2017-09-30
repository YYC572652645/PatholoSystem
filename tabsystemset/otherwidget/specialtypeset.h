#ifndef SPECIATYPESET_H
#define SPECIATYPESET_H

/***************************************************************
   功能:特染切片类型设置

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"

namespace Ui {
class speciatypeset;
}

class SpeciaTypeSet : public QWidget
{
    Q_OBJECT

public:
    explicit SpeciaTypeSet(QWidget *parent = 0);           //构造函数
    ~SpeciaTypeSet();                                      //析构函数
    void showDialog();                                     //显示界面

private slots:
    void receiveData(QString typeName, int type);           //接收数据
    void on_pushButtonNew_clicked();                        //新建
    void on_pushButtonDelete_clicked();                     //删除
    void on_pushButtonUpdate_clicked();                     //更改
    void on_pushButtonExit_clicked();                       //退出
    void on_tableWidget_clicked(const QModelIndex &index);  //列表点击

private:
    Ui::speciatypeset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值

private:
    int nowRow;                   //当前选中行
    TypeSetDialog *typeSetDialog; //新建输入框
};

#endif // TYPESET_H
