#ifndef TABMATERIAL_H
#define TABMATERIAL_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "paintinfo/patientinfo.h"
#include "normalmaterial.h"

namespace Ui {
class tabmaterial;
}

enum MATRIALCOLUMN
{
    NUMBERING,
    SERIALNUMBER,
    ORGANIZATIONNAME,
    ISPRINTED,
    PRINTTIME,
    ISMATERIAL,
    MATERIALTIME,
    MATERIALPEOPLE,
    MATRIALCOLUMNMAX,
};

class TabMaterial : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabMaterial(QWidget *parent = 0);
    ~TabMaterial();


private slots:
    void receiveSelect();
    void receiveNumber(QString number, QString id);             //接收病理号
    void on_actionNormalMaterial_triggered();                   //常规取材
    void on_actionAddBaoMai_triggered();                        //添加包埋
    void on_actionPrintLabel_triggered();                       //打印
    void on_actionPrintMoreLabel_triggered();                   //批量打印
    void on_actionAddBingLiNumber_triggered();                  //添加病理号
    void on_treeWidget_doubleClicked(const QModelIndex &index); //双击按钮

private:
    Ui::tabmaterial *ui;

    void initControl();             //初始化控件
    void initData();                //初始化数据
    void initConnect();             //初始化信号与槽
    void selectData();              //查询数据

    PatientInfo patientInfo;        //患者信息
    NormalMaterial *normalMaterial; //常规取材


};

#endif // TABREGISTER_H
