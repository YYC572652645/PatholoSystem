#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("病理科专用打码软件 ");
    this->initControl();
    this->initConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
    SAFEDELETE(tabRegister);
    SAFEDELETE(tabSystemSet);
    SAFEDELETE(tabMaterial);
    SAFEDELETE(tabNormalSlice);
    SAFEDELETE(tabImmuneSlice);
    SAFEDELETE(tabSpecialSlice);
}

void MainWindow::receiveNumber(QString number, QString id)
{
    ui->tabWidgetTotal->setCurrentIndex(1);

    emit sendNumber(number, id);
}

/*******************   初始化控件    ***********************/
void MainWindow::initControl()
{
    tabRegister = new TabRegister(this);        //登记
    tabSystemSet = new TabSystemSet(this);      //系统设置
    tabMaterial = new TabMaterial(this);        //取材
    tabNormalSlice = new TabNormalSlice(this);  //常规切片
    tabImmuneSlice = new TabImmuneSlice(this);  //免疫组化切片
    tabSpecialSlice = new TabSpeciaSlice(this); //特染切片

    ui->tabWidgetTotal->addTab(tabRegister,    "登记");
    ui->tabWidgetTotal->addTab(tabMaterial,    "取材");
    ui->tabWidgetTotal->addTab(tabNormalSlice, "常规切片");
    ui->tabWidgetTotal->addTab(tabImmuneSlice, "免疫组化切片");
    ui->tabWidgetTotal->addTab(tabSpecialSlice,"特染切片");
    ui->tabWidgetTotal->addTab(tabSystemSet,   "系统设置");
}

/*******************   初始化信号与槽    ***********************/
void MainWindow::initConnect()
{
    connect(tabRegister, SIGNAL(sendNumber(QString, QString)), this, SLOT(receiveNumber(QString, QString)));
    connect(this, SIGNAL(sendNumber(QString, QString)), tabMaterial, SLOT(receiveNumber(QString, QString)));
}
