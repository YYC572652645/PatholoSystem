#include "tabregister.h"
#include "ui_tabregister.h"
#include "databasedef.h"
#include "globaldef.h"
#include "exceloperate/exceloperate.h"
#include <QMovie>
#include <QMessageBox>
#include <QModelIndex>
#include <QAbstractItemModel>
#include "messagebox/messagedialog.h"
#include <QFileDialog>

/*******************       构造函数                ***********************/
TabRegister::TabRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabregister)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();

    newSlices = new NewSlices(this);                                 //新编号
    newMoreSlices = new NewMoreSlices(this);                         //批量编号
    templateSetUp = new TemplateSetUp(FIRSTWIDGET, this);            //打印模板

    //初始化信号和槽
    connect(newSlices,     SIGNAL(signalSelect(int, int)),      this, SLOT(selectData(int, int)));
    connect(newSlices,     SIGNAL(printBLNumber(int, QString)), this, SLOT(printBLNumber(int, QString)));
    connect(newMoreSlices, SIGNAL(signalSelect(int, int)),      this, SLOT(selectData(int, int)));


    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));
}

/*******************       析构函数                ***********************/
TabRegister::~TabRegister()
{
    delete ui;
    SAFEDELETE(newSlices);
    SAFEDELETE(newMoreSlices);
    SAFEDELETE(templateSetUp);
    SAFEDELETE(movie);
    SAFEDELETE(timer);
    SAFEDELETE(menu);
    SAFEDELETE(print);
    SAFEDELETE(del);
    SAFEDELETE(refresh);
}

/*******************       更新gif                ***********************/
void TabRegister::updateMovie()
{
    movie->stop();
    timer->stop();
}

/*******************       打印数据                ***********************/
void TabRegister::printBLNumber(int count, QString number)
{
    for(int i = 0; i < count; i ++)
    {
        templateSetUp->printImage(number);
    }
}

/*******************       查询数据                ***********************/
void TabRegister::selectData(int type, int scrollFlage)
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

    ui->tableWidget->setRowCount(dataCount);     //设置表格行数

    for(int i = 0; i < dataCount; i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(registerData.registerInfo.at(i).pCode));          //序号
        ui->tableWidget->setItem(i, 1, DATA(registerData.registerInfo.at(i).sn));             //病理号
        ui->tableWidget->setItem(i, 2, DATA(registerData.registerInfo.at(i).printQuantity));  //打印数量

        {
            QWidget     *widget     = new QWidget(this);
            QCheckBox   *checkBox   = new QCheckBox(this);
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

    if(scrollFlage)
    {
        //滑动至最后一行
        ui->tableWidget->scrollToBottom();

        //设置第一行为当前选中行
        if(dataCount != 0)
        {
            ui->tableWidget->selectRow(dataCount - 1);
            ui->tableWidget->setFocus();
        }

        if(registerData.registerInfo.size() != 0)
        {
            patientInfo.setPaintId(registerData.registerInfo.last().pCode);
            patientInfo.setRegId(registerData.registerInfo.last().sn);
        }
    }
}

/*******************       初始化控件              ***********************/
void TabRegister::initControl()
{
    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setAlternatingRowColors(true);

    //纵向隐藏序号
    ui->tableWidget->verticalHeader()->setHidden(true);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

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
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setColumnWidth(1, 200);

    //设置水平伸展策略
    ui->splitter->setStretchFactor(1, 0);

    //创建菜单
    this->createActions();
}

/*******************       创建菜单                ***********************/
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

/*******************       显示菜单                ***********************/
void TabRegister::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(print);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}

/*******************       初始化数据               ***********************/
void TabRegister::initData()
{
    selectData(ALLDATA, true);
}

/*******************       新建编号                 ***********************/
void TabRegister::on_actionNewNumber_triggered()
{
    newSlices->showDialog();
}

/*******************       批量编号                 ***********************/
void TabRegister::on_actionNewMoreNumber_triggered()
{
    newMoreSlices->showDialog();
}

/*******************       打印模板                 ***********************/
void TabRegister::on_actionPrintTemplate_triggered()
{
    if(NULL != ui->tableWidget->currentItem() && registerData.registerInfo.size() > ui->tableWidget->currentRow())
    {
        templateSetUp->setQrCodeNumber(registerData.registerInfo.at(ui->tableWidget->currentRow()).sn);
    }

    templateSetUp->showWidget();
}

/*******************       删除数据                 ***********************/
void TabRegister::on_actionDeleteInfo_triggered()
{
    int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("确定删除该数据吗？此操作不可逆！"),GLOBALDEF::SUCCESSIMAGE, false, this);
    if(ok == QDialog::Accepted)
    {
        for(int i = 0; i < ui->tableWidget->selectedItems().size() ; i += 4)
        {
            int currentRow = ui->tableWidget->selectedItems().at(i)->row();

            if(currentRow >= registerData.registerInfo.size()) continue;

            registerData.deleteRowData(registerData.registerInfo.at(currentRow).id);
        }

        this->selectData(ALLDATA, false);
    }
}

/*******************       清空数据                 ***********************/
void TabRegister::on_actionClearInfo_triggered()
{
    int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("确定清空数据吗？此操作不可逆！"),GLOBALDEF::SUCCESSIMAGE, false, this);
    if(ok == QDialog::Accepted)
    {
        registerData.deleteAllData();
        this->selectData(ALLDATA, false);
    }
}

/*******************       导出Excel               ***********************/
void TabRegister::on_actionExtendExcel_triggered()
{
    QList<QString>itemName;

    itemName.append(PCODE);
    itemName.append(SN);
    itemName.append(PRINTQUANTITY);
    itemName.append(PRINTED);
    itemName.append(CREATETIME);

    QString fileName = QFileDialog::getSaveFileName(NULL, "保存文件",".","Excel(*.xlsx *.xls)");

    ExcelOperate * excelOperate = new ExcelOperate();

    excelOperate->setExtendType(GLOBALDEF::REGTYPE);
    excelOperate->setItemName(itemName);
    excelOperate->setRegisterInfo(registerData.registerInfo);
    excelOperate->setFileName(fileName);

    connect(excelOperate, SIGNAL(finished()), excelOperate, SLOT(terminate()));

    excelOperate->start();
}

/*******************       刷新数据                 ***********************/
void TabRegister::on_pushButtonRefresh_clicked()
{
    //播放gif
    ui->labelMovie->setMovie(movie);
    movie->start();

    selectData(ALLDATA, true);

    timer->start(GLOBALDEF::REFRESHTIME);
}

/*******************       查找数据                 ***********************/
void TabRegister::on_pushButtonFind_clicked()
{
    selectData(BLDATA, true);
}

/*******************       选中一行                 ***********************/
void TabRegister::on_tableWidget_clicked(const QModelIndex &currentIndex)
{
    QAbstractItemModel *model = ui->tableWidget->model();
    QModelIndex index = model->index(currentIndex.row(), 0);

    patientInfo.setPaintId(model->data(index).toString());

    index = model->index(currentIndex.row(), 1);

    patientInfo.setRegId(model->data(index).toString());

    //如果是自动保存，则保存
    if(patientInfo.getIsAutoSaveFlage())
    {
        patientInfo.on_actionSavePatientInfo_triggered();
    }

    patientInfo.setSelect();
}

/*******************       双击跳转至第二个界面       ***********************/
void TabRegister::on_tableWidget_doubleClicked(const QModelIndex &currentIndex)
{
    QAbstractItemModel *model = ui->tableWidget->model();
    QModelIndex index = model->index(currentIndex.row(), 1);
    QModelIndex secondIndex = model->index(currentIndex.row(), 0);

    emit sendNumber(model->data(index).toString(), model->data(secondIndex).toString());
}

/*******************       打印标签                 ***********************/
void TabRegister::on_actionPrintLabel_triggered()
{
    for(int i = 0; i < ui->tableWidget->selectedItems().size() ; i += 4)
    {
        int currentRow = ui->tableWidget->selectedItems().at(i)->row();

        if(currentRow >= registerData.registerInfo.size()) continue;

        if(registerData.registerInfo.at(currentRow).printed != "0")
        {
            for(int i = 0; i < registerData.registerInfo.at(currentRow).printQuantity.toInt(); i ++)
            {
                templateSetUp->printImage(registerData.registerInfo.at(currentRow).sn);
            }
        }
        else
        {
            for(int i = 0; i < registerData.registerInfo.at(currentRow).printQuantity.toInt(); i ++)
            {
                templateSetUp->printImage(registerData.registerInfo.at(currentRow).sn);
            }

            registerData.updateBLData("1", registerData.registerInfo.at(currentRow).id);
        }
    }

    selectData(ALLDATA, false);
}

/*******************       批量打印打印标签          ***********************/
void TabRegister::on_actionPrintMoreLabel_triggered()
{
    int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("即将批量打印所有剩余的病理登记标签，您确认吗？"),GLOBALDEF::SUCCESSIMAGE, false, this);
    if(ok == QDialog::Accepted)
    {
        for(int i = 0; i < registerData.registerInfo.size(); i ++)
        {
            if(registerData.registerInfo.at(i).printed == "0")
            {
                for(int j = 0; j < registerData.registerInfo.at(i).printQuantity.toInt(); j ++)
                {
                    templateSetUp->printImage(registerData.registerInfo.at(i).sn);
                }

                registerData.updateBLData("1", registerData.registerInfo.at(i).id);
            }
        }

        selectData(ALLDATA, false);
    }
}
