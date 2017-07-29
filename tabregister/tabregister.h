#ifndef TABREGISTER_H
#define TABREGISTER_H

#include <QMainWindow>
#include "registerdata.h"
namespace Ui {
class tabregister;
}


class TabRegister : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabRegister(QWidget *parent = 0);
    ~TabRegister();

private:
    Ui::tabregister *ui;


    void initControl();  //初始化控件

    void initData();     //初始化数据

private:
    RegisterData registerData;
};

#endif // TABREGISTER_H
