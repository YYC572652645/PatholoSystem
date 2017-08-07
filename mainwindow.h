#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabregister/tabregister.h"
#include "tabsystemset/tabsystemset.h"
#include "tabmaterial/tabmaterial.h"
#include "tabnormalslice/tabnormalslice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void initControl(); //初始化控件


private:
    TabRegister tabRegister;        //登记
    TabSystemSet tabSystemSet;      //系统设置
    TabMaterial tabMaterial;        //取材
    TabNormalSlice tabNormalSlice;  //常规切片
};

#endif // MAINWINDOW_H
