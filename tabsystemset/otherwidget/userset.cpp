#include "userset.h"
#include "ui_userset.h"
#include "globaldef.h"
#include <QCheckBox>


/****************     构造函数      **********************/
UserSet::UserSet(QWidget *parent) :
    QWidget(parent)
  ,ui(new Ui::userset)
  ,userWidget(NULL)
  ,nowRow(-1)
{
    ui->setupUi(this);

    this->initControl();  //初始化控件
    this->initValue();    //初始化值

    userWidget = new UserWidget(this);
    connect(userWidget, SIGNAL(sendData(UserData)), this, SLOT(receiveData(UserData)));
}

/****************     析构函数      **********************/
UserSet::~UserSet()
{
    delete ui;
}

/****************     显示对话框    **********************/
void UserSet::showDialog()
{
    this->show();
}

/****************     接收信息    **********************/
void UserSet::receiveData(UserData data)
{
    if(!SYSTEMDATA->userInsertData(data))
    {
        SYSTEMDATA->userUpdateData(data);
    }

    dataSelect();
}

/****************     初始化控件    **********************/
void UserSet::initControl()
{
    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //纵向隐藏序号
    ui->tableWidget->verticalHeader()->setHidden(true);

    //去除点击的虚线
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnWidth(0, 60);
    ui->tableWidget->setColumnWidth(1, 60);
    ui->tableWidget->setColumnWidth(2, 60);
    ui->tableWidget->setColumnWidth(3, 60);
    ui->tableWidget->setColumnWidth(4, 100);
    ui->tableWidget->setColumnWidth(5, 100);
    ui->tableWidget->setColumnWidth(6, 100);
    ui->tableWidget->setColumnWidth(7, 60);
}

/****************     初始化值      **********************/
void UserSet::initValue()
{
    dataSelect();
}

/****************     新建         **********************/
void UserSet::on_pushButtonNew_clicked()
{
    userWidget->showWidget();
}

/****************     删除         **********************/
void UserSet::on_pushButtonDelete_clicked()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    if(ui->tableWidget->currentRow() >= SYSTEMDATA->getUserList().size()) return;

    if(SYSTEMDATA->getUserList().at(ui->tableWidget->currentRow()).isAdministrator.toInt()) return;

    bool success = SYSTEMDATA->userDeleteData(SYSTEMDATA->getUserList().at(ui->tableWidget->currentRow()).userName);

    if(!success) return;

    ui->tableWidget->removeRow(ui->tableWidget->currentRow());

    dataSelect();
}

/****************     更新         **********************/
void UserSet::on_pushButtonUpdate_clicked()
{
    if(nowRow < 0) return;

    if(nowRow >= SYSTEMDATA->getUserList().size()) return;

    userWidget->showUpdateWidget(SYSTEMDATA->getUserList().at(ui->tableWidget->currentRow()));
}

/****************     退出         **********************/
void UserSet::on_pushButtonExit_clicked()
{
    this->close();
}

/****************     查询数据  **********************/
void UserSet::dataSelect()
{
    int dataCount = SYSTEMDATA->userSelectData();

    if(dataCount == GLOBALDEF::DATAERROR) return;

    QList<UserData> dataList = SYSTEMDATA->getUserList();

    ui->tableWidget->setRowCount(dataCount);     //设置表格行数

    for(int i = 0; i < dataCount; i ++)
    {
        int authority = dataList.at(i).authority.toInt();

        ui->tableWidget->setItem(i, 0,   DATA(dataList.at(i).userName));

        int commond = dataList.at(i).isAdministrator.toInt();

        ui->tableWidget->setCellWidget(i, 1, setWidget(commond,   commond));
        ui->tableWidget->setCellWidget(i, 2, setWidget(authority, GLOBALDEF::SHOWREG));
        ui->tableWidget->setCellWidget(i, 3, setWidget(authority, GLOBALDEF::SHOWMATERIAL));
        ui->tableWidget->setCellWidget(i, 4, setWidget(authority, GLOBALDEF::SHOWNORMALSLICE));
        ui->tableWidget->setCellWidget(i, 5, setWidget(authority, GLOBALDEF::SHOWIMMUNESLICE));
        ui->tableWidget->setCellWidget(i, 6, setWidget(authority, GLOBALDEF::SHOWSPECIALSLICE));
        ui->tableWidget->setCellWidget(i, 7, setWidget(authority, GLOBALDEF::SHOWSATISTICS));
        ui->tableWidget->setItem(i, 8,   DATA(dataList.at(i).remark));
    }
}

/****************     设置Check  **********************/
QWidget *UserSet::setWidget(int authority, int type)
{
    QWidget     *widget     = new QWidget(this);
    QCheckBox   *checkBox   = new QCheckBox(this);
    QHBoxLayout *hboxLayout = new QHBoxLayout(this);
    checkBox->setMinimumHeight(16);
    hboxLayout->addWidget(checkBox);
    hboxLayout->setAlignment(checkBox, Qt::AlignCenter);
    widget->setLayout(hboxLayout);

    if(authority & type)
    {
        checkBox->setChecked(true);
    }
    checkBox->setEnabled(false);

    return widget;
}

/****************     点击列表  **********************/
void UserSet::on_tableWidget_clicked(const QModelIndex &index)
{
    nowRow = index.row();
}
