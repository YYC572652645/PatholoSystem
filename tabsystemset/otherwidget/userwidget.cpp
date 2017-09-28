#include "userwidget.h"
#include "ui_userwidget.h"

/****************     构造函数      **********************/
UserWidget::UserWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userwidget)
{
    ui->setupUi(this);

    this->setWindowTitle("用户");
    this->setWindowFlags(this->windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
}

/****************     析构函数      **********************/
UserWidget::~UserWidget()
{
    delete ui;
}

/****************     显示窗口      **********************/
void UserWidget::showWidget(UserData data)
{
    clearInfo();

    ui->lineEditUserName->setText(data.userName);

    if(data.isAdministrator.toInt())
    {
        ui->checkBoxAdminster->setChecked(true);
    }

    ui->lineEditRemark->setText(data.remark);

    int authority = data.authority.toInt();

    if(authority & 0X01) ui->checkBoxReg->setChecked(true);

    if(authority & 0X02) ui->checkBoxMateral->setChecked(true);

    if(authority & 0X04) ui->checkBoxNormal->setChecked(true);

    if(authority & 0X08) ui->checkBoxImmune->setChecked(true);

    if(authority & 0X10) ui->checkBoxSpecial->setChecked(true);

    if(authority & 0X20) ui->checkBoxSelect->setChecked(true);

    this->show();
}

/****************     确定按钮      **********************/
void UserWidget::on_pushButtonOk_clicked()
{
    UserData data;

    if(ui->lineEditUserName->text().isEmpty()) return;

    data.userName = ui->lineEditUserName->text();

    if(ui->lineEditPassWord->text() != ui->lineEditPassWordMore->text()) return;

    data.passWord = ui->lineEditPassWord->text();

    data.isAdministrator = QString::number(ui->checkBoxAdminster->isChecked());

    data.remark = ui->lineEditRemark->text();

    int authority = 0;

    if(ui->checkBoxReg->isChecked())
    {
        authority |= 0X01;
    }
    if(ui->checkBoxMateral->isChecked())
    {
        authority |= 0X02;
    }
    if(ui->checkBoxNormal->isChecked())
    {
        authority |= 0X04;
    }
    if(ui->checkBoxImmune->isChecked())
    {
        authority |= 0X08;
    }
    if(ui->checkBoxSpecial->isChecked())
    {
        authority |= 0X10;
    }
    if(ui->checkBoxSelect->isChecked())
    {
        authority |= 0X20;
    }

    data.authority = QString::number(authority);

    emit sendData(data);

    this->close();
}

/****************     取消按钮      **********************/
void UserWidget::on_pushButtonCancel_clicked()
{
    this->close();
}

/****************     清空信息      **********************/
void UserWidget::clearInfo()
{
   ui->checkBoxAdminster->setChecked(false);
   ui->checkBoxImmune->setChecked(false);
   ui->checkBoxReg->setChecked(false);
   ui->checkBoxMateral->setChecked(false);
   ui->checkBoxNormal->setChecked(false);
   ui->checkBoxSpecial->setChecked(false);
   ui->checkBoxSpecial->setChecked(false);

   ui->lineEditPassWord->clear();
   ui->lineEditPassWordMore->clear();
   ui->lineEditRemark->clear();
   ui->lineEditUserName->clear();
}
