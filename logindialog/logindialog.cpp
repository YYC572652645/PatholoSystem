#include "logindialog.h"
#include "ui_logindialog.h"
#include "logindata.h"
#include "messagebox/messagedialog.h"
#include "config/qreadini.h"
#include "globaldef.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    this->setWindowTitle("登录");

    ui->lineEditUserName->setText(INICONFIG->getLoginConfig().userName);
    ui->lineEditPassWord->setText(INICONFIG->getLoginConfig().passWord);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButtonOk_clicked()
{
    QString userName = ui->lineEditUserName->text();
    QString passWord = ui->lineEditPassWord->text();

    if(loginData.selectData(userName, passWord))
    {
        authority = loginData.getUserInfo().authority.toInt();
        adminster = loginData.getUserInfo().isAdministrator.toInt();

        accept();

        INICONFIG->writeIni(userName, passWord);
    }
    else
    {
        MESSAGEBOX->setInfo(GLOBALDEF::SYSTEMINFO, "请检查账号密码是否正确 ", QPixmap(GLOBALDEF::FAILIMAGE), true, this);
    }
}

void LoginDialog::on_pushButtonCancel_clicked()
{
    this->close();
}

int LoginDialog::getAdminster() const
{
    return adminster;
}

int LoginDialog::getAuthority() const
{
    return authority;
}
