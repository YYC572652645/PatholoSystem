#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->initControl();//初始化控件
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initControl()
{
    loginDialog.setParent(this);
    loginDialog.show();
}
