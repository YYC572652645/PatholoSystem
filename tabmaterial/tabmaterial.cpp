#include "tabmaterial.h"
#include "ui_tabmaterial.h"
#include "globaldef.h"
#include <QTreeWidgetItem>
#include "materialdata.h"

TabMaterial::TabMaterial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabmaterial)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();
    this->initConnect();

    this->selectData();
}

TabMaterial::~TabMaterial()
{
    delete ui;
    SAFEDELETE(normalMaterial);
}


/*******************   初始化控件    ***********************/
void TabMaterial::initControl()
{
    //设置单行选中
    ui->treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget->setAlternatingRowColors(true);

    //设置为不可编辑
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //添加界面
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->addWidget(&patientInfo);
    ui->widgetInfo->setLayout(vBoxLayout);

    //设置表头点击禁止塌陷
    ui->treeWidget->header()->setHighlightSections(false);

    //设置点击表头排序
    ui->treeWidget->setSortingEnabled(true);

    //设置根据内容调整列宽
    ui->treeWidget->header()->setStretchLastSection(true);
    ui->treeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    //设置水平伸展策略
    ui->splitter->setStretchFactor(1, 0);

    //设置字体
    ui->treeWidget->setFont(QFont("ZYsong", 12));
}

/*******************   初始化数据    ***********************/
void TabMaterial::initData()
{
    normalMaterial = new NormalMaterial(this); //常规取材
}

/*******************   初始化信号与槽    ***********************/
void TabMaterial::initConnect()
{
    connect(normalMaterial, SIGNAL(sendSelect()), this, SLOT(receiveSelect()));
}

/*******************   确定查询数据    ***********************/
void TabMaterial::receiveSelect()
{
    selectData();
}

/*******************   查询数据    ***********************/
void TabMaterial::selectData()
{
    ui->treeWidget->clear();

    MATERIALDATA->selectData();

    QList<DataParent> parentList = MATERIALDATA->getParentList();
    QList<DataChild>  childList = MATERIALDATA->getChildList();


    for(int i = 0; i < parentList.size(); i ++)
    {
        QTreeWidgetItem* parentItem = TREEDATA(ui->treeWidget);

        parentItem->setText(0, parentList.at(i).pCode);
        parentItem->setText(1, parentList.at(i).samplingCount);

        for(int j = 0; j < childList.size(); j ++)
        {
            if(parentList.at(i).samplingId == childList.at(j).samplingId)
            {
                QTreeWidgetItem* childItem = TREEITEM();

                childItem->setText(NUMBERING,        childList.at(j).embedCode);
                childItem->setText(SERIALNUMBER,     childList.at(j).sn);
                childItem->setText(ORGANIZATIONNAME, childList.at(j).tissue);
                childItem->setText(ISPRINTED,        childList.at(j).printed);
                childItem->setText(PRINTTIME,        childList.at(j).printTime);
                childItem->setText(ISMATERIAL,       childList.at(j).sampled);
                childItem->setText(MATERIALTIME,     childList.at(j).samplingTime);
                childItem->setText(MATERIALPEOPLE,   childList.at(j).sampler);

                parentItem->addChild(childItem);
            }
        }
    }

    ui->treeWidget->expandAll();

}

/*******************   接收病理号    ***********************/
void TabMaterial::receiveNumber(QString number, QString id)
{
    normalMaterial->showWidget(number, id);
}

/*******************   常规取材    ***********************/
void TabMaterial::on_actionNormalMaterial_triggered()
{
    normalMaterial->showWidget();
}

/*******************   添加包埋    ***********************/
void TabMaterial::on_actionAddBaoMai_triggered()
{
    if(NULL == ui->treeWidget->currentItem()) return;

    QTreeWidgetItem* item = TREEITEM();

    if(NULL == ui->treeWidget->currentItem()->parent())
    {
        for(int i = 0; i < ui->treeWidget->columnCount(); i ++)
        {
            item->setText(i, "this is a program");
        }
        ui->treeWidget->currentItem()->addChild(item);
    }

    ui->treeWidget->expandItem(ui->treeWidget->currentItem());
}

/*******************   打印    ***********************/
void TabMaterial::on_actionPrintLabel_triggered()
{

}

/*******************   批量打印    ***********************/
void TabMaterial::on_actionPrintMoreLabel_triggered()
{

}

/*******************   添加病理号    ***********************/
void TabMaterial::on_actionAddBingLiNumber_triggered()
{
    QTreeWidgetItem* item = TREEDATA(ui->treeWidget);

    for(int i = 0; i < ui->treeWidget->columnCount(); i ++)
    {
        item->setText(i, "11111");
    }

    item->setSelected(true);

    ui->treeWidget->setCurrentItem(item);

    //item->setCheckState(ui->treeWidget->currentColumn(), Qt::Checked);
}

/*******************   双击控件    ***********************/
void TabMaterial::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    if(NULL == ui->treeWidget->currentItem()->parent())
    {
        normalMaterial->showWidget();
    }
}
