#include "printset.h"
#include "ui_printset.h"
#include "globaldef.h"
#include "databasedef.h"
#include <QHostInfo>

/****************     构造函数      **********************/
PrintSet::PrintSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::printset)
{
    ui->setupUi(this);

    this->initControl();  //初始化控件
    this->initValue();    //初始化值
}

/****************     析构函数      **********************/
PrintSet::~PrintSet()
{
    delete ui;
}

/****************     显示对话框    **********************/
void PrintSet::showDialog()
{
    initValue();

    this->show();
}

/****************     初始化控件    **********************/
void PrintSet::initControl()
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
}

/****************     初始化值      **********************/
void PrintSet::initValue()
{
    QStringList printList = QPrinterInfo::availablePrinterNames();

    for(int i = 0; i <printList.size(); i ++)
    {
        PrintData data;

        QHostInfo hostInfo = QHostInfo::fromName(QHostInfo::localHostName());;

        foreach(QHostAddress address,hostInfo.addresses())
        {
            if(address.protocol() == QAbstractSocket::IPv4Protocol)
            {
                data.computerID = address.toString();
            }
        }

        data.computerName = QHostInfo::localHostName();
        data.cinkModel    = "USB";
        data.printerPort  = "9100";
        data.printerModel = printList.at(i);

        SYSTEMDATA->printInsertData(data);
    }

    dataSelect();
}

/****************     查询数据  **********************/
void PrintSet::dataSelect()
{
    int dataCount = SYSTEMDATA->printSelectData();

    if(dataCount == GLOBALDEF::ERROR) return;

    QList<PrintData> dataList = SYSTEMDATA->getPrintList();

    ui->tableWidget->setRowCount(dataCount);     //设置表格行数

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, DAtABASEDEF::COMPUTERID,   DATA(dataList.at(i).computerID));
        ui->tableWidget->setItem(i, DAtABASEDEF::COMPUTERNAME, DATA(dataList.at(i).computerName));
        ui->tableWidget->setItem(i, DAtABASEDEF::PRINTERMODEL, DATA(dataList.at(i).printerModel));
        ui->tableWidget->setItem(i, DAtABASEDEF::CINKMODEl,    DATA(dataList.at(i).cinkModel));
        ui->tableWidget->setItem(i, DAtABASEDEF::PRINTERIP,    DATA(dataList.at(i).printerIP));
        ui->tableWidget->setItem(i, DAtABASEDEF::PRINTERPORT,  DATA(dataList.at(i).printerPort));
        ui->tableWidget->setItem(i, DAtABASEDEF::PRINTREMARK,  DATA(dataList.at(i).remark));
    }
}

/****************     确定  **********************/
void PrintSet::on_pushButtonOk_clicked()
{
    for(int row = 0; row < ui->tableWidget->rowCount(); row ++)
    {
        PrintData data;

        data.computerID   = ui->tableWidget->item(row, DAtABASEDEF::COMPUTERID)->text();
        data.computerName = ui->tableWidget->item(row, DAtABASEDEF::COMPUTERNAME)->text();
        data.cinkModel    = ui->tableWidget->item(row, DAtABASEDEF::PRINTERMODEL)->text();
        data.printerIP    = ui->tableWidget->item(row, DAtABASEDEF::CINKMODEl)->text();
        data.printerPort  = ui->tableWidget->item(row, DAtABASEDEF::PRINTERIP)->text();
        data.printerModel = ui->tableWidget->item(row, DAtABASEDEF::PRINTERPORT)->text();
        data.remark       = ui->tableWidget->item(row, DAtABASEDEF::PRINTREMARK)->text();

        SYSTEMDATA->printUpdateData(data);
    }

    this->close();
}

/****************     取消  **********************/
void PrintSet::on_pushButtonCancel_clicked()
{
    this->close();
}

/****************     双击列表  **********************/
void PrintSet::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if(index.column() == DAtABASEDEF::PRINTERIP || index.column() == DAtABASEDEF::PRINTERPORT || index.column() == DAtABASEDEF::PRINTREMARK)
    {
        ui->tableWidget->editItem(ui->tableWidget->currentItem());
    }
}

/****************     删除  **********************/
void PrintSet::on_pushButtonDelete_clicked()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    int row = ui->tableWidget->currentRow();

    QString computerId  = ui->tableWidget->item(row, DAtABASEDEF::COMPUTERID)->text();
    QString printerName = ui->tableWidget->item(row, DAtABASEDEF::PRINTERMODEL)->text();

    SYSTEMDATA->printDeleteData(computerId, printerName);

    dataSelect();
}
