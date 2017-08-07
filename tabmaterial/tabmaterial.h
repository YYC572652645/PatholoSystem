#ifndef TABMATERIAL_H
#define TABMATERIAL_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "tabregister/patientinfo.h"

namespace Ui {
class tabmaterial;
}


class TabMaterial : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabMaterial(QWidget *parent = 0);
    ~TabMaterial();


private:
    Ui::tabmaterial *ui;

    void initControl();  //初始化控件

    void initData();    //初始化数据

   PatientInfo patientInfo;


};

#endif // TABREGISTER_H
