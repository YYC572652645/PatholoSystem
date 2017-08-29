#include "tabregister.h"
#include "ui_tabregister.h"
#include "databasedef.h"
#include "globaldef.h"
#include "exceloperate/exceloperate.h"
#include <QMovie>
#include <QMessageBox>
#include <QModelIndex>
#include <QAbstractItemModel>

/*******************   构造函数    ***********************/
TabRegister::TabRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabregister)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();

    newSlices = new NewSlices();         //新编号
    newMoreSlices = new NewMoreSlices(); //批量编号
    templateSetUp = new TemplateSetUp(); //打印模板

    //初始化信号和槽
    connect(newSlices, SIGNAL(signalSelect(int)), this, SLOT(selectData(int)));
    connect(newMoreSlices, SIGNAL(signalSelect(int)), this, SLOT(selectData(int)));

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));
}

/*******************   析构函数    ***********************/
TabRegister::~TabRegister()
{
    SAFEDELETE(newSlices);
    SAFEDELETE(newMoreSlices);
    SAFEDELETE(templateSetUp);
    SAFEDELETE(movie);
    SAFEDELETE(timer);
    delete ui;
}

/*******************   更新gif    ***********************/
void TabRegister::updateMovie()
{
    movie->stop();
    timer->stop();
}

/*******************   查询数据    ***********************/
void TabRegister::selectData(int type)
{
    int dataCount = 0;
    if(type == ALLDATA)
    {
        dataCount = registerData.selectData();  //查询出的数据条数
    }
    else
    {
        dataCount = registerData.selectBLData(ui->lineEdit->text());
    }

    if(dataCount == GLOBALDEF::ERROR) return;

    ui->tableWidget->setRowCount(dataCount);    //设置表格行数

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(registerData.registerInfo.at(i).pCode));          //序号
        ui->tableWidget->setItem(i, 1, DATA(registerData.registerInfo.at(i).sn));             //病理号
        ui->tableWidget->setItem(i, 2, DATA(registerData.registerInfo.at(i).printQuantity));  //打印数量

        {
            QWidget *widget = new QWidget(this);
            QCheckBox *checkBox = new QCheckBox(this);
            QHBoxLayout *hboxLayout = new QHBoxLayout(this);
            checkBox->setMinimumHeight(16);
            hboxLayout->addWidget(checkBox);
            hboxLayout->setAlignment(checkBox, Qt::AlignCenter);
            widget->setLayout(hboxLayout);
            ui->tableWidget->setCellWidget(i, 3, widget);

            if(registerData.registerInfo.at(i).printed == GLOBALDEF::PRINTFLAGE)
            {
                checkBox->setChecked(true);
            }
            checkBox->setEnabled(false);
        }

        ui->tableWidget->setItem(i, 4, DATA(registerData.registerInfo.at(i).createTime));     //创建时间
    }

    //滑动至最后一行
    ui->tableWidget->scrollToBottom();

    //设置第一行为当前选中行
    if(dataCount != 0)
    {
        ui->tableWidget->selectRow(dataCount - 1);
        ui->tableWidget->setFocus();
    }
}

/*******************   初始化控件    ***********************/
void TabRegister::initControl()
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

    ui->tableWidget->setStyleSheet("QTableView QHeaderView::section {background-color:#EAE9EE}");

    //添加界面
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->addWidget(&patientInfo);
    ui->widgetInfo->setLayout(vBoxLayout);

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    //设置水平伸展策略
    ui->splitter->setStretchFactor(1, 0);

    //创建菜单
    this->createActions();
}


/*******************   创建菜单    ***********************/
void TabRegister::createActions()
{
    menu    = new QMenu(this);
    print   = new QAction(QIcon(GLOBALDEF::PRINTICON),   "打印", this);
    refresh = new QAction(QIcon(GLOBALDEF::REFRESHICON), "刷新", this);
    del     = new QAction(QIcon(GLOBALDEF::DELETEICON),  "删除", this);

    connect(print,   SIGNAL(triggered(bool)), this,SLOT(on_actionPrintLabel_triggered()));
    connect(refresh, SIGNAL(triggered(bool)), this,SLOT(on_pushButtonRefresh_clicked()));
    connect(del,     SIGNAL(triggered(bool)), this,SLOT(on_actionDeleteInfo_triggered()));
}

/**************************显示菜单***************************/
void TabRegister::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(print);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}

/*******************   初始化数据    ***********************/
void TabRegister::initData()
{
    selectData(ALLDATA);
}

/*******************   新建编号    ***********************/
void TabRegister::on_actionNewNumber_triggered()
{
    newSlices->showDialog();
}

/*******************   批量编号    ***********************/
void TabRegister::on_actionNewMoreNumber_triggered()
{
    newMoreSlices->showDialog();
}

/*******************   打印模板    ***********************/
void TabRegister::on_actionPrintTemplate_triggered()
{
    templateSetUp->show();
}

/*******************   删除数据    ***********************/
void TabRegister::on_actionDeleteInfo_triggered()
{
    int ok = QMessageBox::question(this,tr("系统提示"),tr("确定删除该数据吗？此操作不可逆！"),QMessageBox::Yes|QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
        registerData.deleteRowData(registerData.registerInfo.at(ui->tableWidget->currentRow()).id);
        this->selectData(ALLDATA);
    }
}

/*******************   清空数据    ***********************/
void TabRegister::on_actionClearInfo_triggered()
{
    int ok = QMessageBox::question(this,tr("系统提示"),tr("确定清空数据吗？此操作不可逆！"),QMessageBox::Yes|QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
        registerData.deleteAllData();
        this->selectData(ALLDATA);
    }
}

/*******************   导出Excel    ***********************/
void TabRegister::on_actionExtendExcel_triggered()
{
    QList<QString>itemName;

    itemName.append(PCODE);
    itemName.append(SN);
    itemName.append(PRINTQUANTITY);
    itemName.append(PRINTED);
    itemName.append(CREATETIME);

    EXCEL->extendExcel(itemName, registerData.registerInfo);
}

/*******************   刷新数据       ***********************/
void TabRegister::on_pushButtonRefresh_clicked()
{
    //播放gif

    ui->labelMovie->setMovie(movie);
    movie->start();

    selectData(ALLDATA);

    timer->start(GLOBALDEF::REFRESHTIME);
}

/*******************   查找数据       ***********************/
void TabRegister::on_pushButtonFind_clicked()
{
    selectData(BLDATA);
}

/*******************   选中一行       ***********************/
void TabRegister::on_tableWidget_clicked(const QModelIndex &index)
{

}

/*******************   双击跳转至第二个界面       ***********************/
void TabRegister::on_tableWidget_doubleClicked(const QModelIndex &currentIndex)
{
    QAbstractItemModel *model = ui->tableWidget->model();
    QModelIndex index = model->index(currentIndex.row(), 1);
    emit sendNumber(model->data(index).toString());
}

/*******************   打印标签       ***********************/
void TabRegister::on_actionPrintLabel_triggered()
{

}
