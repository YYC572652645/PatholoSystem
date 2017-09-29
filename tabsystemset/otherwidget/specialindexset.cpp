#include "specialindexset.h"
#include "ui_specialindexset.h"
#include "globaldef.h"


/****************     构造函数      **********************/
SpeciaIndexSet::SpeciaIndexSet(QWidget *parent) :
    QWidget(parent)
  ,ui(new Ui::specialindexset)
  ,nowRow(-1)
  ,typeSetDialog(NULL)
  ,templateSetUp(NULL)
{
    ui->setupUi(this);



    this->initControl();                      //初始化控件
    this->initValue();                        //初始化值
}

/****************     析构函数      **********************/
SpeciaIndexSet::~SpeciaIndexSet()
{
    delete ui;
}

/****************     显示对话框    **********************/
void SpeciaIndexSet::showDialog()
{
    this->initValue();

    nowRow = 0;

    if(SYSTEMDATA->getSpecialingName().size() != 0)
    {
        ui->tableWidget->selectRow(0);
        ui->tableWidget->setFocus();
    }

    SYSTEMDATA->selectStainingData(GLOBALDEF::SECONDTYPE);

    this->show();
}

/****************     初始化控件    **********************/
void SpeciaIndexSet::initControl()
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

    templateSetUp = new TemplateSetUp(SEVENTHWIDGET, this);
    typeSetDialog = new TypeSetDialog(this);
    typeSetDialog->setInfo();

    //连接信号和槽
    connect(typeSetDialog, SIGNAL(sendString(QString, int)), this,SLOT(receiveData(QString, int)));
}

/****************     初始化值      **********************/
void SpeciaIndexSet::initValue()
{
    int count = SYSTEMDATA->selectStainingData(GLOBALDEF::SECONDTYPE);  //查询标本类别信息

    if(count == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(count);

    QMap<QString , QString> mapData =  SYSTEMDATA->getSpecialingName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(mapData.value(mapData.keys().at(i))));          //名称
    }
}

/****************     接收数据      **********************/
void SpeciaIndexSet::receiveData(QString typeName, int type)
{
    if(type ==  GLOBALDEF::TYPEINSERT)
    {
        SYSTEMDATA->insertStainingData(typeName, GLOBALDEF::SECONDTYPE);
    }
    else if(type ==  GLOBALDEF::TYPEUPDATE)
    {
        if(nowRow >= SYSTEMDATA->getSpecialingName().size()) return;

        SYSTEMDATA->updateStainingData(typeName, SYSTEMDATA->getSpecialingName().keys().at(nowRow));
    }

    this->initValue();
}

/****************     新建         **********************/
void SpeciaIndexSet::on_pushButtonNew_clicked()
{
    typeSetDialog->showNewDialog();
}

/****************     删除         **********************/
void SpeciaIndexSet::on_pushButtonDelete_clicked()
{
    if(nowRow < 0) return;

    if(nowRow >= SYSTEMDATA->getSpecialingName().size()) return;

    bool success = SYSTEMDATA->deleteStainingData(SYSTEMDATA->getSpecialingName().keys().at(nowRow));

    if(!success) return;

    ui->tableWidget->removeRow(nowRow); //移除删除的一行

    SYSTEMDATA->selectStainingData(GLOBALDEF::SECONDTYPE);
}

/****************     更新         **********************/
void SpeciaIndexSet::on_pushButtonUpdate_clicked()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    QMap<QString , QString> mapData =  SYSTEMDATA->getSpecialingName();

    QString codeTypeName = mapData.value(mapData.keys().at(nowRow));

    typeSetDialog->showUpdateDialog(NULL, codeTypeName);
}

/****************     退出         **********************/
void SpeciaIndexSet::on_pushButtonExit_clicked()
{
    this->close();
}

/****************     点击列表控件  **********************/
void SpeciaIndexSet::on_tableWidget_clicked(const QModelIndex &index)
{
    nowRow = index.row();
}

/****************     打印标签     **********************/
void SpeciaIndexSet::on_pushButtonPrint_clicked()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    QMap<QString , QString> mapData =  SYSTEMDATA->getSpecialingName();

    templateSetUp->printImage(mapData.value(mapData.keys().at(nowRow)));
}

/****************     全部打印     **********************/
void SpeciaIndexSet::on_pushButtonPrintAll_clicked()
{
    QMap<QString , QString> mapData =  SYSTEMDATA->getSpecialingName();

    for(int i = 0; i < mapData.keys().size(); i ++)
    {
        templateSetUp->printImage(mapData.value(mapData.keys().at(i)));
    }
}

/****************     设置模板     **********************/
void SpeciaIndexSet::on_pushButtonTemplateSet_clicked()
{
    QMap<QString, QString> mapData =  SYSTEMDATA->getSpecialingName();

    if(NULL != ui->tableWidget->currentItem())
    {
        templateSetUp->setQrCodeNumber(mapData.value(mapData.keys().at(nowRow)));
    }

    templateSetUp->showWidget();
}
