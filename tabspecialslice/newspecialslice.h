#ifndef NEWSPECIALSLICE_H
#define NEWSPECIALSLICE_H

#include <QMainWindow>
#include "specialslicedata.h"

namespace Ui {
class newspecialslice;
}

class NewSpecialSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewSpecialSlice(QWidget *parent = 0);
    ~NewSpecialSlice();

    void showWidget();                       //显示窗口
    void showWidget(DataSpecialSlice data);   //显示窗口

signals:
    void sendSelect();                       //发送查询信号

private slots:
    void on_pushButtonOk_clicked();          //确定按钮
    void on_pushButtonCancel_clicked();      //取消按钮

private:
    Ui::newspecialslice *ui;
    void setComboBoxInfo();                 //设置信息
};

#endif // NEWNORMALSLICE_H
