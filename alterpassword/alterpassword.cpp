#include "alterpassword.h"
#include "ui_alterpassword.h"
#include "config/qreadini.h"
#include "messagebox/messagedialog.h"
#include "globaldef.h"

AlterPassword::AlterPassword(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::alterpassword)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);

    this->setWindowTitle("修改密码");
}

AlterPassword::~AlterPassword()
{
    delete ui;
}

void AlterPassword::on_pushButtonOk_clicked()
{
    if(ui->lineEditPsdMore->text().isEmpty()) return;

    if(ui->lineEditPsdMore->text() == ui->lineEditNewPsd->text())
    {
        INICONFIG->readIni();
        bool success = loginData.selectData(INICONFIG->getLoginConfig().userName, ui->lineEditOldPsd->text());

        if(success)
        {
            loginData.updateData(INICONFIG->getLoginConfig().userName, ui->lineEditPsdMore->text());
            this->close();
        }
        else
        {
            MESSAGEBOX->setInfo(GLOBALDEF::SYSTEMINFO, "请检查密码是否正确是否正确 ", QPixmap(GLOBALDEF::FAILIMAGE), true, this);
        }
    }
    else
    {

        MESSAGEBOX->setInfo(GLOBALDEF::SYSTEMINFO, "请检查两次密码是否一致 ", QPixmap(GLOBALDEF::FAILIMAGE), true, this);
    }
}

void AlterPassword::on_pushButtonCancel_clicked()
{
    this->close();
}
