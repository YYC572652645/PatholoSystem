#include "typesetdialog.h"
#include "ui_typesetdialog.h"
#include "messagebox/messagedialog.h"
#include "globaldef.h"
TypeSetDialog::TypeSetDialog(QWidget *parent) :
    QMainWindow(parent),dataType(0),
    ui(new Ui::typesetdialog)
{
    ui->setupUi(this);

    this->setWindowTitle("类别");

     this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
    //this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
}

TypeSetDialog::~TypeSetDialog()
{
    delete ui;
}

void TypeSetDialog::on_pushButtonOk_clicked()
{
    if(ui->lineEditTypeName->text().isEmpty())
    {
        MESSAGEBOX->setInfo(GLOBALDEF::SYSTEMINFO, "请输入类别名称！", QPixmap(GLOBALDEF::FAILIMAGE), false, this);
        return;
    }

    if(ui->label->isHidden())
    {
        emit sendString(ui->lineEditTypeName->text(), dataType);
    }
    else
    {
        emit sendString(ui->lineEditTypeAbbreviation->text(), ui->lineEditTypeName->text(), dataType);
    }


    this->close();
}

void TypeSetDialog::on_pushButtonCancel_clicked()
{
    this->close();
}

void TypeSetDialog::showUpdateDialog(QString typeAbbreviation, QString typeName)
{
    dataType = GLOBALDEF::TYPEUPDATE;
    ui->lineEditTypeAbbreviation->setText(typeAbbreviation);
    ui->lineEditTypeName->setText(typeName);

    this->show();
}

void TypeSetDialog::showNewDialog()
{
    dataType = GLOBALDEF::TYPEINSERT;

    ui->lineEditTypeAbbreviation->setText("");
    ui->lineEditTypeName->setText("");

    this->show();
}

void TypeSetDialog::setInfo()
{
    ui->label->hide();
    ui->lineEditTypeAbbreviation->hide();
    this->setWindowTitle("属性");
    this->setMinimumHeight(180);
    this->setMaximumHeight(180);
}
