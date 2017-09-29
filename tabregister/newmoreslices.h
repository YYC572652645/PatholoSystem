#ifndef NEWMORESLICES_H
#define NEWMORESLICES_H

/***************************************************************
   功能:批量切片

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include "registerdata.h"

namespace Ui {
class newmoreslices;
}

class CodeTypeInfo;

class NewMoreSlices : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewMoreSlices(QWidget *parent = 0); //构造函数
    ~NewMoreSlices();                            //析构函数
    void showDialog();                           //显示界面

signals:
    void signalSelect(int, int);                 //查询信号

private slots:
    void on_pushButtonOk_clicked();              //确定按钮
    void on_pushButtonCancel_clicked();          //取消按钮

private:
    Ui::newmoreslices *ui;
    RegisterData registerData;                   //登记数据库对象
    QList<CodeTypeInfo> dataInfo;                //数据信息
};

#endif // NEWMORESLICES_H
