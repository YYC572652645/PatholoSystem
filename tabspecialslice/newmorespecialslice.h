#ifndef NEWMORESPECIALSLICE_H
#define NEWMORESPECIALSLICE_H


/***************************************************************
   功能:批量切片

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QKeyEvent>
#include "specialslicedata.h"

namespace Ui {
class newmorespecialslice;
}

class NewMoreSpecialSlice : public QMainWindow
{
    Q_OBJECT

signals:
    void sendSelect();                                  //发送查询信号

public:
    explicit NewMoreSpecialSlice(QWidget *parent = 0);  //构造函数
    ~NewMoreSpecialSlice();                             //析构函数
    void showWidget();                                  //显示界面

private slots:
    void on_pushButtonOk_clicked();                     //确定按钮
    void on_pushButtonCancel_clicked();                 //取消按钮

private:
    Ui::newmorespecialslice *ui;
    void keyPressEvent(QKeyEvent * event);              //获取扫码枪数据
    QString subFinger(QString number);                  //去字母
    void setComboBoxInfo();                             //设置信息
};

#endif // NEWMORENORMALSLICE_H
