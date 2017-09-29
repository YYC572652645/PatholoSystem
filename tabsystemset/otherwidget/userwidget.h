#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QMainWindow>
#include "../tabsystemdata.h"

namespace Ui {
class userwidget;
}

class UserWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = 0);
    ~UserWidget();

    void showWidget(UserData data);        //显示界面

signals:
    void sendData(UserData data);         //发送数据

private slots:
    void on_pushButtonOk_clicked();       //确定按钮
    void on_pushButtonCancel_clicked();   //取消按钮

private:
    Ui::userwidget *ui;
    void clearInfo();                     //清空信息
};

#endif // USERWIDGET_H
