#ifndef ALTERPASSWORD_H
#define ALTERPASSWORD_H

/***************************************************************
   功能:修改密码

   创建人:殷宇辰

   创建时间:2017-9-25
**************************************************************/

#include <QMainWindow>
#include "logindialog/logindata.h"

namespace Ui {
class alterpassword;
}

class AlterPassword : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlterPassword(QWidget *parent = 0);
    ~AlterPassword();

private slots:
    void on_pushButtonOk_clicked();       //确定按钮
    void on_pushButtonCancel_clicked();   //取消按钮

private:
    Ui::alterpassword *ui;
    LoginData loginData;                  //数据库对象
};

#endif // ALTERPASSWORD_H
