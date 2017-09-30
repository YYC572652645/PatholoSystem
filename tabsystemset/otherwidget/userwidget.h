#ifndef USERWIDGET_H
#define USERWIDGET_H


/***************************************************************
   功能:用户新建更改对话框

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#include <QMainWindow>
#include "../tabsystemdata.h"

namespace Ui {
class userwidget;
}

class UserWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = 0); //构造函数
    ~UserWidget();                            //析构函数

    void showWidget(UserData data);           //显示界面

signals:
    void sendData(UserData data);             //发送数据

private slots:
    void on_pushButtonOk_clicked();           //确定按钮
    void on_pushButtonCancel_clicked();       //取消按钮

private:
    Ui::userwidget *ui;
    void clearInfo();                         //清空信息
};

#endif // USERWIDGET_H
