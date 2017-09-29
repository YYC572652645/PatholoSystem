#ifndef NEWMOREIMMUNESLICE_H
#define NEWMOREIMMUNESLICE_H

/***************************************************************
   功能:批量新建

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QKeyEvent>
#include "immuneslicedata.h"

namespace Ui {
class newmoreimmuneslice;
}

class NewMoreImmuneSlice : public QMainWindow
{
    Q_OBJECT

signals:
    void sendSelect();                                 //发送查询信号

public:
    explicit NewMoreImmuneSlice(QWidget *parent = 0);  //构造函数
    ~NewMoreImmuneSlice();                             //析构函数
    void showWidget();                                 //显示窗口

private slots:
    void on_pushButtonOk_clicked();                    //确定按钮
    void on_pushButtonCancel_clicked();                //取消按钮

private:
    Ui::newmoreimmuneslice *ui;

    void keyPressEvent(QKeyEvent * event);             //获取扫码枪数据
    QString subFinger(QString number);                 //去字母
    void setComboBoxInfo();                            //设置信息
};

#endif // NEWMORENORMALSLICE_H
