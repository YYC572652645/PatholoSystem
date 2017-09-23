#include "tabimmuneslice.h"
#include "ui_tabimmuneslice.h"
#include "globaldef.h"
#include "messagebox/messagedialog.h"

/*******************   析构函数    ***********************/
TabImmuneSlice::TabImmuneSlice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabimmuneslice)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();

    //查询数据
    dataSelect(ALLDATA);

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置最后一行为当前选中行
    ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
    ui->tableWidget->setFocus();

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));
}

/*******************   构造函数    ***********************/
TabImmuneSlice::~TabImmuneSlice()
{
    delete ui;

    SAFEDELETE(newImmuneSlice);
    SAFEDELETE(newMoreSlice);
    SAFEDELETE(templateSetUp);
    SAFEDELETE(menu);
    SAFEDELETE(print);
    SAFEDELETE(del);
    SAFEDELETE(refresh);
    SAFEDELETE(movie);
    SAFEDELETE(timer);
}

/*******************   初始化控件    ***********************/
void TabImmuneSlice::initControl()
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

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //设置列宽
    ui->tableWidget->setColumnWidth(6, 160);
    ui->tableWidget->setColumnWidth(8, 160);

    this->createActions();
}

/*******************   初始化数据    ***********************/
void TabImmuneSlice::initData()
{
    newImmuneSlice = new NewImmuneSlice(this);               //新建切片
    newMoreSlice = new NewMoreImmuneSlice(this);             //批量新增
    templateSetUp = new TemplateSetUp(FOURTHWIDGET, this);   //打印模板

    connect(newImmuneSlice, SIGNAL(sendSelect()), this, SLOT(receiveSelect()));
    connect(newMoreSlice, SIGNAL(sendSelect()), this, SLOT(receiveSelect()));
}

/*******************   创建菜单            ***********************/
void TabImmuneSlice::createActions()
{
    menu    = new QMenu(this);
    print   = new QAction(QIcon(GLOBALDEF::PRINTICON),   "打印", this);
    refresh = new QAction(QIcon(GLOBALDEF::REFRESHICON), "刷新", this);
    del     = new QAction(QIcon(GLOBALDEF::DELETEICON),  "删除", this);

    connect(print,   SIGNAL(triggered(bool)), this,SLOT(on_actionPrintLabel_triggered()));
    connect(refresh, SIGNAL(triggered(bool)), this,SLOT(on_pushButtonRefresh_clicked()));
    connect(del,     SIGNAL(triggered(bool)), this,SLOT(on_actionDeleteInfo_triggered()));
}

/*******************   显示菜单            ***********************/
void TabImmuneSlice::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(print);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}

/*******************   更新gif            ***********************/
void TabImmuneSlice::updateMovie()
{
    movie->stop();
    timer->stop();
}


/*******************   接收查询    ***********************/
void TabImmuneSlice::receiveSelect()
{
    dataSelect(ALLDATA);

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置最后一行为当前选中行
    ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
    ui->tableWidget->setFocus();

}

/*******************   查询并显示数据            ***********************/
void TabImmuneSlice::dataSelect(int type)
{
    int dataCount = 0;

    if(type == ALLDATA)
    {
        dataCount = IMMUNESLICEDATA->selectData(type, NULL);
    }
    else
    {
        dataCount = IMMUNESLICEDATA->selectData(type, ui->lineEditNumber->text());
    }

    if(dataCount == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(dataCount);           //设置表格行数

    QList<DataImmuneSlice> dataList = IMMUNESLICEDATA->getDataList();

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(dataList.at(i).sectionCode));
        ui->tableWidget->setItem(i, 1, DATA(dataList.at(i).cloneNumber));

        {
            QWidget     *widget     = new QWidget(this);
            QCheckBox   *checkBox   = new QCheckBox(this);
            QHBoxLayout *hboxLayout = new QHBoxLayout(this);
            checkBox->setMinimumHeight(16);
            hboxLayout->addWidget(checkBox);
            hboxLayout->setAlignment(checkBox, Qt::AlignCenter);
            widget->setLayout(hboxLayout);
            ui->tableWidget->setCellWidget(i, 2, widget);

            if(dataList.at(i).printed == GLOBALDEF::PRINTFLAGE)
            {
                checkBox->setChecked(true);
            }
            checkBox->setEnabled(false);
        }

        ui->tableWidget->setItem(i, 3, DATA(dataList.at(i).printNum));
        ui->tableWidget->setItem(i, 4, DATA(dataList.at(i).stainTypeName));
        ui->tableWidget->setItem(i, 5, DATA(dataList.at(i).staining));
        ui->tableWidget->setItem(i, 6, DATA(dataList.at(i).sectionTime));
        ui->tableWidget->setItem(i, 7, DATA(dataList.at(i).sectioner));
        ui->tableWidget->setItem(i, 8, DATA(dataList.at(i).stainTime));
        ui->tableWidget->setItem(i, 9, DATA(dataList.at(i).stainer));
    }
}

/*******************   打印            ***********************/
void TabImmuneSlice::on_actionPrintLabel_triggered()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    DataImmuneSlice data = IMMUNESLICEDATA->getDataList().at(ui->tableWidget->currentRow());

    if(data.printed != "0")
    {
        int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("当前标签已经打印，您需要重打吗？"), GLOBALDEF::SUCCESSIMAGE, false, this);
        if(ok == QDialog::Accepted)
        {
            for(int j = 0; j < data.printNum.toInt(); j ++)
            {
                templateSetUp->setQrCodeNumber(data.sectionCode);
                templateSetUp->setDataImmuneSlice(data);

                templateSetUp->printImage(data.sectionCode);
            }
        }
    }
    else
    {
        for(int j = 0; j < data.printNum.toInt(); j ++)
        {
            templateSetUp->setQrCodeNumber(data.sectionCode);
            templateSetUp->setDataImmuneSlice(data);

            templateSetUp->printImage(data.sectionCode);
        }

        data.printed = "1";

        IMMUNESLICEDATA->updateData(data);
    }

    dataSelect(ALLDATA);
}

/*******************   删除信息            ***********************/
void TabImmuneSlice::on_actionDeleteInfo_triggered()
{
    IMMUNESLICEDATA->deleteData(BLDATA, IMMUNESLICEDATA->getDataList().at(ui->tableWidget->currentRow()).sectionId);

    dataSelect(ALLDATA);
}

/*******************   刷新数据            ***********************/
void TabImmuneSlice::on_pushButtonRefresh_clicked()
{
    ui->labelMovie->setMovie(movie);
    movie->start();

    dataSelect(ALLDATA);

    timer->start(GLOBALDEF::REFRESHTIME);
}

/*******************   双击列表            ***********************/
void TabImmuneSlice::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    newImmuneSlice->showWidget(IMMUNESLICEDATA->getDataList().at(ui->tableWidget->currentRow()));
}

/*******************   查询数据            ***********************/
void TabImmuneSlice::on_pushButtonFind_clicked()
{
    dataSelect(BLDATA);
}

/*******************   批量新增            ***********************/
void TabImmuneSlice::on_actionNewMore_triggered()
{
    newMoreSlice->showWidget();
}

/*******************   打印模板            ***********************/
void TabImmuneSlice::on_actionPrintTemplate_triggered()
{
    if(NULL != ui->tableWidget->currentItem())
    {
        templateSetUp->setQrCodeNumber(IMMUNESLICEDATA->getDataList().at(ui->tableWidget->currentRow()).sectionCode);
        templateSetUp->setDataImmuneSlice(IMMUNESLICEDATA->getDataList().at(ui->tableWidget->currentRow()));
    }

    templateSetUp->showWidget();
}

/*******************   新建切片            ***********************/
void TabImmuneSlice::on_actionNewSlice_triggered()
{
    newImmuneSlice->showWidget();
}
