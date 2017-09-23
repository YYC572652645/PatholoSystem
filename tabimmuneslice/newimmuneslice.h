#ifndef NEWIMMUNESLICE_H
#define NEWIMMUNESLICE_H

#include <QMainWindow>
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
    void setComboBoxInfo();                 //设置信息
};

#endif // NEWNORMALSLICE_H
