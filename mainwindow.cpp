#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "globaldef.h"

/*******************   构造函数       ***********************/
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent)
  ,ui(new Ui::MainWindow)
  ,tabRegister(NULL)
  ,tabSystemSet(NULL)
  ,tabMaterial(NULL)
  ,tabNormalSlice(NULL)
  ,tabImmuneSlice(NULL)
  ,tabSpecialSlice(NULL)
  ,tabsSatistics(NULL)
  ,alterPassword(NULL)
  ,authority(0)
  ,adminster(0)
{
    ui->setupUi(this);

    alterPassword = new AlterPassword(this);

    this->setWindowTitle("病理科专用打码软件 ");
}

/*******************   析构函数       ***********************/
MainWindow::~MainWindow()
{
    SAFEDELETE(tabRegister);
    SAFEDELETE(tabSystemSet);
    SAFEDELETE(tabMaterial);
    SAFEDELETE(tabNormalSlice);
    SAFEDELETE(tabImmuneSlice);
    SAFEDELETE(tabSpecialSlice);
    delete ui;
}

/*******************   接收双击消息    ***********************/
void MainWindow::receiveNumber(QString number, QString id)
{
    ui->tabWidgetTotal->setCurrentIndex(1);

    emit sendNumber(number, id);
}

/*******************   初始化控件      ***********************/
void MainWindow::initControl()
{        
    //如果是管理员则全部显示
    if(adminster) authority = GLOBALDEF::SHOWALL;

    if(authority & GLOBALDEF::SHOWREG)
    {
        tabRegister     = new TabRegister(this);
        ui->tabWidgetTotal->addTab(tabRegister,    "登记");

        connect(tabRegister, SIGNAL(sendNumber(QString, QString)), this, SLOT(receiveNumber(QString, QString)));
    }

    if(authority & GLOBALDEF::SHOWMATERIAL)
    {
        tabMaterial     = new TabMaterial(this);
        ui->tabWidgetTotal->addTab(tabMaterial,    "取材");

        connect(this, SIGNAL(sendNumber(QString, QString)), tabMaterial, SLOT(receiveNumber(QString, QString)));
    }

    if(authority & GLOBALDEF::SHOWNORMALSLICE)
    {
        tabNormalSlice  = new TabNormalSlice(this);
        ui->tabWidgetTotal->addTab(tabNormalSlice, "常规切片");
    }

    if(authority & GLOBALDEF::SHOWIMMUNESLICE)
    {
        tabImmuneSlice  = new TabImmuneSlice(this);
        ui->tabWidgetTotal->addTab(tabImmuneSlice, "免疫组化切片");
    }

    if(authority & GLOBALDEF::SHOWSPECIALSLICE)
    {
        tabSpecialSlice = new TabSpeciaSlice(this);  //特染切片
        ui->tabWidgetTotal->addTab(tabSpecialSlice,"特染切片");
    }

    if(authority & GLOBALDEF::SHOWSATISTICS)
    {
        tabsSatistics   = new TabsSatistics(this);
        ui->tabWidgetTotal->addTab(tabsSatistics,  "取材统计");
    }

    if(authority & GLOBALDEF::SHOWSYSTEMSET)
    {
        tabSystemSet    = new TabSystemSet(this);
        ui->tabWidgetTotal->addTab(tabSystemSet,   "系统设置");
    }
}

/*******************   显示信息        ***********************/
void MainWindow::showMainWindow()
{
    this->initControl();
    this->showMaximized();
}

/*******************   设置权限信息     ***********************/
void MainWindow::setAuthority(int value)
{
    authority = value;
}

/*******************   更改密码         ***********************/
void MainWindow::on_pushButton_clicked()
{
    alterPassword->show();
}

/*******************   设置管理员信息    ***********************/
void MainWindow::setAdminster(int value)
{
    adminster = value;
}
