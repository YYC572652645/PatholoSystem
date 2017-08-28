#ifndef TABREGISTER_H
#define TABREGISTER_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "registerdata.h"
#include "newslices.h"
#include "patientinfo.h"
#include "newmoreslices.h"
#include "printtemplate/templatesetup.h"
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

    void on_actionNewMoreNumber_triggered();

    void on_actionPrintTemplate_triggered();

private:
    Ui::tabregister *ui;

    void initControl();  //初始化控件

    void initData();    //初始化数据

private:
    RegisterData registerData;   //登记数据库
    PatientInfo patientInfo;     //患者信息

    NewSlices *newSlices;         //新编号
    NewMoreSlices *newMoreSlices; //批量编号
    TemplateSetUp *templateSetUp; //打印模板

};

#endif // TABREGISTER_H
