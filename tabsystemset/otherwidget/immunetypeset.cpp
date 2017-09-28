#include "immunetypeset.h"
#include "ui_immunetypeset.h"
#include "globaldef.h"


/****************     构造函数      **********************/
ImmuneTypeSet::ImmuneTypeSet(QWidget *parent) :
    QWidget(parent),nowRow(-1),
    ui(new Ui::immunetypeset)
{
    ui->setupUi(this);

    typeSetDialog = NULL;

    this->initControl();  //初始化控件
    this->initValue();    //初始化值
}

/****************     析构函数      **********************/
ImmuneTypeSet::~ImmuneTypeSet()
{
    delete ui;
}

/****************     显示对话框    **********************/
void ImmuneTypeSet::showDialog()
{
    this->initValue();

    nowRow = 0;

    if(SYSTEMDATA->getStainTypeName().size() != 0)
    {
        ui->tableWidget->selectRow(0);
        ui->tableWidget->setFocus();
    }

    SYSTEMDATA->selectStainTypeData(GLOBALDEF::FIRSTTYPE);

    this->show();
}

/****************     初始化控件    **********************/
void ImmuneTypeSet::initControl()
{
    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //等宽显示
    QHeaderView *headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //纵向隐藏序号
    headerView=ui->tableWidget->verticalHeader();
    headerView->setHidden(true);

    //去除点击的虚线
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    typeSetDialog = new TypeSetDialog(this);

    typeSetDialog->setInfo();

    //连接信号和槽
    connect(typeSetDialog, SIGNAL(sendString(QString, int)), this,SLOT(receiveData(QString, int)));
}

/****************     初始化值      **********************/
void ImmuneTypeSet::initValue()
{
    int count = SYSTEMDATA->selectStainTypeData(GLOBALDEF::FIRSTTYPE);  //查询标本类别信息

    if(count == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(count);

    QMap<QString , QString> mapData =  SYSTEMDATA->getStainTypeName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(mapData.value(mapData.keys().at(i))));          //名称
    }
}

/****************     接收数据      **********************/
void ImmuneTypeSet::receiveData(QString typeName, int type)
{
    if(type ==  GLOBALDEF::TYPEINSERT)
    {
        SYSTEMDATA->insertStainTypeData(typeName, GLOBALDEF::FIRSTTYPE);
    }
    else if(type ==  GLOBALDEF::TYPEUPDATE)
    {
        if(nowRow >= SYSTEMDATA->getStainTypeName().size()) return;

        SYSTEMDATA->updateStainTypeData(typeName, SYSTEMDATA->getStainTypeName().keys().at(nowRow));
    }

    this->initValue();
}

/****************     新建         **********************/
void ImmuneTypeSet::on_pushButtonNew_clicked()
{
    typeSetDialog->showNewDialog();
}

/****************     删除         **********************/
void ImmuneTypeSet::on_pushButtonDelete_clicked()
{
    if(nowRow < 0) return;

    if(nowRow >= SYSTEMDATA->getStainTypeName().size()) return;

    bool success = SYSTEMDATA->deleteStainTypeData(SYSTEMDATA->getStainTypeName().keys().at(nowRow));

    if(!success) return;

    ui->tableWidget->removeRow(nowRow); //移除删除的一行

    SYSTEMDATA->selectStainTypeData(GLOBALDEF::FIRSTTYPE);
}

/****************     更新         **********************/
void ImmuneTypeSet::on_pushButtonUpdate_clicked()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    QMap<QString , QString> mapData =  SYSTEMDATA->getStainTypeName();

    QString codeTypeName = mapData.value(mapData.keys().at(nowRow));

    typeSetDialog->showUpdateDialog(NULL, codeTypeName);
}

/****************     退出         **********************/
void ImmuneTypeSet::on_pushButtonExit_clicked()
{
    this->close();
}

/****************     点击列表控件  **********************/
void ImmuneTypeSet::on_tableWidget_clicked(const QModelIndex &index)
{
    nowRow = index.row();
}
