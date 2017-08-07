#include "tabnormalslice.h"
#include "ui_tabnormalslice.h"

TabNormalSlice::TabNormalSlice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabnormalslice)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();
}

TabNormalSlice::~TabNormalSlice()
{
    delete ui;
}

/*******************   初始化控件    ***********************/
void TabNormalSlice::initControl()
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

}

/*******************   初始化数据    ***********************/
void TabNormalSlice::initData()
{

}




