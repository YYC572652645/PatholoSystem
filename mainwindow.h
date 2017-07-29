#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabregister/tabregister.h"

#pragma execution_character_set("utf-8")


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
    TabRegister tabRegister;
};

#endif // MAINWINDOW_H
