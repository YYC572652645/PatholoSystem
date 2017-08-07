#include "typeset.h"
#include "ui_typeset.h"
#include "globaldef.h"

TypeSet::TypeSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::typeset)
{
    ui->setupUi(this);

    this->initControl();
}

TypeSet::~TypeSet()
{
    delete ui;
}

void TypeSet::initControl()
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

    ui->tableWidget->setRowCount(2);

    ui->tableWidget->setItem(0, 0, DATA("F"));
    ui->tableWidget->setItem(0, 1, DATA("冰冻"));
    ui->tableWidget->setItem(1, 0, DATA("A"));
    ui->tableWidget->setItem(1, 1, DATA("常规"));
}
