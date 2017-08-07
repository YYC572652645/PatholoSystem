#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("病理科专用打码软件 ");
    this->initControl();                         //初始化控件
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initControl()
{
    ui->tabWidgetTotal->addTab(&tabRegister,  "登记");
    ui->tabWidgetTotal->addTab(&tabMaterial,  "取材");
    ui->tabWidgetTotal->addTab(&tabNormalSlice,"常规切片");
    ui->tabWidgetTotal->addTab(&tabSystemSet, "系统设置");

}
