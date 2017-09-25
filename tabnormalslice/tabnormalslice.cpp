#include "tabnormalslice.h"
#include "ui_tabnormalslice.h"
#include "globaldef.h"
#include "messagebox/messagedialog.h"
#include <QFileDialog>
#include <QDateTime>

/*******************   构造函数    ***********************/
TabNormalSlice::TabNormalSlice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabnormalslice)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();
    this->dataSelect(ALLDATA);

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置最后一行为当前选中行
    ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
    ui->tableWidget->setFocus();

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));
}

/*******************   析构函数    ***********************/
TabNormalSlice::~TabNormalSlice()
{
    delete ui;

    SAFEDELETE(newNormalSlice);
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
void TabNormalSlice::initControl()
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
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setColumnWidth(6, 160);
    ui->tableWidget->setColumnWidth(8, 160);

    //创建菜单
    this->createActions();
}

/*******************   初始化数据    ***********************/
void TabNormalSlice::initData()
{
    newNormalSlice = new NewNormalSlice(this);               //新建
    newMoreSlice = new NewMoreNormalSlice(this);             //批量新建
    templateSetUp = new TemplateSetUp(THIRDWIDGET, this);    //打印模板

    connect(newNormalSlice, SIGNAL(sendSelect()), this, SLOT(receiveSelect()));
    connect(newMoreSlice, SIGNAL(sendSelect()), this, SLOT(receiveSelect()));
}

/*******************   新建切片    ***********************/
void TabNormalSlice::on_actionNewSlice_triggered()
{
    newNormalSlice->showWidget();
}

/*******************   接收查询信号    ***********************/
void TabNormalSlice::receiveSelect()
{
    dataSelect(ALLDATA);

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置最后一行为当前选中行
    ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
    ui->tableWidget->setFocus();
}

/*******************   创建菜单            ***********************/
void TabNormalSlice::createActions()
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
void TabNormalSlice::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(print);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}

/*******************   查询并显示数据            ***********************/
void TabNormalSlice::dataSelect(int type)
{
    int dataCount = 0;

    if(type == ALLDATA)
    {
        dataCount = NORMALSLICEDATA->selectData(type, NULL);
    }
    else
    {
        dataCount = NORMALSLICEDATA->selectData(type, ui->lineEditNumber->text());
    }

    if(dataCount == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(dataCount);           //设置表格行数

    QList<DataNormalSlice> dataList = NORMALSLICEDATA->getDataList();

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(dataList.at(i).sectionCode));
        ui->tableWidget->setItem(i, 1, DATA(dataList.at(i).other));

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
void TabNormalSlice::on_actionPrintLabel_triggered()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    DataNormalSlice data = NORMALSLICEDATA->getDataList().at(ui->tableWidget->currentRow());

    if(data.printed != "0")
    {
        int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("当前标签已经打印，您需要重打吗？"), GLOBALDEF::SUCCESSIMAGE, false, this);
        if(ok == QDialog::Accepted)
        {
            for(int j = 0; j < data.printNum.toInt(); j ++)
            {
                templateSetUp->setQrCodeNumber(data.sectionCode);
                templateSetUp->setDataNormalSlice(data);

                templateSetUp->printImage(data.sectionCode);
            }
        }
    }
    else
    {
        for(int j = 0; j < data.printNum.toInt(); j ++)
        {
            templateSetUp->setQrCodeNumber(data.sectionCode);
            templateSetUp->setDataNormalSlice(data);

            templateSetUp->printImage(data.sectionCode);
        }

        data.printed = "1";

        NORMALSLICEDATA->updateData(data);
    }

    dataSelect(ALLDATA);
}

/*******************   批量打印            ***********************/
void TabNormalSlice::on_actionPrintMoreLabel_triggered()
{
    int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("即将批量打印所有剩余的病理登记标签，您确认吗？"),GLOBALDEF::SUCCESSIMAGE, false, this);

    if(ok == QDialog::Accepted)
    {
        for(int i = 0; i < NORMALSLICEDATA->getDataList().size(); i ++)
        {
            DataNormalSlice data = NORMALSLICEDATA->getDataList().at(i);

            if(data.printed == "0")
            {
                for(int j = 0; j < data.printNum.toInt(); j ++)
                {
                    templateSetUp->setQrCodeNumber(data.sectionCode);
                    templateSetUp->setDataNormalSlice(data);

                    templateSetUp->printImage(data.sectionCode);
                }

                data.printed = "1";

                NORMALSLICEDATA->updateData(data);
            }
        }

        dataSelect(ALLDATA);
    }
}

/*******************   删除信息            ***********************/
void TabNormalSlice::on_actionDeleteInfo_triggered()
{
    NORMALSLICEDATA->deleteData(BLDATA, NORMALSLICEDATA->getDataList().at(ui->tableWidget->currentRow()).sectionId);

    dataSelect(ALLDATA);
}

/*******************   清空信息            ***********************/
void TabNormalSlice::on_actionClearInfo_triggered()
{
    NORMALSLICEDATA->deleteData(ALLDATA, NULL);
    dataSelect(ALLDATA);
}

/*******************   刷新数据            ***********************/
void TabNormalSlice::on_pushButtonRefresh_clicked()
{
    ui->labelMovie->setMovie(movie);
    movie->start();

    dataSelect(ALLDATA);

    timer->start(GLOBALDEF::REFRESHTIME);
}

/*******************   更新gif            ***********************/
void TabNormalSlice::updateMovie()
{
    movie->stop();
    timer->stop();
}

/*******************   双击列表            ***********************/
void TabNormalSlice::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    newNormalSlice->showWidget(NORMALSLICEDATA->getDataList().at(ui->tableWidget->currentRow()));
}

/*******************   查询数据            ***********************/
void TabNormalSlice::on_pushButtonFind_clicked()
{
    dataSelect(BLDATA);
}

/*******************   批量新增            ***********************/
void TabNormalSlice::on_actionNewMore_triggered()
{
    newMoreSlice->showWidget();
}

/*******************   打印模板            ***********************/
void TabNormalSlice::on_actionPrintTemplate_triggered()
{
    if(NULL != ui->tableWidget->currentItem())
    {
        templateSetUp->setQrCodeNumber(NORMALSLICEDATA->getDataList().at(ui->tableWidget->currentRow()).sectionCode);
        templateSetUp->setDataNormalSlice(NORMALSLICEDATA->getDataList().at(ui->tableWidget->currentRow()));
    }

    templateSetUp->showWidget();
}

/*******************   导入Txt            ***********************/
void TabNormalSlice::on_actionImportTxt_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(NULL, "打开文件对话框", ".", "txt(*.txt)");

    if(fileName.isEmpty()) return;

    QFile file(fileName);

    if(!file.open(QIODevice::Text | QIODevice::ReadOnly)) return;

    QTextStream textRead(&file);

    while(!textRead.atEnd())
    {
        DataNormalSlice data;

        QStringList stringList = textRead.readLine().split("$$");

        if(stringList.size() < 2) continue;

        data.embedCode     = stringList.first();
        data.sectionCode   = stringList.first();
        data.printNum      = "1";
        data.stainTypeName = "常规";
        data.staining      = stringList.at(1);
        data.sectionTime   = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        data.stainTime     = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        data.printed       = "0";

        NORMALSLICEDATA->insertData(data);
    }

    file.close();

    dataSelect(ALLDATA);

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置最后一行为当前选中行
    ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
    ui->tableWidget->setFocus();
}
