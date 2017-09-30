#ifndef USERSET_H
#define USERSET_H

/***************************************************************
   功能:用户设置

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"
#include "userwidget.h"

namespace Ui {
class userset;
}

class UserSet : public QWidget
{
    Q_OBJECT

public:
    explicit UserSet(QWidget *parent = 0);
    ~UserSet();

    void showDialog();

private slots:
    void receiveData(UserData data);     //接收数据
    void on_pushButtonNew_clicked();     //新建
    void on_pushButtonDelete_clicked();  //删除
    void on_pushButtonUpdate_clicked();  //更新
    void on_pushButtonExit_clicked();    //退出

private:
    Ui::userset *ui;

    void initControl();                 //初始化控件
    void initValue();                   //初始化值
    void dataSelect();                  //数据查询

private:
    UserWidget *userWidget;
};

#endif // TYPESET_H
