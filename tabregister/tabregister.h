#ifndef TABREGISTER_H
#define TABREGISTER_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "registerdata.h"
#include "newslices.h"
#include "patientinfo.h"
namespace Ui {
class tabregister;
}


class TabRegister : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabRegister(QWidget *parent = 0);
    ~TabRegister();

private slots:
    void on_actionNewNumber_triggered();

private:
    Ui::tabregister *ui;

    void initControl();  //初始化控件

    void initData();    //初始化数据

private:
    RegisterData registerData;  //登记数据库
    NewSlices newSlices;        //新编号
    PatientInfo patientInfo;    //患者信息

};

#endif // TABREGISTER_H
