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

    //纵向隐藏序号
    QHeaderView *headerView=ui->tableWidget->horizontalHeader();
    headerView=ui->tableWidget->verticalHeader();
    headerView->setHidden(true);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setStyleSheet("QTableView QHeaderView::section {background-color:#EAE9EE}");

    //添加界面
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->addWidget(&patientInfo);
    ui->widgetInfo->setLayout(vBoxLayout);


    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    //设置水平伸展策略
    ui->splitter->setStretchFactor(1, 0);
}

/*******************   初始化数据    ***********************/
void TabMaterial::initData()
{

}




