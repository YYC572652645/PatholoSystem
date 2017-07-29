#include "tabregister.h"
#include "ui_tabregister.h"
#include "databasedef.h"
#include "globaldef.h"

TabRegister::TabRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabregister)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();
}

TabRegister::~TabRegister()
{
    delete ui;
}



/*******************   初始化控件    ***********************/
void TabRegister::initControl()
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

    ui->tableWidget->setStyleSheet("QTableView QHeaderView::section {background-color:#EAE9EE}");
}


/*******************   初始化数据    ***********************/
void TabRegister::initData()
{
    int dataCount = registerData.selectData();  //查询出的数据条数

    if(dataCount == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(dataCount);    //设置表格行数

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(registerData.registerInfo.at(i).pCode));          //序号
        ui->tableWidget->setItem(i, 1, DATA(registerData.registerInfo.at(i).sn));             //病理号
        ui->tableWidget->setItem(i, 2, DATA(registerData.registerInfo.at(i).printQuantity));  //打印数量
        ui->tableWidget->setItem(i, 3, DATA(registerData.registerInfo.at(i).printed));        //是否打印
        ui->tableWidget->setItem(i, 4, DATA(registerData.registerInfo.at(i).createTime));     //创建时间
    }
}
