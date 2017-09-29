#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "logindata.h"
#include "messagebox/messagedialog.h"

namespace Ui {
class logindialog;
}

/***************************************************************
   功能:登录对话框

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

    int getAuthority() const;           //获取权限信息
    int getAdminster() const;           //获取管理员信息

private slots:
    void on_pushButtonOk_clicked();     //确定按钮
    void on_pushButtonCancel_clicked(); //取消按钮

private:
    Ui::logindialog *ui;

    LoginData loginData;                //登录数据库对象
    MessageDialog messageDialog;        //提示框
    int authority;                      //权限
    int adminster;                      //管理员
};

#endif // LOGINDIALOG_H
