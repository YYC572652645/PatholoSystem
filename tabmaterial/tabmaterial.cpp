#include "tabmaterial.h"
#include "ui_tabmaterial.h"

TabMaterial::TabMaterial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabmaterial)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();
}

TabMaterial::~TabMaterial()
{
    delete ui;
}

/*******************   初始化控件    ***********************/
void TabMaterial::initControl()
{
    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //等宽显示
    QHeaderView *headerView=ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //纵向隐藏序号
    headerView=ui->tableWidget->verticalHeader();
    headerView->setHidden(true);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setStyleSheet("QTableView QHeaderView::section {background-color:#EAE9EE}");

    //添加界面
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->addWidget(&patientInfo);
    ui->widgetInfo->setLayout(vBoxLayout);
}

/*******************   初始化数据    ***********************/
void TabMaterial::initData()
{

}




