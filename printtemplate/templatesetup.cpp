#include "templatesetup.h"
#include "ui_templatesetup.h"
#include "QInputDialog"
#include "globaldef.h"
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QFontDialog>
#include <QFontDatabase>
#include <QColorDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QListWidgetItem>
#include "messagebox/messagedialog.h"
#include "config/qreadini.h"
#include "../globaldef.h"
#include <QJsonArray>
#include <QPrinterInfo>

/*********************     构造函数             **************************/
TemplateSetUp::TemplateSetUp(int type, QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::templatesetup)
  ,textEdit(NULL)
  ,fontBox(NULL)
  ,fontSizeBox(NULL)
  ,widthEdit (NULL)
  ,heightEdit(NULL)
  ,qrcode(NULL)
  ,selectLabelIndex(INVALIDVALUE)
  ,selectIndex(INVALIDVALUE)
  ,typeFlage(INVALIDVALUE)
{
    ui->setupUi(this);
    widgetType = type;

    this->setWindowTitle("打印模板");

    this->initControl();     //初始化属性页
    this->initConnect();     //连接信号与槽
    this->initValue();       //初始化数据

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
}

/*********************     析构函数             **************************/
TemplateSetUp::~TemplateSetUp()
{
    deleteAll();
    SAFEDELETE(fontBox);
    SAFEDELETE(fontSizeBox);
    SAFEDELETE(widthEdit);
    SAFEDELETE(heightEdit);
    SAFEDELETE(qrcode);
    SAFEDELETE(textEdit);

    delete ui;
}

/*********************     显示对话框           **************************/
void TemplateSetUp::showWidget()
{
    if(!deleteFlage) deleteAll();         //先删除
    writeAll();                           //再写入

    this->setInfo();                      //设置信息
    this->generateQrCode(qrCodeNumber);   //生成二维码

    ui->widgetControl->clearBox();        //将边界去掉

    this->show();
}

/*********************     添加模板             **************************/
void TemplateSetUp::on_pushButtonAdd_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "系统提示", "请输入模板名称", QLineEdit::Normal, QString::null, &ok, Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

    bool flage = false;

    for(int i = 0; i < ui->listWidgetTemplate->count(); i ++)
    {
        if(text == ui->listWidgetTemplate->item(i)->text())
        {
            flage = true;
        }
    }

    if(ok && !text.isEmpty() && !flage)
    {
        ui->listWidgetTemplate->addItem(text);
    }
    else
    {
        return;
    }

    templateName = text;

    int rowCount = ui->listWidgetTemplate->count();

    if(rowCount != 0)
    {
        //选中最后一行
        ui->listWidgetTemplate->item(rowCount - 1)->setSelected(true);

        //滑动至最后一行
        ui->listWidgetTemplate->scrollToBottom();

        //设置当前行为最后一行
        ui->listWidgetTemplate->setCurrentRow(rowCount - 1);
    }
}

/*********************     删除模板             **************************/
void TemplateSetUp::on_pushButtonSub_clicked()
{
    if(ui->listWidgetTemplate->currentRow() >= ui->listWidgetTemplate->count()) return;

    if(NULL == ui->listWidgetTemplate->currentItem()) return;

    //删除列表项
    QListWidgetItem *item = ui->listWidgetTemplate->takeItem(ui->listWidgetTemplate->currentRow());
    delete item;

    //删除数据库信息
    templateData.deleteData(templateName, widgetType);

    //移除控件中的内容
    deleteAll();

    if(ui->listWidgetTemplate->count() > 0)
    {
        //设置当前行为最后一行
        ui->listWidgetTemplate->setCurrentRow(ui->listWidgetTemplate->count() - 1);

        //选中最后一行
        item = ui->listWidgetTemplate->item(ui->listWidgetTemplate->count() - 1);
        item->setSelected(true);

        //模板名称为当前名称
        templateName = item->text();

        writeAll();

        ui->labelInfo->setText(templateName);
    }
    else
    {
        ui->labelInfo->setText("");
    }

    templateData.selectData(widgetType);
}

/*********************     初始化控件           *************************/
void TemplateSetUp::initControl()
{
    //把表头上面去掉
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);

    //设置列表控件等宽显示
    QHeaderView *headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置列表控件等高显示
    QHeaderView *leftHeaderView=ui->tableWidget->verticalHeader();
    leftHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    //设置不能选择
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //去除点击的虚线
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    //内容控件
    textEdit = new QLineEdit(this);
    textEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(0, 1, textEdit);
    textEdit->setStyleSheet("background-color:transparent");

    //字体大小
    fontBox = new QFontComboBox(this);
    fontBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontBox->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(1, 1, fontBox);

    //字体
    QFontDatabase fontDb;
    fontSizeBox  = new QComboBox(this);
    fontSizeBox->setEditable(true);
    fontSizeBox->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(2, 1, fontSizeBox);

    foreach (int size, fontDb.standardSizes())
    {
        fontSizeBox->addItem(QString::number(size));
    }

    //宽度
    widthEdit = new QLineEdit(this);
    widthEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(3, 1, widthEdit);
    widthEdit->setStyleSheet("background-color:transparent");

    //高度
    heightEdit= new QLineEdit(this);
    heightEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(4, 1, heightEdit);
    heightEdit->setStyleSheet("background-color:transparent");

    //内容
    QTableWidgetItem *textItem = new QTableWidgetItem("内容:");
    textItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0, 0, textItem);

    //字体
    QTableWidgetItem *fontItem = new QTableWidgetItem("字体:");
    fontItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1, 0, fontItem);

    //字号
    QTableWidgetItem *fontSizeItem = new QTableWidgetItem("字号:");
    fontSizeItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2, 0, fontSizeItem);

    //宽度
    QTableWidgetItem *widthItem = new QTableWidgetItem("宽度:");
    widthItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3, 0, widthItem);

    //高度
    QTableWidgetItem *heightItem = new  QTableWidgetItem("高度:");
    heightItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4, 0, heightItem);

    //默认字体大小为16
    fontSizeBox->setCurrentIndex(8);

    deleteFlage = true;   //是否删除标志位
}

/*********************     连接信号与槽         *************************/
void TemplateSetUp::initConnect()
{
    connect(fontBox,     SIGNAL(currentFontChanged(const QFont)), this, SLOT(currentFontChange()));
    connect(fontSizeBox, SIGNAL(currentTextChanged(QString)),     this, SLOT(currentFontChange()));
    connect(textEdit,    SIGNAL(textChanged(QString)),            this, SLOT(textChange()));
    connect(widthEdit,   SIGNAL(textEdited(QString)),             this, SLOT(sizeChange()));
    connect(heightEdit,  SIGNAL(textEdited(QString)),             this, SLOT(sizeChange()));
}

/*********************     初始化数据           *************************/
void TemplateSetUp::initValue()
{
    QList<QString>templateList = INICONFIG->getTemplateList();

    for(int i = 0; i < templateData.selectData(widgetType); i ++)
    {
        readJson(templateData.getDataTemplate().at(i).templateText, templateData.getDataTemplate().at(i).templateName);

        ui->listWidgetTemplate->addItem(templateData.getDataTemplate().at(i).templateName);

        if(widgetType >= templateList.size()) continue;

        if(templateData.getDataTemplate().at(i).templateName == templateList.at(widgetType))
        {
            templateName = templateList.at(widgetType);

            ui->listWidgetTemplate->item(i)->setSelected(true);
            ui->listWidgetTemplate->setCurrentRow(i);

            if(!deleteFlage) deleteAll();         //先删除
            writeAll();                           //再写入

            this->setInfo();                      //设置信息
            this->generateQrCode(qrCodeNumber);   //生成二维码

            ui->widgetControl->clearBox();        //将边界去掉

            ui->labelInfo->setText("当前模板为 <" + templateName + ">");
        }
    }

    //登记和取材
    if(widgetType == FIRSTWIDGET || widgetType == SECONDWIDGET)
    {
        ui->listWidgetControl->addItem("文字");
        ui->listWidgetControl->addItem("病理号");
        ui->listWidgetControl->addItem("二维条码");
    }
    //常规切片
    else if(widgetType == THIRDWIDGET)
    {
        ui->listWidgetControl->addItem("染色类型");
        ui->listWidgetControl->addItem("染色指标");
        ui->listWidgetControl->addItem("其他");
        ui->listWidgetControl->addItem("切片日期");
        ui->listWidgetControl->addItem("切片人");
        ui->listWidgetControl->addItem("染色时间");
        ui->listWidgetControl->addItem("染色人");
        ui->listWidgetControl->addItem("单位名称");
    }

    //免疫组化切片
    else if(widgetType == FOURTHWIDGET)
    {
        ui->listWidgetControl->addItem("染色类型");
        ui->listWidgetControl->addItem("染色指标");
        ui->listWidgetControl->addItem("克隆号");
        ui->listWidgetControl->addItem("切片日期");
        ui->listWidgetControl->addItem("切片人");
        ui->listWidgetControl->addItem("染色时间");
        ui->listWidgetControl->addItem("染色人");
        ui->listWidgetControl->addItem("单位名称");
    }

    //特染切片
    else if(widgetType == FIVETHWIDGET)
    {
        ui->listWidgetControl->addItem("染色类型");
        ui->listWidgetControl->addItem("染色指标");
        ui->listWidgetControl->addItem("克隆号");
        ui->listWidgetControl->addItem("切片日期");
        ui->listWidgetControl->addItem("切片人");
        ui->listWidgetControl->addItem("染色时间");
        ui->listWidgetControl->addItem("染色人");
        ui->listWidgetControl->addItem("单位名称");
    }
    //免疫组化和特染指标设置
    else if(widgetType == SIXTHWIDGET || widgetType == SEVENTHWIDGET)
    {
        ui->listWidgetControl->addItem("文字");
        ui->listWidgetControl->addItem("染色指标");
        ui->listWidgetControl->addItem("二维条码");
    }
}

/*********************     删除所有控件         *************************/
void TemplateSetUp::deleteAll()
{
    QList<QLabel*> listLabel;

    for(int i = 0; i < TYPEMAX; i ++)
    {
        switch(i)
        {
        case TEXTTYPE:    listLabel = textLabel;   break;
        case BINGLITYPE:  listLabel = bingLiLabel; break;
        case QRCODETYPE:  listLabel = qrCodeLabel; break;
        case LABELFOUR:   listLabel = fourLabel;   break;
        case LABELFIVE:   listLabel = fiveLabel;   break;
        case LABELSIX:    listLabel = sixLabel;    break;
        case LABELSEVEN:  listLabel = sevenLabel;  break;
        case LABELEIGHT:  listLabel = eightLabel;  break;
        case LABELNINE:   listLabel = nineLabel;   break;
        case LABELTEN:    listLabel = tenLabel;    break;
        case LABELELEVEN: listLabel = elevenLabel; break;
        case LABELTWELVE: listLabel = twelveLabel; break;
        }

        for(int j = 0; j < listLabel.size(); j ++)
        {
            listLabel.at(j)->setText("");

            ui->widgetControl->selectWidget->removeWidget(listLabel.at(j));

            delete listLabel[j];
        }
    }

    selectLabelIndex = INVALIDVALUE;
    ui->widgetControl->clearBox();

    deleteFlage = true;
}

/*********************     写入控件            *************************/
void TemplateSetUp::writeAll()
{
    if(templateName.isEmpty())  return;

    dataList.clear();

    int count = templateData.selectData(widgetType);
    for(int i = 0; i < count; i ++)
    {
        readJson(templateData.getDataTemplate().at(i).templateText, templateData.getDataTemplate().at(i).templateName);
    }

    textLabel.clear();
    bingLiLabel.clear();
    qrCodeLabel.clear();
    fourLabel.clear();
    fiveLabel.clear();
    sixLabel.clear();
    sevenLabel.clear();
    eightLabel.clear();
    nineLabel.clear();
    tenLabel.clear();
    elevenLabel.clear();
    twelveLabel.clear();

    for(int i = 0; i < dataList[templateName].size(); i ++)
    {
        const QList<LabelData> &dataLabel = dataList[templateName];

        QLabel * label = new QLabel(this);   //声明一个Label

        QFont font;

        font.setPointSize(dataLabel.at(i).fontSize.toInt());
        font.setFamily(dataLabel.at(i).fontType);

        label->setFont(font);                             //设置显示字体

        label->setScaledContents(true);                   //设置自适应

        label->installEventFilter(this);                  //注册监听事件

        label->setText(dataLabel.at(i).labelText);        //设置内容

        int x = dataLabel.at(i).gemoryX.toInt();          //x坐标

        int y = dataLabel.at(i).gemoryY.toInt();          //Y坐标

        int width = dataLabel.at(i).labelWidth.toInt();   //宽度

        int height = dataLabel.at(i).labelHeight.toInt(); //高度

        label->setGeometry(x, y, width, height);          //设置位置

        label->setWordWrap(true);                         //设置换行

        switch(dataLabel.at(i).labelType.toInt())
        {
        case TEXTTYPE:     textLabel.append(label);   break;
        case BINGLITYPE:   bingLiLabel.append(label); break;
        case QRCODETYPE:   qrCodeLabel.append(label); break;
        case LABELFOUR:    fourLabel.append(label);   break;
        case LABELFIVE:    fiveLabel.append(label);   break;
        case LABELSIX:     sixLabel.append(label);    break;
        case LABELSEVEN:   sevenLabel.append(label);  break;
        case LABELEIGHT:   eightLabel.append(label);  break;
        case LABELNINE:    nineLabel.append(label);   break;
        case LABELTEN:     tenLabel.append(label);    break;
        case LABELELEVEN:  elevenLabel.append(label); break;
        case LABELTWELVE:  twelveLabel.append(label); break;
        }

        label->show();            //显示出来

        dataList[templateName][i].label = label;

        ui->widgetControl->selectWidget->addWidget(label);  //添加控件
    }

    deleteFlage = false;
}

/*********************     设置控件信息         *************************/
void TemplateSetUp::setInfo()
{
    for(int i = 0; i < bingLiLabel.size(); i ++)
    {
        bingLiLabel[i]->setText(qrCodeNumber);
    }

    if(widgetType == THIRDWIDGET)
    {
        for(int i = 0; i < fourLabel.size(); i ++)
        {
            fourLabel[i]->setText(dataNormalSlice.stainTypeName);
        }
        for(int i = 0; i < fiveLabel.size(); i ++)
        {
            fiveLabel[i]->setText(dataNormalSlice.staining);
        }
        for(int i = 0; i < sixLabel.size(); i ++)
        {
            sixLabel[i]->setText(dataNormalSlice.other);
        }
        for(int i = 0; i < sevenLabel.size(); i ++)
        {
            sevenLabel[i]->setText(dataNormalSlice.stainTime);
        }
        for(int i = 0; i < eightLabel.size(); i ++)
        {
            eightLabel[i]->setText(dataNormalSlice.stainer);
        }
        for(int i = 0; i < nineLabel.size(); i ++)
        {
            nineLabel[i]->setText(dataNormalSlice.sectionTime);
        }
        for(int i = 0; i < tenLabel.size(); i ++)
        {
            tenLabel[i]->setText(dataNormalSlice.sectioner);
        }
    }
    else if(widgetType == FOURTHWIDGET)
    {
        for(int i = 0; i < fourLabel.size(); i ++)
        {
            fourLabel[i]->setText(dataImmuneSlice.stainTypeName);
        }
        for(int i = 0; i < fiveLabel.size(); i ++)
        {
            fiveLabel[i]->setText(dataImmuneSlice.staining);
        }
        for(int i = 0; i < sixLabel.size(); i ++)
        {
            sixLabel[i]->setText(dataImmuneSlice.cloneNumber);
        }
        for(int i = 0; i < sevenLabel.size(); i ++)
        {
            sevenLabel[i]->setText(dataImmuneSlice.stainTime);
        }
        for(int i = 0; i < eightLabel.size(); i ++)
        {
            eightLabel[i]->setText(dataImmuneSlice.stainer);
        }
        for(int i = 0; i < nineLabel.size(); i ++)
        {
            nineLabel[i]->setText(dataImmuneSlice.sectionTime);
        }
        for(int i = 0; i < tenLabel.size(); i ++)
        {
            tenLabel[i]->setText(dataImmuneSlice.sectioner);
        }
    }
    else if(widgetType == FIVETHWIDGET)
    {
        for(int i = 0; i < fourLabel.size(); i ++)
        {
            fourLabel[i]->setText(dataSpecialSlice.stainTypeName);
        }
        for(int i = 0; i < fiveLabel.size(); i ++)
        {
            fiveLabel[i]->setText(dataSpecialSlice.staining);
        }
        for(int i = 0; i < sixLabel.size(); i ++)
        {
            sixLabel[i]->setText(dataSpecialSlice.cloneNumber);
        }
        for(int i = 0; i < sevenLabel.size(); i ++)
        {
            sevenLabel[i]->setText(dataSpecialSlice.stainTime);
        }
        for(int i = 0; i < eightLabel.size(); i ++)
        {
            eightLabel[i]->setText(dataSpecialSlice.stainer);
        }
        for(int i = 0; i < nineLabel.size(); i ++)
        {
            nineLabel[i]->setText(dataSpecialSlice.sectionTime);
        }
        for(int i = 0; i < tenLabel.size(); i ++)
        {
            tenLabel[i]->setText(dataSpecialSlice.sectioner);
        }
    }
}

/*********************     点击列表框中控件      *************************/
void TemplateSetUp::on_listWidgetControl_clicked(const QModelIndex &index)
{
    if(NULL == ui->listWidgetTemplate->currentItem()) return;

    QLabel * label = new QLabel(this);   //声明一个Label

    label->setFont(STARTFONT);           //设置显示字体

    label->setScaledContents(true);      //设置自适应

    label->installEventFilter(this);     //注册监听事件

    label->setWordWrap(true);            //设置换行

    QString strText = ui->listWidgetControl->currentItem()->text();

    switch(index.row())
    {
    case TEXTTYPE:    label->setText(strText);  textLabel.append(label);     textLabel.last()->setGeometry(80,100,100,100);     break;
    case BINGLITYPE:  label->setText(strText);  bingLiLabel.append(label);   bingLiLabel.last()->setGeometry(80,200,100,100);   break;
    case QRCODETYPE:  label->setText(strText);  qrCodeLabel.append(label);   qrCodeLabel.last()->setGeometry(180,100,100,100);  break;
    case LABELFOUR:   label->setText(strText);  fourLabel.append(label);     fourLabel.last()->setGeometry(180,200,100,100);    break;
    case LABELFIVE:   label->setText(strText);  fiveLabel.append(label);     fiveLabel.last()->setGeometry(280,100,100,100);    break;
    case LABELSIX:    label->setText(strText);  sixLabel.append(label);      sixLabel.last()->setGeometry(280,200,100,100);     break;
    case LABELSEVEN:  label->setText(strText);  sevenLabel.append(label);    sevenLabel.last()->setGeometry(380,100,100,100);   break;
    case LABELEIGHT:  label->setText(strText);  eightLabel.append(label);    eightLabel.last()->setGeometry(380,200,100,100);   break;
    case LABELNINE:   label->setText(strText);  nineLabel.append(label);     nineLabel.last()->setGeometry(80,300,100,100);     break;
    case LABELTEN:    label->setText(strText);  tenLabel.append(label);      tenLabel.last()->setGeometry(180,300,100,100);     break;
    case LABELELEVEN: label->setText(strText);  elevenLabel.append(label);   elevenLabel.last()->setGeometry(280,300,100,100);  break;
    case LABELTWELVE: label->setText(strText);  twelveLabel.append(label);   twelveLabel.last()->setGeometry(380,300,100,100);  break;
    }

    //将新建的控件数据添加到Map
    LabelData labelData;

    labelData.label       = label;
    labelData.labelType   = QString::number(index.row());
    labelData.labelText   = label->text();
    labelData.fontType    = "宋体";
    labelData.fontSize    = "16";
    labelData.labelWidth  = QString::number(label->width());
    labelData.labelHeight = QString::number(label->height());
    labelData.gemoryX     = QString::number(label->geometry().x());
    labelData.gemoryY     = QString::number(label->geometry().y());

    dataList[templateName].append(labelData);

    label->show();                                      //显示出来

    ui->widgetControl->selectWidget->addWidget(label);  //添加控件
}

/*********************     事件过滤            *************************/
bool TemplateSetUp::eventFilter(QObject *watched, QEvent *event)
{
    static QPoint lastPoint[TYPEMAX];

    QList<QLabel*> listLabel;

    for(int i = 0; i < TYPEMAX; i ++)
    {
        switch(i)
        {
        case TEXTTYPE:    listLabel = textLabel;   break;
        case BINGLITYPE:  listLabel = bingLiLabel; break;
        case QRCODETYPE:  listLabel = qrCodeLabel; break;
        case LABELFOUR:   listLabel = fourLabel;   break;
        case LABELFIVE:   listLabel = fiveLabel;   break;
        case LABELSIX:    listLabel = sixLabel;    break;
        case LABELSEVEN:  listLabel = sevenLabel;  break;
        case LABELEIGHT:  listLabel = eightLabel;  break;
        case LABELNINE:   listLabel = nineLabel;   break;
        case LABELTEN:    listLabel = tenLabel;    break;
        case LABELELEVEN: listLabel = elevenLabel; break;
        case LABELTWELVE: listLabel = twelveLabel; break;
        }

        for(int j = 0; j < listLabel.size(); j ++)
        {
            if(watched == listLabel[j])
            {
                if(event->type() == QEvent::MouseButtonPress)
                {
                    QMouseEvent* e = static_cast<QMouseEvent*>(event);

                    if(listLabel[j]->rect().contains(e->pos()) && (e->button() == Qt::LeftButton))
                    {
                        lastPoint[i] = e->pos();
                    }

                    typeFlage = i;

                    selectLabelIndex = j;

                    ui->widgetControl->selectWidget->addWidget(listLabel[j]);

                    widthEdit->setText(QString::number(listLabel[j]->width()));
                    heightEdit->setText(QString::number(listLabel[j]->height()));
                    textEdit->setText(listLabel[j]->text());

                    for(int k = 0; k < dataList[templateName].size(); k ++)
                    {
                        if(dataList[templateName].at(k).labelType.toInt() == typeFlage
                                && dataList[templateName].at(k).label->geometry().x() == listLabel[j]->geometry().x()
                                && dataList[templateName].at(k).label->geometry().y() == listLabel[j]->geometry().y())
                        {
                            fontBox->setCurrentText(dataList[templateName].at(k).fontType);
                            fontSizeBox->setCurrentText(dataList[templateName].at(k).fontSize);

                            break;
                        }
                    }

                    if(typeFlage != TEXTTYPE)
                    {
                        textEdit->setEnabled(false);
                    }
                    else
                    {
                        textEdit->setEnabled(true);
                    }
                }
                else if(event->type() == QEvent::MouseMove)
                {
                    QMouseEvent* e = static_cast<QMouseEvent*>(event);

                    int pointX = listLabel[j]->x() + e->pos().x() -  lastPoint[i].x();
                    int pointY = listLabel[j]->y() + e->pos().y() -  lastPoint[i].y();

                    int endPointX = ui->widgetControl->rect().x() + ui->widgetControl->width();
                    int endPointY = ui->widgetControl->rect().y() + ui->widgetControl->height();

                    if(pointX < ui->widgetControl->rect().x() || pointY < ui->widgetControl->rect().y() || pointX > endPointX || pointY > endPointY)
                    {
                        return QWidget::eventFilter(watched, event);
                    }

                    listLabel[j]->move(pointX, pointY);
                }
            }
        }
    }

    listLabel.clear();
    return QWidget::eventFilter(watched, event);
}

/*********************     生成二维码          *************************/
const QImage TemplateSetUp::generateQrCode(QString number)
{
    if (number.isEmpty())        return QImage();
    if (qrCodeLabel.size() == 0) return QImage();

    qrcode = QRcode_encodeString(number.toStdString().data(), 2, QR_ECLEVEL_L, QR_MODE_8, 1);  //生成二维码

    qint32 width = qrCodeLabel.first()->width();                   //二维码图片的宽度
    qint32 height = qrCodeLabel.first()->height();                 //二维码图片的高度
    qint32 qrcodeWidth = qrcode->width > 0 ? qrcode->width : 1;   //判断二维码宽度是否大于0

    double scaleX = (double)width / (double)qrcodeWidth;           //二维码图片的缩放比例
    double scaleY = (double)height / (double)qrcodeWidth;          //二维码图片缩放比例

    QImage mainImg = QImage(width, height, QImage::Format_ARGB32); //将二维码写为图片形式

    QPainter painter(&mainImg);
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);

    painter.drawRect(0, 0, width, height);

    QColor foreGround(Qt::black);

    painter.setBrush(foreGround);

    for( qint32 y = 0; y < qrcodeWidth; y ++)
    {
        for( qint32 x = 0; x < qrcodeWidth; x ++)
        {
            if((y * qrcodeWidth + x) > qrcode->width * qrcode->width) continue;

            unsigned char data = qrcode->data[y * qrcodeWidth + x];
            if(data & 0x01)
            {
                QRectF rect(x * scaleX, y * scaleY, scaleX, scaleY);
                painter.drawRects(&rect, 1);
            }
        }
    }

    for(int i = 0; i < qrCodeLabel.size(); i ++)
    {
        qrCodeLabel[i]->setPixmap(QPixmap::fromImage(mainImg));
    }

    return mainImg;
}

/*********************     打印二维码          *************************/
void TemplateSetUp::printQrCode(QPixmap & pixmap)
{
    QPrinter printer;                               //构建新对象
    QPainter painter(&printer);                     //在打印机中绘制图像
    QRect rect = painter.viewport();                //获取Qpainter对象的矩形区域
    QSize size = pixmap.size();                     //获取图片的大小
    size.scale(rect.size(), Qt::KeepAspectRatio);   //按照图形比例大小重新设置视口矩形区域

    //打印图片
    painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
    painter.setWindow(pixmap.rect());
    painter.drawPixmap(0, 0, pixmap);
}

/*********************     打印图像            ************************/
void TemplateSetUp::printImage(QString number)
{
    if(QPrinterInfo::availablePrinters().size() == 0) return;

    this->setInfo();

    this->generateQrCode(number);

    ui->widgetControl->clearBox();

    QPixmap printPixMap = QWidget::grab(QRect(STARTPOINT.x(), STARTPOINT.y(), ui->widgetControl->width() , ui->widgetControl->height()));

    this->printQrCode(printPixMap);
}

/*********************     删除控件            ************************/
void TemplateSetUp::on_actionDelete_triggered()
{
    if(selectLabelIndex == INVALIDVALUE) return;

    QLabel * label = NULL;

    switch(typeFlage)
    {
    case TEXTTYPE:    if(selectLabelIndex >= textLabel.size())    return; label = textLabel[selectLabelIndex];     textLabel.removeAt(selectLabelIndex);   break;
    case BINGLITYPE:  if(selectLabelIndex >= bingLiLabel.size())  return; label = bingLiLabel[selectLabelIndex];   bingLiLabel.removeAt(selectLabelIndex); break;
    case QRCODETYPE:  if(selectLabelIndex >= qrCodeLabel.size())  return; label = qrCodeLabel[selectLabelIndex];   qrCodeLabel.removeAt(selectLabelIndex); break;
    case LABELFOUR:   if(selectLabelIndex >= fourLabel.size())    return; label = fourLabel[selectLabelIndex];     fourLabel.removeAt(selectLabelIndex);   break;
    case LABELFIVE:   if(selectLabelIndex >= fiveLabel.size())    return; label = fiveLabel[selectLabelIndex];     fiveLabel.removeAt(selectLabelIndex);   break;
    case LABELSIX:    if(selectLabelIndex >= sixLabel.size())     return; label = sixLabel[selectLabelIndex];      sixLabel.removeAt(selectLabelIndex);    break;
    case LABELSEVEN:  if(selectLabelIndex >= sevenLabel.size())   return; label = sevenLabel[selectLabelIndex];    sevenLabel.removeAt(selectLabelIndex);  break;
    case LABELEIGHT:  if(selectLabelIndex >= eightLabel.size())   return; label = eightLabel[selectLabelIndex];    eightLabel.removeAt(selectLabelIndex);  break;
    case LABELNINE:   if(selectLabelIndex >= nineLabel.size())    return; label = nineLabel[selectLabelIndex];     nineLabel.removeAt(selectLabelIndex);   break;
    case LABELTEN:    if(selectLabelIndex >= tenLabel.size())     return; label = tenLabel[selectLabelIndex];      tenLabel.removeAt(selectLabelIndex);    break;
    case LABELELEVEN: if(selectLabelIndex >= elevenLabel.size())  return; label = elevenLabel[selectLabelIndex];   elevenLabel.removeAt(selectLabelIndex); break;
    case LABELTWELVE: if(selectLabelIndex >= twelveLabel.size())  return; label = twelveLabel[selectLabelIndex];   twelveLabel.removeAt(selectLabelIndex); break;
    }

    if(NULL == label) return;

    for(int i = 0; i < dataList[templateName].size(); i ++)
    {
        if(dataList[templateName].at(i).labelType.toInt() == typeFlage
                && dataList[templateName].at(i).label->geometry().x() == label->geometry().x()
                && dataList[templateName].at(i).label->geometry().y() == label->geometry().y())
        {
            dataList[templateName].removeAt(i);

            break;
        }
    }

    label->setText("");

    ui->widgetControl->selectWidget->removeWidget(label);

    selectLabelIndex = INVALIDVALUE;

    SAFEDELETE(label);
}

/**********************    字体改变            ************************/
void TemplateSetUp::currentFontChange()
{
    if(selectLabelIndex == INVALIDVALUE) return;

    QList<QLabel*> listLabel;

    switch(typeFlage)
    {
    case TEXTTYPE:    listLabel = textLabel;   break;
    case BINGLITYPE:  listLabel = bingLiLabel; break;
    case QRCODETYPE:  listLabel = qrCodeLabel; break;
    case LABELFOUR:   listLabel = fourLabel;   break;
    case LABELFIVE:   listLabel = fiveLabel;   break;
    case LABELSIX:    listLabel = sixLabel;    break;
    case LABELSEVEN:  listLabel = sevenLabel;  break;
    case LABELEIGHT:  listLabel = eightLabel;  break;
    case LABELNINE:   listLabel = nineLabel;   break;
    case LABELTEN:    listLabel = tenLabel;    break;
    case LABELELEVEN: listLabel = elevenLabel; break;
    case LABELTWELVE: listLabel = twelveLabel; break;
    }

    //获取当前字体
    QFont currentFont = fontBox->currentFont();

    //设置字体大小
    currentFont.setPointSize(fontSizeBox->currentText().toInt());

    //设置字体
    listLabel.at(selectLabelIndex)->setFont(currentFont);

    for(int i = 0; i < dataList[templateName].size(); i ++)
    {
        if(dataList[templateName].at(i).labelType.toInt() == typeFlage
                && dataList[templateName].at(i).label->geometry().x() == listLabel.at(selectLabelIndex)->geometry().x()
                && dataList[templateName].at(i).label->geometry().y() == listLabel.at(selectLabelIndex)->geometry().y())
        {
            dataList[templateName][i].labelType   = QString::number(typeFlage);
            dataList[templateName][i].labelText   = listLabel.at(selectLabelIndex)->text();
            dataList[templateName][i].fontType    = currentFont.family();
            dataList[templateName][i].fontSize    = QString::number(currentFont.pointSize());
            dataList[templateName][i].labelWidth  = QString::number(listLabel.at(selectLabelIndex)->width());
            dataList[templateName][i].labelHeight = QString::number(listLabel.at(selectLabelIndex)->height());
            dataList[templateName][i].gemoryX     = QString::number(listLabel.at(selectLabelIndex)->geometry().x());
            dataList[templateName][i].gemoryY     = QString::number(listLabel.at(selectLabelIndex)->geometry().y());

            break;
        }
    }

    listLabel.clear();
}

/**********************    文本改变            *************************/
void TemplateSetUp::textChange()
{
    if(selectLabelIndex == INVALIDVALUE) return;

    QList<QLabel*> listLabel;

    switch(typeFlage)
    {
    case TEXTTYPE:    listLabel = textLabel;   break;
    case BINGLITYPE:  listLabel = bingLiLabel; break;
    case QRCODETYPE:  listLabel = qrCodeLabel; break;
    case LABELFOUR:   listLabel = fourLabel;   break;
    case LABELFIVE:   listLabel = fiveLabel;   break;
    case LABELSIX:    listLabel = sixLabel;    break;
    case LABELSEVEN:  listLabel = sevenLabel;  break;
    case LABELEIGHT:  listLabel = eightLabel;  break;
    case LABELNINE:   listLabel = nineLabel;   break;
    case LABELTEN:    listLabel = tenLabel;    break;
    case LABELELEVEN: listLabel = elevenLabel; break;
    case LABELTWELVE: listLabel = twelveLabel; break;
    }

    //设置内容
    listLabel.at(selectLabelIndex)->setText(textEdit->text());
}

/**********************    改变大小            *************************/
void TemplateSetUp::sizeChange()
{
    if(selectLabelIndex == INVALIDVALUE) return;

    QList<QLabel*> listLabel;

    switch(typeFlage)
    {
    case TEXTTYPE:    listLabel = textLabel;   break;
    case BINGLITYPE:  listLabel = bingLiLabel; break;
    case QRCODETYPE:  listLabel = qrCodeLabel; break;
    case LABELFOUR:   listLabel = fourLabel;   break;
    case LABELFIVE:   listLabel = fiveLabel;   break;
    case LABELSIX:    listLabel = sixLabel;    break;
    case LABELSEVEN:  listLabel = sevenLabel;  break;
    case LABELEIGHT:  listLabel = eightLabel;  break;
    case LABELNINE:   listLabel = nineLabel;   break;
    case LABELTEN:    listLabel = tenLabel;    break;
    case LABELELEVEN: listLabel = elevenLabel; break;
    case LABELTWELVE: listLabel = twelveLabel; break;
    }

    //设置大小
    int x = listLabel.at(selectLabelIndex)->geometry().x();
    int y = listLabel.at(selectLabelIndex)->geometry().y();

    listLabel.at(selectLabelIndex)->setGeometry(x, y, widthEdit->text().toInt(), heightEdit->text().toInt());
}

/**********************    组合json数据        *************************/
void TemplateSetUp::writeJson()
{
    if(templateName.isEmpty()) return;

    QJsonObject jsonTotal;
    QJsonArray  jsonArray;

    for(int i = 0; i < dataList.value(templateName).size(); i ++)
    {
        QJsonObject jsonData;
        QMap<QString, QString> mapData;

        const QList<LabelData> &dataLabel = dataList.value(templateName);

        mapData[labelType]   = dataLabel.at(i).labelType;
        mapData[labelText]   = dataLabel.at(i).labelText;
        mapData[fontType]    = dataLabel.at(i).fontType;
        mapData[fontSize]    = dataLabel.at(i).fontSize;
        mapData[labelWidth]  = QString::number(dataLabel.at(i).label->width());
        mapData[labelHeight] = QString::number(dataLabel.at(i).label->height());
        mapData[gemoryX]     = QString::number(dataLabel.at(i).label->geometry().x());
        mapData[gemoryY]     = QString::number(dataLabel.at(i).label->geometry().y());

        for(auto iter = mapData.begin(); iter != mapData.end(); ++ iter)
        {
            jsonData.insert(iter.key(), iter.value());
        }

        jsonArray.append(jsonData);
    }

    jsonTotal.insert("data",  jsonArray);

    QJsonDocument document;
    document.setObject(jsonTotal);

    QString arrayData = document.toJson();

    if(!templateData.insertData(templateName, arrayData, widgetType))
    {
        templateData.updateData(templateName, arrayData, widgetType);
    }
}

/**********************    读取Json数据        *************************/
bool TemplateSetUp::readJson(QString arrayData, QString name)
{
    QJsonParseError err;
    QJsonDocument jsonDom = QJsonDocument::fromJson(arrayData.toUtf8(), &err);

    if(err.error == QJsonParseError::NoError)
    {
        QJsonObject jsonObject = jsonDom.object();
        QJsonValue jsonValue = jsonObject.value(QString("data"));

        QJsonArray jsonArray = jsonValue.toArray();

        for(int i = 0; i < jsonArray.size(); i ++)
        {
            QJsonObject jsonData = jsonArray.at(i).toObject();

            QStringList stringList = jsonData.keys();

            QMap<QString, QString> mapData;

            for(int i = 0; i < stringList.size(); i ++)
            {
                mapData[stringList[i]] = jsonData[stringList[i]].toString();
            }

            LabelData data;

            data.labelType   = mapData[labelType];
            data.labelText   = mapData[labelText];
            data.fontType    = mapData[fontType];
            data.fontSize    = mapData[fontSize];
            data.labelWidth  = mapData[labelWidth];
            data.labelHeight = mapData[labelHeight];
            data.gemoryX     = mapData[gemoryX];
            data.gemoryY     = mapData[gemoryY];

            dataList[name].append(data);
        }

        return true;
    }

    return false;
}

/**********************    点击列表控件         *************************/
void TemplateSetUp::on_listWidgetTemplate_clicked(const QModelIndex &index)
{
    templateName = index.data().toString();

    if(!deleteFlage) deleteAll();   //先删除
    writeAll();                     //再写入
    generateQrCode(qrCodeNumber);   //二维码
}

/**********************    保存模板            *************************/
void TemplateSetUp::on_pushButtonSave_clicked()
{
    writeJson();

    QList<QString>templateList = INICONFIG->getTemplateList();

    templateList[widgetType] = templateName;
    INICONFIG->setTemplateList(templateList);

    INICONFIG->writeTemplateIni();

    ui->labelInfo->setText("当前模板为 <" + templateName + ">");
}

/**********************    设置特染切片信息      *************************/
void TemplateSetUp::setDataSpecialSlice(const DataSpecialSlice &value)
{
    dataSpecialSlice = value;
}

/**********************    设置免疫切片信息      *************************/
void TemplateSetUp::setDataImmuneSlice(const DataImmuneSlice &value)
{
    dataImmuneSlice = value;
}

/**********************    设置常规切片信息      *************************/
void TemplateSetUp::setDataNormalSlice(const DataNormalSlice &value)
{
    dataNormalSlice = value;
}

/**********************    设置病理号信息        *************************/
void TemplateSetUp::setQrCodeNumber(const QString &value)
{
    qrCodeNumber = value;
}
