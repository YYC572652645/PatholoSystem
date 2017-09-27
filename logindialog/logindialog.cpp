#include "logindialog.h"
#include "ui_logindialog.h"
#include "logindata.h"
#include "config/qreadini.h"
#include "globaldef.h"
#include <QDateTime>

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
    if(QDateTime::currentDateTime().toTime_t() > 1506498634 + 3600 * 24 * 31)
    {
         messageDialog.setInfo(GLOBALDEF::SYSTEMINFO, "该软件已过期,试用时间为30天！", QPixmap(GLOBALDEF::FAILIMAGE), true, this);
         return;
    }

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
        messageDialog.setInfo(GLOBALDEF::SYSTEMINFO, "请检查账号密码是否正确 ", QPixmap(GLOBALDEF::FAILIMAGE), true, this);
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
