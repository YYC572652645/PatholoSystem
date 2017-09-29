#ifndef PRINTSET_H
#define PRINTSET_H

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"
#include <QPrinterInfo>

namespace Ui {
class printset;
}

class PrintSet : public QWidget
{
    Q_OBJECT

public:
    explicit PrintSet(QWidget *parent = 0);                       //构造函数
    ~PrintSet();                                                  //析构函数
    void showDialog();                                            //显示界面

private slots:
    void on_pushButtonOk_clicked();                               //确定按钮
    void on_pushButtonCancel_clicked();                           //取消按钮
    void on_tableWidget_doubleClicked(const QModelIndex &index);  //双击列表
    void on_pushButtonDelete_clicked();                           //删除数据

private:
    Ui::printset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值
    void dataSelect();             //查询数据
    QPrinterInfo printer;          //打印对象
};

#endif // TYPESET_H
