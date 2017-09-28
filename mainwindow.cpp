#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

/*******************   构造函数    ***********************/
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

/*******************   析构函数    ***********************/
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

/*******************   初始化控件    ***********************/
void MainWindow::initControl()
{
    //如果是管理员则全部显示
    if(adminster) authority = 0XFF;

    if(authority & 0X01)
    {
        tabRegister     = new TabRegister(this);     //登记
        ui->tabWidgetTotal->addTab(tabRegister,    "登记");

        connect(tabRegister, SIGNAL(sendNumber(QString, QString)), this, SLOT(receiveNumber(QString, QString)));
    }

    if(authority & 0X02)
    {
        tabMaterial     = new TabMaterial(this);     //取材
        ui->tabWidgetTotal->addTab(tabMaterial,    "取材");

        connect(this, SIGNAL(sendNumber(QString, QString)), tabMaterial, SLOT(receiveNumber(QString, QString)));
    }

    if(authority & 0X04)
    {
        tabNormalSlice  = new TabNormalSlice(this);  //常规切片
        ui->tabWidgetTotal->addTab(tabNormalSlice, "常规切片");
    }

    if(authority & 0X08)
    {
        tabImmuneSlice  = new TabImmuneSlice(this);  //免疫组化切片
        ui->tabWidgetTotal->addTab(tabImmuneSlice, "免疫组化切片");
    }

    if(authority & 0X10)
    {
        tabSpecialSlice = new TabSpeciaSlice(this);  //特染切片
        ui->tabWidgetTotal->addTab(tabSpecialSlice,"特染切片");
    }

    if(authority & 0X20)
    {
        tabsSatistics   = new TabsSatistics(this);   //取材统计
        ui->tabWidgetTotal->addTab(tabsSatistics,  "取材统计");
    }

    if(authority & 0X40)
    {
        tabSystemSet    = new TabSystemSet(this);    //系统设置
        ui->tabWidgetTotal->addTab(tabSystemSet,   "系统设置");
    }
}

/*******************   显示信息    ***********************/
void MainWindow::showMainWindow()
{
    this->initControl();
    this->showMaximized();
}

void MainWindow::setAuthority(int value)
{
    authority = value;
}

void MainWindow::on_pushButton_clicked()
{
    alterPassword->show();
}

void MainWindow::setAdminster(int value)
{
    adminster = value;
}
