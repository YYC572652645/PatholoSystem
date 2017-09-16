#include "typeset.h"
#include "ui_typeset.h"
#include "globaldef.h"


/****************     构造函数      **********************/
TypeSet::TypeSet(QWidget *parent) :
    QWidget(parent),nowRow(-1),
    ui(new Ui::typeset)
{
    ui->setupUi(this);

    this->initControl();  //初始化控件

    this->initValue();    //初始化值
}

/****************     析构函数      **********************/
TypeSet::~TypeSet()
{
    delete ui;
}

/****************     显示对话框    **********************/
void TypeSet::showDialog()
{
    this->initValue();

    nowRow = 0;

    if(SYSTEMDATA->getCodeTypeInfo().size() != 0)
    {
        ui->tableWidget->selectRow(0);
        ui->tableWidget->setFocus();
    }

    this->show();
}

/****************     初始化控件    **********************/
void TypeSet::initControl()
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

    //连接信号和槽
    connect(&typeSetDialog, SIGNAL(sendString(QString, QString, int)), this,SLOT(receiveData(QString, QString, int)));
}

/****************     初始化值      **********************/
void TypeSet::initValue()
{
    bool success = SYSTEMDATA->codeTypeSelectData();  //查询标本类别信息

    if(!success) return;

    ui->tableWidget->setRowCount(SYSTEMDATA->getCodeTypeInfo().size());

    for(int i = 0; i < SYSTEMDATA->getCodeTypeInfo().size(); i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(SYSTEMDATA->getCodeTypeInfo().at(i).codeTypeAbbr));          //前缀
        ui->tableWidget->setItem(i, 1, DATA(SYSTEMDATA->getCodeTypeInfo().at(i).codeTypeName));          //名称
    }
}

/****************     接收数据      **********************/
void TypeSet::receiveData(QString typeAbbreviation, QString typeName, int type)
{
    if(type ==  GLOBALDEF::TYPEINSERT)
    {
        SYSTEMDATA->codeTypeInsertData(typeAbbreviation, typeName);
    }
    else if(type ==  GLOBALDEF::TYPEUPDATE)
    {
        if(nowRow >= SYSTEMDATA->getCodeTypeInfo().size()) return;

        SYSTEMDATA->codeTypeUpdateData(typeAbbreviation, typeName, SYSTEMDATA->getCodeTypeInfo().at(nowRow).codeTypeID);
    }

    this->initValue();
}

/****************     新建         **********************/
void TypeSet::on_pushButtonNew_clicked()
{
    typeSetDialog.showNewDialog();
}

/****************     删除         **********************/
void TypeSet::on_pushButtonDelete_clicked()
{
    if(nowRow < 0) return;

    if(nowRow >= SYSTEMDATA->getCodeTypeInfo().size()) return;

    bool success = SYSTEMDATA->codeTypeDeleteData(SYSTEMDATA->getCodeTypeInfo().at(nowRow).codeTypeID);

    if(!success) return;

    ui->tableWidget->removeRow(nowRow); //移除删除的一行
}

/****************     更新         **********************/
void TypeSet::on_pushButtonUpdate_clicked()
{
    QString codeTypeAbbr = SYSTEMDATA->getCodeTypeInfo().at(nowRow).codeTypeAbbr;
    QString codeTypeName = SYSTEMDATA->getCodeTypeInfo().at(nowRow).codeTypeName;

    typeSetDialog.showUpdateDialog(codeTypeAbbr, codeTypeName);
}

/****************     退出         **********************/
void TypeSet::on_pushButtonExit_clicked()
{
    this->close();
}

/****************     点击列表控件  **********************/
void TypeSet::on_tableWidget_clicked(const QModelIndex &index)
{
    nowRow = index.row();
}
