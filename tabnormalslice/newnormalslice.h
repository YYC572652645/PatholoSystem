#ifndef NEWNORMALSLICE_H
#define NEWNORMALSLICE_H

/***************************************************************
   功能:新建切片

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QKeyEvent>
#include "normalslicedata.h"

namespace Ui {
class newnormalslice;
}

class NewNormalSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewNormalSlice(QWidget *parent = 0); //构造函数
    ~NewNormalSlice();                            //析构函数

    void showWidget();                            //显示界面
    void showWidget(DataNormalSlice data);        //显示界面

signals:
    void sendSelect();

private slots:
    void on_pushButtonOk_clicked();               //确定按钮
    void on_pushButtonCancel_clicked();           //取消按钮

private:
    Ui::newnormalslice *ui;
    void keyPressEvent(QKeyEvent * event);        //获取扫码器信息
};

#endif // NEWNORMALSLICE_H
