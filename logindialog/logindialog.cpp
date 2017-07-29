#include "logindialog.h"
#include "ui_logindialog.h"
#include "logindata.h"
#include "messagebox/messagedialog.h"
#include "globaldef.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButtonOk_clicked()
{
    QString userName = ui->lineEditUserName->text();
    QString passWord = ui->lineEditPassWord->text();

    if(loginData.selectData(userName,passWord))
    {
        accept();
    }
    else
    {
        MESSAGEBOX->setInfo(GLOBALDEF::SYSTEMINFO, "请检查账号密码是否正确 ", QPixmap(GLOBALDEF::FAILIMAGE), false, this);
    }
}

void LoginDialog::on_pushButtonCancel_clicked()
{
   this->close();
}
