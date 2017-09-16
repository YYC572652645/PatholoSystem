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

    //纵向隐藏序号
    QHeaderView *headerView=ui->tableWidget->horizontalHeader();
    headerView=ui->tableWidget->verticalHeader();
    headerView->setHidden(true);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
}

/*******************   初始化数据    ***********************/
void TabNormalSlice::initData()
{

}




