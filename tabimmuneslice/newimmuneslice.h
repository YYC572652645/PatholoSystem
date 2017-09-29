#ifndef NEWIMMUNESLICE_H
#define NEWIMMUNESLICE_H

/***************************************************************
   功能:新建切片

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QKeyEvent>
#include "immuneslicedata.h"

namespace Ui {
class newimmuneslice;
}

class NewImmuneSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewImmuneSlice(QWidget *parent = 0);
    ~NewImmuneSlice();

    void showWidget();                       //显示窗口
    void showWidget(DataImmuneSlice data);   //显示窗口
signals:
    void sendSelect();                       //发送查询信号

private slots:
    void on_pushButtonOk_clicked();          //确定按钮
    void on_pushButtonCancel_clicked();      //取消按钮

private:
    Ui::newimmuneslice *ui;
    void setComboBoxInfo();                  //设置信息
    void keyPressEvent(QKeyEvent * event);   //确定点击
};

#endif // NEWNORMALSLICE_H
