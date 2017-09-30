#include "tabstatistics.h"
#include "ui_tabstatistics.h"
#include "globaldef.h"
#include "databasedef.h"
#include "exceloperate/exceloperate.h"
#include "QFileDialog"

/*******************       构造函数             ***********************/
TabsSatistics::TabsSatistics(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::tabstatistics)
  ,menu (NULL)
  ,refresh(NULL)
  ,extend(NULL)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();
}

/*******************       析构函数             ***********************/
TabsSatistics::~TabsSatistics()
{
    delete ui;
}

/*******************       初始化控件            ***********************/
void TabsSatistics::initControl()
{
    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //纵向隐藏序号
    ui->tableWidget->verticalHeader()->setHidden(true);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->setColumnWidth(3, 200);
    ui->tableWidget->setColumnWidth(5, 200);

    //创建菜单
    this->createActions();
}

/*******************       初始化数据            ***********************/
void TabsSatistics::initData()
{
    ui->dateTimeEditBeginTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    unsigned int dateTime = QDateTime::currentDateTime().toTime_t() - 86400;
    ui->dateTimeEditBeginTime->setDateTime(QDateTime::fromTime_t(dateTime));

    ui->dateTimeEditEndTime->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEditEndTime->setDateTime(QDateTime::currentDateTime());
}

/*******************       创建菜单              ***********************/
void TabsSatistics::createActions()
{
    menu    = new QMenu(this);
    refresh = new QAction(QIcon(GLOBALDEF::REFRESHICON), "刷新", this);
    extend  = new QAction(QIcon(GLOBALDEF::EXCELICON),   "导出", this);

    connect(refresh, SIGNAL(triggered(bool)), this,SLOT(on_actionReferesh_triggered()));
    connect(extend,  SIGNAL(triggered(bool)), this,SLOT(on_actionExtend_triggered()));
}

/*******************       显示菜单              ***********************/
void TabsSatistics::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(refresh);
    menu->addAction(extend);

    menu->exec(QCursor::pos());

    event->accept();
}

/*******************       刷新数据              ***********************/
void TabsSatistics::on_actionReferesh_triggered()
{
    dataSelect(ALLDATA);
}

/*******************       导出Excel            ***********************/
void TabsSatistics::on_actionExtend_triggered()
{
    QList<QString>itemName;

    itemName.append(STATISTICSINFO::DATE);
    itemName.append(STATISTICSINFO::MATERIALTOTAL);
    itemName.append(STATISTICSINFO::EMBEDDINGTOTAL);
    itemName.append(STATISTICSINFO::NORMALMTLTOTAL);
    itemName.append(STATISTICSINFO::NORMALEDDTOTAL);
    itemName.append(STATISTICSINFO::FROZENMTLTOTAL);
    itemName.append(STATISTICSINFO::FROZENMEDDOTAL);

    QString fileName = QFileDialog::getSaveFileName(NULL, "保存文件",".","Excel(*.xlsx *.xls)");

    ExcelOperate * excelOperate = new ExcelOperate();

    excelOperate->setExtendType(GLOBALDEF::STATISTICSTYPE);
    excelOperate->setItemName(itemName);
    excelOperate->setStatisticsList(MATERIALDATA->getStatisticsList());
    excelOperate->setFileName(fileName);

    connect(excelOperate, SIGNAL(finished()), excelOperate, SLOT(terminate()));

    excelOperate->start();
}

/*******************       统计数据              ***********************/
void TabsSatistics::on_pushButtonSum_clicked()
{
    dataSelect(BLDATA);
}

/*******************       查询并显示数据         ***********************/
void TabsSatistics::dataSelect(int type)
{
    int dataCount = 0;

    if(type == ALLDATA)
    {
        dataCount = MATERIALDATA->selectStatistics();
    }
    else
    {
        dataCount = MATERIALDATA->selectStatistics(ui->dateTimeEditBeginTime->text(),ui->dateTimeEditEndTime->text());
    }

    if(dataCount == GLOBALDEF::DATAERROR) return;

    ui->tableWidget->setRowCount(dataCount);

    QList<DataStatistics> dataList = MATERIALDATA->getStatisticsList();

    if(dataCount != 0 && dataList.first().date.isEmpty()) return;

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, DATABASEDEF::DATE,           DATA(dataList.at(i).date));
        ui->tableWidget->setItem(i, DATABASEDEF::MATERIALTOTAL,  DATA(dataList.at(i).materialTotal));
        ui->tableWidget->setItem(i, DATABASEDEF::EMBEDDINGTOTAL, DATA(dataList.at(i).embeddingTotal));
        ui->tableWidget->setItem(i, DATABASEDEF::NORMALMTLTOTAL, DATA(dataList.at(i).normalMtlTotal));
        ui->tableWidget->setItem(i, DATABASEDEF::NORMALEDDTOTAL, DATA(dataList.at(i).normalEddTotal));
        ui->tableWidget->setItem(i, DATABASEDEF::FROZENMTLTOTAL, DATA(dataList.at(i).frozenMtlTotal));
        ui->tableWidget->setItem(i, DATABASEDEF::FROZENEDDTOTAL, DATA(dataList.at(i).frozenEddTotal));
    }
}
