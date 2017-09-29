#ifndef NEWSLICES_H
#define NEWSLICES_H

/***************************************************************
   功能:新建切片

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include "registerdata.h"
#include "tabsystemset/tabsystemdata.h"
namespace Ui {
class newslices;
}

class NewSlices : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewSlices(QWidget *parent = 0); //构造函数
    ~NewSlices();                            //析构函数
    void showDialog();                       //显示对话框

signals:
    void signalSelect(int, int);             //查询信号
    void printBLNumber(int, QString);        //打印信号

private slots:
    void on_pushButtonOk_clicked();          //确定按钮
    void on_pushButtonCancel_clicked();      //取消按钮

private:
    Ui::newslices *ui;
    RegisterData registerData;               //登记数据库对象
    QList<CodeTypeInfo> dataInfo;            //数据信息
};

#endif // NEWSLICES_H
