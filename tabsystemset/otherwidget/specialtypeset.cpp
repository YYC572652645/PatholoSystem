#include "specialtypeset.h"
#include "ui_specialtypeset.h"
#include "globaldef.h"


/****************     构造函数      **********************/
SpeciaTypeSet::SpeciaTypeSet(QWidget *parent) :
    QWidget(parent)
  ,ui(new Ui::speciatypeset)
  ,nowRow(-1)
  ,typeSetDialog(NULL)
{
    ui->setupUi(this);



    this->initControl();  //初始化控件
    this->initValue();    //初始化值
}

/****************     析构函数      **********************/
SpeciaTypeSet::~SpeciaTypeSet()
{
    delete ui;
}

/****************     显示对话框    **********************/
void SpeciaTypeSet::showDialog()
{
    this->initValue();

    nowRow = 0;

    if(SYSTEMDATA->getSpecialTypeName().size() != 0)
    {
        ui->tableWidget->selectRow(0);
        ui->tableWidget->setFocus();
    }

    SYSTEMDATA->selectStainTypeData(GLOBALDEF::SECONDTYPE);

    this->show();
}

/****************     初始化控件    **********************/
void SpeciaTypeSet::initControl()
{
    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //等宽显示
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //纵向隐藏序号
    ui->tableWidget->verticalHeader()->setHidden(true);

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
void SpeciaTypeSet::initValue()
{
    int count = SYSTEMDATA->selectStainTypeData(GLOBALDEF::SECONDTYPE);  //查询标本类别信息

    if(count == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(count);

    QMap<QString , QString> mapData =  SYSTEMDATA->getSpecialTypeName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(mapData.value(mapData.keys().at(i))));          //名称
    }
}

/****************     接收数据      **********************/
void SpeciaTypeSet::receiveData(QString typeName, int type)
{
    if(type ==  GLOBALDEF::TYPEINSERT)
    {
        SYSTEMDATA->insertStainTypeData(typeName, GLOBALDEF::SECONDTYPE);
    }
    else if(type ==  GLOBALDEF::TYPEUPDATE)
    {
        if(nowRow >= SYSTEMDATA->getSpecialTypeName().size()) return;

        SYSTEMDATA->updateStainTypeData(typeName, SYSTEMDATA->getSpecialTypeName().keys().at(nowRow));
    }

    this->initValue();
}

/****************     新建         **********************/
void SpeciaTypeSet::on_pushButtonNew_clicked()
{
    typeSetDialog->showNewDialog();
}

/****************     删除         **********************/
void SpeciaTypeSet::on_pushButtonDelete_clicked()
{
    if(nowRow < 0) return;

    if(nowRow >= SYSTEMDATA->getSpecialTypeName().size()) return;

    bool success = SYSTEMDATA->deleteStainTypeData(SYSTEMDATA->getSpecialTypeName().keys().at(nowRow));

    if(!success) return;

    ui->tableWidget->removeRow(nowRow); //移除删除的一行
    SYSTEMDATA->selectStainTypeData(GLOBALDEF::SECONDTYPE);
}

/****************     更新         **********************/
void SpeciaTypeSet::on_pushButtonUpdate_clicked()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    QMap<QString , QString> mapData =  SYSTEMDATA->getSpecialTypeName();

    QString codeTypeName = mapData.value(mapData.keys().at(nowRow));

    typeSetDialog->showUpdateDialog(NULL, codeTypeName);
}

/****************     退出         **********************/
void SpeciaTypeSet::on_pushButtonExit_clicked()
{
    this->close();
}

/****************     点击列表控件  **********************/
void SpeciaTypeSet::on_tableWidget_clicked(const QModelIndex &index)
{
    nowRow = index.row();
}
