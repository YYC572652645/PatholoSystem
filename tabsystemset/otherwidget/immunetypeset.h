#ifndef IMMUNETYPESET_H
#define IMMUNETYPESET_H

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"

namespace Ui {
class immunetypeset;
}

class ImmuneTypeSet : public QWidget
{
    Q_OBJECT

public:
    explicit ImmuneTypeSet(QWidget *parent = 0);            //构造函数
    ~ImmuneTypeSet();                                       //析构函数
    void showDialog();                                      //显示窗口

private slots:
    void receiveData(QString typeName, int type);           //接收数据
    void on_pushButtonNew_clicked();                        //新建
    void on_pushButtonDelete_clicked();                     //删除
    void on_pushButtonUpdate_clicked();                     //更改
    void on_pushButtonExit_clicked();                       //退出
    void on_tableWidget_clicked(const QModelIndex &index);  //点击列表

private:
    Ui::immunetypeset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值

private:
    int nowRow;                   //当前选中行
    TypeSetDialog *typeSetDialog; //新建输入框
};

#endif // TYPESET_H
