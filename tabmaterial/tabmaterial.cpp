#include "tabmaterial.h"
#include "ui_tabmaterial.h"
#include "globaldef.h"
#include <QTreeWidgetItem>
#include "materialdata.h"
#include "config/qreadini.h"
#include "../../tabsystemset/tabsystemdata.h"
#include "messagebox/messagedialog.h"
#include <QFileDialog>
#include <QDateTime>

/*******************   构造函数            ***********************/
TabMaterial::TabMaterial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabmaterial)
{
    ui->setupUi(this);

    this->initControl();
    this->initData();
    this->initConnect();

    this->selectData(ALLDATA);

    timer = new QTimer(this);
    movie = new QMovie(":/image/image/refresh.gif");

    connect(timer, SIGNAL(timeout()), this, SLOT(updateMovie()));
}

/*******************   析构函数            ***********************/
TabMaterial::~TabMaterial()
{
    delete ui;
    SAFEDELETE(normalMaterial);
    SAFEDELETE(templateSetUp);
    SAFEDELETE(menu);
    SAFEDELETE(print);
    SAFEDELETE(del);
    SAFEDELETE(refresh);
    SAFEDELETE(movie);
    SAFEDELETE(timer);
    SAFEDELETE(currentItem);
}

/*******************   初始化控件          ***********************/
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
    ui->treeWidget->setColumnWidth(0, 210);
    ui->treeWidget->setColumnWidth(4, 160);
    ui->treeWidget->setColumnWidth(6, 160);

    //设置根据内容调整列宽
    ui->treeWidget->header()->setStretchLastSection(true);

    //设置水平伸展策略
    ui->splitter->setStretchFactor(1, 0);

    //设置字体
    ui->treeWidget->setFont(QFont("ZYsong", 12));

    //设置添加病理号不可用
    ui->actionAddBingLiNumber->setEnabled(false);

    //设置添加病理号不可用
    ui->actionAddBaoMai->setEnabled(false);

    //设置双击不收缩
    ui->treeWidget->setExpandsOnDoubleClick(false);

    //创建菜单
    this->createActions();
}

/*******************   创建菜单            ***********************/
void TabMaterial::createActions()
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
void TabMaterial::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();

    menu->addAction(print);
    menu->addAction(refresh);
    menu->addAction(del);

    menu->exec(QCursor::pos());

    event->accept();
}

/*******************   初始化数据          ***********************/
void TabMaterial::initData()
{
    normalMaterial = new NormalMaterial(this);               //常规取材
    templateSetUp = new TemplateSetUp(SECONDWIDGET, this);   //打印模板
    updateFlage = false;
}

/*******************   初始化信号与槽       ***********************/
void TabMaterial::initConnect()
{
    connect(normalMaterial, SIGNAL(sendSelect()), this, SLOT(receiveSelect()));
}

/*******************   更新gif            ***********************/
void TabMaterial::updateMovie()
{
    movie->stop();
    timer->stop();
}

/*******************   确定查询数据        ***********************/
void TabMaterial::receiveSelect()
{
    selectData(ALLDATA);

    ui->treeWidget->scrollToBottom();
}

/*******************   刷新数据            ***********************/
void TabMaterial::on_pushButtonRefresh_clicked()
{
    //播放gif
    ui->labelMovie->setMovie(movie);
    movie->start();

    selectData(ALLDATA);

    timer->start(GLOBALDEF::REFRESHTIME);
}

/*******************   查询数据            ***********************/
void TabMaterial::selectData(int type)
{
    ui->treeWidget->clear();

    if(type == ALLDATA)
    {
        MATERIALDATA->selectData(ALLDATA);
    }
    else
    {
        MATERIALDATA->selectData(BLDATA, ui->lineEditNumber->text());
    }

    QList<DataParent> parentList = MATERIALDATA->getParentList();
    QList<DataChild>  childList = MATERIALDATA->getChildList();

    if(parentList.size() > 0)
    {
        ui->actionAddBingLiNumber->setEnabled(true);
        ui->actionAddBaoMai->setEnabled(true);
    }

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
                parentItem->addChild(childItem);

                childItem->setText(NUMBERING,        childList.at(j).embedCode);
                childItem->setText(SERIALNUMBER,     childList.at(j).sn);
                childItem->setText(ORGANIZATIONNAME, childList.at(j).tissue);

                {
                    QWidget     *widget     = new QWidget(this);
                    QCheckBox   *checkBox   = new QCheckBox(this);
                    QHBoxLayout *hboxLayout = new QHBoxLayout(this);
                    checkBox->setMinimumHeight(16);
                    hboxLayout->addWidget(checkBox);
                    hboxLayout->setAlignment(checkBox, Qt::AlignCenter);
                    widget->setLayout(hboxLayout);
                    ui->treeWidget->setItemWidget(childItem, ISPRINTED, widget);

                    if(childList.at(j).printed == GLOBALDEF::PRINTFLAGE)
                    {
                        checkBox->setChecked(true);
                    }
                    checkBox->setEnabled(false);
                }

                childItem->setText(PRINTTIME, childList.at(j).printTime);

                if(childList.at(j).sampled == "0")
                {
                    childItem->setCheckState(ISMATERIAL, Qt::Unchecked);
                }
                else
                {
                    childItem->setCheckState(ISMATERIAL, Qt::Checked);
                }


                childItem->setText(MATERIALTIME,     childList.at(j).samplingTime);
                childItem->setText(MATERIALPEOPLE,   childList.at(j).sampler);

                if(currentCode == childList.at(j).embedCode)
                {
                    childItem->setSelected(true);
                    ui->treeWidget->setCurrentItem(childItem);
                    ui->treeWidget->scrollToItem(childItem);
                    currentCode.clear();
                }
            }
        }
    }

    ui->treeWidget->expandAll();
}

/*******************   接收病理号          ***********************/
void TabMaterial::receiveNumber(QString number, QString id)
{
    normalMaterial->showWidget(number, id);
}

/*******************   常规取材            ***********************/
void TabMaterial::on_actionNormalMaterial_triggered()
{
    normalMaterial->showWidget();
}

/*******************   添加包埋            ***********************/
void TabMaterial::on_actionAddBaoMai_triggered()
{
    if(NULL == ui->treeWidget->currentItem()) return;

    //获取编码规则
    SYSTEMDATA->codeBeginSelectData();
    QMap<QString, QString>mapData = SYSTEMDATA->getCodeBeginSnSetInfo();

    int count = 0;

    QString samplingId;

    QString pCode;

    if(NULL == ui->treeWidget->currentItem()->parent())
    {
        pCode = ui->treeWidget->currentItem()->text(0);
        samplingId = getIndexNumber(BLDATA, ui->treeWidget->currentItem()->text(0));
    }
    else
    {
        pCode = ui->treeWidget->currentItem()->parent()->text(0);
        samplingId = getIndexNumber(CHILDDATA, ui->treeWidget->currentItem()->text(0));
    }

    count = MATERIALDATA->selectBaoMai(samplingId);

    DataChild dataChild;

    dataChild.samplingId = samplingId;                    //取材ID
    dataChild.sn = QString::number(++count);              //序号

    {
        dataChild.embedCode = pCode;                      //病理号子序号

        if(mapData[HYPHEN] != "0")
        {
            dataChild.embedCode +=  "-";                 //病理号子序号
        }

        switch(mapData[NUMBERTYPE].toInt())
        {
        case 0: dataChild.embedCode +=  QString::number(count);          break;  //病理号子序号
        case 1: dataChild.embedCode +=  numberToLetter(LOWER, count);    break;  //病理号子序号
        case 2: dataChild.embedCode +=  numberToLetter(CAPITAL, count);; break;  //病理号子序号
        }
    }

    dataChild.printed = "0";                              //是否打印
    dataChild.sampled = "0";                              //是否取材
    dataChild.samplingTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");;             //取材时间

    MATERIALDATA->insertChildData(dataChild);

    currentCode = dataChild.embedCode;

    selectData(ALLDATA);
}

/*******************   打印               ***********************/
void TabMaterial::on_actionPrintLabel_triggered()
{
    if(NULL == ui->treeWidget->currentItem()) return;
    if(NULL == ui->treeWidget->currentItem()->parent()) return;

    DataChild data = getDataChild(ui->treeWidget->currentItem()->text(0));

    if(data.printed != "0")
    {
        int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("当前标签已经打印，您需要重打吗？"), GLOBALDEF::SUCCESSIMAGE, false, this);
        if(ok == QDialog::Accepted)
        {
            data.printTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

            MATERIALDATA->updateChildData(data);

            templateSetUp->printImage(data.embedCode);
        }
    }
    else
    {
        templateSetUp->printImage(data.embedCode);

        data.printed = "1";

        data.printTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

        MATERIALDATA->updateChildData(data);
    }

    selectData(ALLDATA);
}

/*******************   批量打印            ***********************/
void TabMaterial::on_actionPrintMoreLabel_triggered()
{
    if(NULL == ui->treeWidget->currentItem()) return;
    if(NULL != ui->treeWidget->currentItem()->parent()) return;

    DataParent data = getDataParent(ui->treeWidget->currentItem()->text(0));

    QList<DataChild> childList = MATERIALDATA->getChildList();

    for(int i = 0; i < childList.size(); i++)
    {
        if(childList.at(i).samplingId ==  data.samplingId)
        {
            templateSetUp->printImage(childList.at(i).embedCode);

            childList[i].printed = "1";

            childList[i].printTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

            MATERIALDATA->updateChildData(childList.at(i));
        }
    }

    selectData(ALLDATA);
}

/*******************   添加病理号           ***********************/
void TabMaterial::on_actionAddBingLiNumber_triggered()
{
    DataParent data;

    INICONFIG->readIni();

    QString recentNumber = INICONFIG->getRecentNumber();

    QString id = MATERIALDATA->selectCode(recentNumber);

    data.samplingId = id;                                                                                   //ID

    if(id.isEmpty())
    {
        data.samplingId = QString::number(recentNumber.right(subFinger(recentNumber)).toUInt() + 1);        //设置ID+1

        data.pCode = recentNumber.left(recentNumber.size() - subFinger(recentNumber)) + data.samplingId;    //病理号
    }
    else
    {
        data.samplingId = QString::number(data.samplingId.toUInt() + 1);                                    //设置ID+1

        data.pCode = recentNumber.left(recentNumber.size() - subFinger(recentNumber)) + data.samplingId;    //病理号
    }

    qDebug()<<data.pCode<<data.samplingId;

    INICONFIG->writeQCIni(data.pCode);

    data.createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");      //取材时间

    MATERIALDATA->insertParentData(data);

    //获取编码规则
    SYSTEMDATA->codeBeginSelectData();
    QMap<QString, QString>mapData = SYSTEMDATA->getCodeBeginSnSetInfo();

    DataChild dataChild;

    dataChild.samplingId = data.samplingId;               //取材ID
    dataChild.sn = "1";                                   //序号

    {
        dataChild.embedCode = data.pCode;                 //病理号子序号

        if(mapData[HYPHEN] != "0")
        {
            dataChild.embedCode +=  "-";                 //病理号子序号
        }

        switch(mapData[NUMBERTYPE].toInt())
        {
        case 0: dataChild.embedCode +=  "1"; break;      //病理号子序号
        case 1: dataChild.embedCode +=  "a"; break;      //病理号子序号
        case 2: dataChild.embedCode +=  "A"; break;      //病理号子序号
        }
    }

    dataChild.printed = "0";                              //是否打印
    dataChild.sampled = "0";                              //是否取材
    dataChild.samplingTime = data.createTime;             //取材时间

    MATERIALDATA->insertChildData(dataChild);

    currentCode = data.pCode;

    selectData(ALLDATA);

    ui->treeWidget->scrollToBottom();
}

/*******************   双击控件             ***********************/
void TabMaterial::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    if(NULL == ui->treeWidget->currentItem()->parent())
    {
        DataParent data = getDataParent(ui->treeWidget->currentItem()->text(0));

        normalMaterial->setData(data);

        normalMaterial->showWidget();
    }
    else
    {
        currentRow = index.row();
        currentColume= index.column();

        currentItem = ui->treeWidget->currentItem();

        if(index.column() == ORGANIZATIONNAME || index.column() == MATERIALTIME ||index.column() == MATERIALPEOPLE)
        {
            ui->treeWidget->closePersistentEditor(currentItem, ORGANIZATIONNAME);
            ui->treeWidget->closePersistentEditor(currentItem, MATERIALTIME);
            ui->treeWidget->closePersistentEditor(currentItem, MATERIALPEOPLE);

            ui->treeWidget->openPersistentEditor(ui->treeWidget->currentItem(), index.column());
        }
    }
}

/*******************   单击控件             ***********************/
void TabMaterial::on_treeWidget_clicked(const QModelIndex &index)
{
    if(currentRow != index.row() || currentColume != index.column())
    {
        if(currentItem != NULL)
        {
            ui->treeWidget->closePersistentEditor(currentItem, ORGANIZATIONNAME);
            ui->treeWidget->closePersistentEditor(currentItem, MATERIALTIME);
            ui->treeWidget->closePersistentEditor(currentItem, MATERIALPEOPLE);
        }
    }

    if(NULL == ui->treeWidget->currentItem()->parent())
    {
        patientInfo.setPaintId(getIndexNumber(BLDATA, ui->treeWidget->currentItem()->text(0)));

        patientInfo.setRegId(ui->treeWidget->currentItem()->text(0));

        patientInfo.setSelect();
    }

    if(updateFlage)
    {
        updateFlage= false;

        if(NULL == ui->treeWidget->currentItem()) return;
        if(NULL == ui->treeWidget->currentItem()->parent()) return;
        if(isEmpty(dataUpdate)) return;

        MATERIALDATA->updateChildData(dataUpdate);

        dataChildClear();
    }
}

/*******************   查询数据             ***********************/
void TabMaterial::on_pushButtonFind_clicked()
{
    selectData(BLDATA);
}

/*******************   删除数据             ***********************/
void TabMaterial::on_actionDeleteInfo_triggered()
{
    int ok = MESSAGEBOX->setInfo(tr("系统提示"),tr("将删除该信息，此操作不可逆，您确定吗？"), GLOBALDEF::SUCCESSIMAGE, false, this);
    if(ok == QDialog::Accepted)
    {
        if(NULL == ui->treeWidget->currentItem()->parent())
        {
            MATERIALDATA->deleteData(BLDATA, getIndexNumber(BLDATA, ui->treeWidget->currentItem()->text(0)));
        }
        else
        {
            MATERIALDATA->deleteData(CHILDDATA, getIndexNumber(CHILDDATA, ui->treeWidget->currentItem()->text(0)), ui->treeWidget->currentItem()->text(0));
        }

        selectData(ALLDATA);
    }
}

/*******************   获取id               ***********************/
QString TabMaterial::getIndexNumber(int type, QString blNumber)
{
    if(type == BLDATA)
    {
        QList<DataParent> parentList = MATERIALDATA->getParentList();

        for(int i = 0; i < parentList.size(); i++)
        {
            if(parentList.at(i).pCode ==  blNumber)
            {
                return parentList.at(i).samplingId;
            }
        }
    }
    else
    {
        QList<DataChild> childList = MATERIALDATA->getChildList();

        for(int i = 0; i < childList.size(); i++)
        {
            if(childList.at(i).embedCode ==  blNumber)
            {
                return childList.at(i).samplingId;
            }
        }
    }

    return NULL;
}

/*******************   去字母               ***********************/
int TabMaterial::subFinger(QString number)
{
    int  count = 0;
    for(int i = number.size() - 1; i >= 0; i --)
    {
        if(number.at(i).isNumber())
        {
            count ++;
        }
        else
        {
            break;
        }
    }

    return count;
}

/*******************   数字转字母            ***********************/
QString TabMaterial::numberToLetter(int type, int number)
{
    QString str;

    int count = 1 + number / 26;     //是26个字母的多少倍
    int remainder = number % 26;     //余数
    for(int i = 0; i < count; i ++)
    {
        if(i + 1 < count)
        {
            if(type == CAPITAL)
            {
                str += 'Z';
            }
            else
            {
                str += 'z';
            }
        }
        else
        {
            char figer;

            if(type == CAPITAL)
            {
                figer = remainder + 64;
            }
            else
            {
                figer = remainder + 96;
            }

            str += figer;
        }
    }

    return str;
}

/*******************   获取父节点数据         ***********************/
DataParent TabMaterial::getDataParent(QString blNumber)
{
    DataParent data;

    QList<DataParent> parentList = MATERIALDATA->getParentList();

    for(int i = 0; i < parentList.size(); i++)
    {
        if(parentList.at(i).pCode ==  blNumber)
        {
            return parentList.at(i);
        }
    }

    return data;
}

/*******************   判断结构体是否为空      ***********************/
bool TabMaterial::isEmpty(DataChild data)
{
    if(!data.embedCode.isEmpty())   return false;
    if(!data.samplingId.isEmpty())  return false;
    if(!data.sn.isEmpty())          return false;
    if(!data.embedCode.isEmpty())   return false;
    if(!data.tissue.isEmpty())      return false;
    if(!data.printed.isEmpty())     return false;
    if(!data.printTime.isEmpty())   return false;
    if(!data.sampled.isEmpty())     return false;
    if(!data.sampler.isEmpty())     return false;
    if(!data.samplingTime.isEmpty()) return false;

    return true;
}

/*******************   清空结构体             ***********************/
void TabMaterial::dataChildClear()
{
    dataUpdate.embedCode.clear();
    dataUpdate.samplingId.clear();
    dataUpdate.sn.clear();
    dataUpdate.embedCode.clear();
    dataUpdate.tissue.clear();
    dataUpdate.printed.clear();
    dataUpdate.printTime.clear();
    dataUpdate.sampled.clear();
    dataUpdate.sampler.clear();
    dataUpdate.samplingTime.clear();
}

/*******************   获取子节点数据          ***********************/
DataChild TabMaterial::getDataChild(QString blNumber)
{
    DataChild data;

    QList<DataChild> childList = MATERIALDATA->getChildList();

    for(int i = 0; i < childList.size(); i++)
    {
        if(childList.at(i).embedCode ==  blNumber)
        {
            return childList.at(i);
        }
    }

    return data;
}

/*******************   打印模板                ***********************/
void TabMaterial::on_actionPrintTemplate_triggered()
{
    if(NULL != ui->treeWidget->currentItem())
    {
        templateSetUp->setQrCodeNumber(ui->treeWidget->currentItem()->text(0));
    }

    templateSetUp->showWidget();
}

/*******************   item内容改变            ***********************/
void TabMaterial::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    if(NULL == item) return;

    dataUpdate = getDataChild(item->text(0));

    if(!isEmpty(dataUpdate))
    {
        dataUpdate.tissue = item->text(ORGANIZATIONNAME);
        dataUpdate.sampler = item->text(MATERIALPEOPLE);
        dataUpdate.samplingTime = item->text(MATERIALTIME);

        if(Qt::Unchecked == item->checkState(ISMATERIAL))
        {
            dataUpdate.sampled = "0";
        }
        else
        {
            dataUpdate.sampled = "1";
        }

        updateFlage = true;
    }
}

/*******************   导出Excel               ***********************/
void TabMaterial::on_actionExtendExcel_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(NULL, "保存文件",".","Excel(*.xlsx *.xls);;txt(*.txt)");

    if(fileName.contains(".txt"))
    {
        this->extendTxt(fileName);
    }
    else
    {
        QList<QString>itemName;

        itemName.append(MATERALINFO::SN);
        itemName.append(MATERALINFO::PCODE);
        itemName.append(MATERALINFO::TISSUE);
        itemName.append(MATERALINFO::PRINTED);
        itemName.append(MATERALINFO::PRINTTIME);
        itemName.append(MATERALINFO::SAMPLED);
        itemName.append(MATERALINFO::SAMPLEDTIME);
        itemName.append(MATERALINFO::SAMPLEDPEOPLE);

        ExcelOperate * excelOperate = new ExcelOperate();

        excelOperate->setExtendType(GLOBALDEF::MATERIALTYPE);
        excelOperate->setItemName(itemName);
        excelOperate->setChildInfo(MATERIALDATA->getChildList());
        excelOperate->setFileName(fileName);

        connect(excelOperate, SIGNAL(finished()), excelOperate, SLOT(terminate()));

        excelOperate->start();
    }
}


/*******************   显示菜单            ***********************/
void TabMaterial::extendTxt(QString fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::Text | QIODevice::WriteOnly)) return;

    QTextStream txtOutput(&file);

    QList<DataChild> childList = MATERIALDATA->getChildList();

    for(int i = 0; i < childList.size(); i ++)
    {
        txtOutput << childList.at(i).embedCode << "$$HE" << "\n";
    }

    file.close();
}
