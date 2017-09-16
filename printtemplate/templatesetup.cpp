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
#include "templatedata/templatedata.h"
#include <QJsonArray>

/*********************     构造函数             **************************/
TemplateSetUp::TemplateSetUp(QWidget *parent) :
    QMainWindow(parent), selectIndex(INVALIDVALUE),typeFlage(INVALIDVALUE),
    selectLabelIndex(INVALIDVALUE),
    ui(new Ui::templatesetup)
{
    ui->setupUi(this);

    this->setWindowTitle("打印模板");

    this->initControl();     //初始化属性页
    this->initConnect();     //连接信号与槽

    int count = TEMPLATEDATA->selectData();

    for(int i = 0; i < count; i ++)
    {
        readJson(TEMPLATEDATA->getDataTemplate().at(i).templateText, TEMPLATEDATA->getDataTemplate().at(i).templateName);

        ui->listWidgetTemplate->addItem(TEMPLATEDATA->getDataTemplate().at(i).templateName);

        templateName = TEMPLATEDATA->getDataTemplate().at(i).templateName;

        //选中最后一行
        QListWidgetItem *item = ui->listWidgetTemplate->item(ui->listWidgetTemplate->count() - 1);
        item->setSelected(true);

        //滑动至最后一行
        ui->listWidgetTemplate->scrollToBottom();

        //设置当前行为最后一行
        ui->listWidgetTemplate->setCurrentRow(ui->listWidgetTemplate->count() - 1);
    }
}

/*********************     析构函数             **************************/
TemplateSetUp::~TemplateSetUp()
{
    textLabel.clear();
    bingLiLabel.clear();
    qrCodeLabel.clear();
    SAFEDELETE(fontBox);
    SAFEDELETE(fontSizeBox);
    SAFEDELETE(colorFrame);
    SAFEDELETE(widthEdit);
    SAFEDELETE(heightEdit);
    SAFEDELETE(qrcode);

    delete ui;
}

/*********************     添加模板             **************************/
void TemplateSetUp::on_pushButtonAdd_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "系统提示", "请输入模板名称", QLineEdit::Normal, QString::null, &ok);

    if(ok && !text.isEmpty())
    {
        ui->listWidgetTemplate->addItem(text);
    }
    else
    {
        return;
    }

    templateName = text;

    ui->widgetControl->show();

    //选中最后一行
    QListWidgetItem *item = ui->listWidgetTemplate->item(ui->listWidgetTemplate->count() - 1);
    item->setSelected(true);

    //滑动至最后一行
    ui->listWidgetTemplate->scrollToBottom();

    //设置当前行为最后一行
    ui->listWidgetTemplate->setCurrentRow(ui->listWidgetTemplate->count() - 1);
}

/*********************     删除模板             **************************/
void TemplateSetUp::on_pushButtonSub_clicked()
{
    //删除列表项
    QListWidgetItem *item = ui->listWidgetTemplate->takeItem(ui->listWidgetTemplate->currentRow());
    delete item;

    //删除数据库信息
    TEMPLATEDATA->deleteData(templateName);

    //移除控件中的内容
    deleteAll();
}

/*********************     初始化属性页控件      *************************/
void TemplateSetUp::initControl()
{
    //把表头上面去掉
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);

    //设置列表控件等宽显示
    QHeaderView *headerView=ui->tableWidget->horizontalHeader();
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

    //添加控件
    textEdit = new QLineEdit(this);
    textEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(0, 1, textEdit);
    textEdit->setStyleSheet("background-color:transparent");

    fontBox = new QFontComboBox(this);
    fontBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontBox->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(1, 1, fontBox);

    QFontDatabase fontDb;
    fontSizeBox  = new QComboBox(this);
    fontSizeBox->setEditable(true);
    fontSizeBox->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(2, 1, fontSizeBox);

    foreach (int size, fontDb.standardSizes())
    {
        fontSizeBox->addItem(QString::number(size));
    }

    colorFrame = new QPushButton(this);
    colorFrame->setStyleSheet("background-color:black");
    ui->tableWidget->setCellWidget(3, 1, colorFrame);


    widthEdit = new QLineEdit(this);
    widthEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(4, 1, widthEdit);
    widthEdit->setStyleSheet("background-color:transparent");
    widthEdit->setEnabled(false);

    heightEdit= new QLineEdit(this);
    heightEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(5, 1, heightEdit);
    heightEdit->setStyleSheet("background-color:transparent");
    heightEdit->setEnabled(false);

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

    //颜色
    QTableWidgetItem *colorItem = new QTableWidgetItem("颜色:");
    colorItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3, 0, colorItem);

    //宽度
    QTableWidgetItem *widthItem = new QTableWidgetItem("宽度:");
    widthItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4, 0, widthItem);

    //高度
    QTableWidgetItem *heightItem = new QTableWidgetItem("高度:");
    heightItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(5, 0, heightItem);

    //默认字体大小为16
    fontSizeBox->setCurrentIndex(8);
}

/*********************     连接信号与槽         *************************/
void TemplateSetUp::initConnect()
{
    connect(fontBox, SIGNAL(currentFontChanged(const QFont)), this, SLOT(currentFontChange()));
    connect(fontSizeBox, SIGNAL(currentTextChanged(QString)), this, SLOT(currentFontChange()));
    connect(colorFrame,  SIGNAL(clicked(bool)), this, SLOT(colorChange()));
    connect(textEdit,  SIGNAL(textChanged(QString)), this, SLOT(textChange()));
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
        }

        for(int j = 0; j < listLabel.size(); j ++)
        {
            listLabel.at(j)->setText("");

            ui->widgetControl->selectWidget->removeWidget(listLabel.at(j));

            delete listLabel.at(j);
        }
    }

    selectLabelIndex = INVALIDVALUE;
    ui->widgetControl->clearBox();
}

/*********************     写入控件            *************************/
void TemplateSetUp::writeAll()
{
    if(ui->widgetControl->isHidden()) return;
    if(templateName.isEmpty())  return;

    textLabel.clear();
    bingLiLabel.clear();
    qrCodeLabel.clear();

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

        QColor color;

        color.setRgb(dataLabel.at(i).fontColor.toUInt());

        //设置颜色
        QPalette pal = label->palette();
        pal.setColor(QPalette::WindowText, color);
        label->setPalette(pal);
        label->setAutoFillBackground(true);

        switch(dataLabel.at(i).labelType.toInt())
        {
        case TEXTTYPE:     textLabel.append(label);      break;
        case BINGLITYPE:   bingLiLabel.append(label);    break;
        case QRCODETYPE:   qrCodeLabel.append(label);    break;
        }

        label->setWordWrap(true); //设置换行

        label->show();            //显示出来

        dataList[templateName][i].label = label;

        ui->widgetControl->selectWidget->addWidget(label);  //添加控件
    }
}

/*********************     点击列表框中控件     *************************/
void TemplateSetUp::on_listWidgetControl_clicked(const QModelIndex &index)
{
    QLabel * label = new QLabel(this);   //声明一个Label

    label->setFont(STARTFONT);           //设置显示字体

    label->setScaledContents(true);      //设置自适应

    label->installEventFilter(this);     //注册监听事件

    switch(index.row())
    {
    case TEXTTYPE:    label->setText("文本");   textLabel.append(label);      textLabel.last()->setGeometry(80,100,100,100);   break;
    case BINGLITYPE:  label->setText("病理号");  bingLiLabel.append(label);   bingLiLabel.last()->setGeometry(80,200,100,100);  break;
    case QRCODETYPE:  label->setText("二维码");  qrCodeLabel.append(label);   qrCodeLabel.last()->setGeometry(180,200,100,100); break;
    }


    //将新建的控件数据添加到Map
    LabelData labelData;

    labelData.label       = label;
    labelData.labelType   = QString::number(index.row());
    labelData.labelText   = label->text();
    labelData.fontType    = "宋体";
    labelData.fontSize    = "16";
    labelData.fontColor   = "0";
    labelData.labelWidth  = QString::number(label->width());
    labelData.labelHeight = QString::number(label->height());
    labelData.gemoryX     = QString::number(label->geometry().x());
    labelData.gemoryY     = QString::number(label->geometry().y());

    dataList[templateName].append(labelData);

    label->setWordWrap(true);                           //设置换行

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

                    for(int i = 0; i < dataList[templateName].size(); i ++)
                    {
                        if(dataList[templateName].at(i).labelType.toInt() == i
                                && dataList[templateName].at(i).label->geometry().x() == listLabel[j]->geometry().x()
                                && dataList[templateName].at(i).label->geometry().y() == listLabel[j]->geometry().y())
                        {
                            fontBox->setCurrentText(dataList[templateName].at(i).fontType);
                            fontSizeBox->setCurrentText(dataList[templateName].at(i).fontSize);

                            QColor color;

                            color.setRgb(dataList[templateName].at(i).fontColor.toInt());

                            //设置颜色
                            QPalette pal = colorFrame->palette();
                            pal.setColor(QPalette::WindowText, color);
                            colorFrame->setPalette(pal);
                            colorFrame->setAutoFillBackground(true);

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
    qint32 qrcodeWidth =  qrcode->width > 0 ? qrcode->width : 1;   //判断二维码宽度是否大于0

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

    bingLiLabel.first()->setText("123456789");

    ui->widgetControl->clearBox();

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
void TemplateSetUp::on_pushButtonPrint_clicked()
{
    generateQrCode("123456789");

    QPixmap printPixMap = QWidget::grab(QRect(STARTPOINT.x(), STARTPOINT.y(), ui->widgetControl->width() - PAINTDATA , ui->widgetControl->height() - PAINTDATA));

    this->printQrCode(printPixMap);
}

/*********************     删除控件            ************************/
void TemplateSetUp::on_actionDelete_triggered()
{
    if(selectLabelIndex == INVALIDVALUE) return;

    QLabel * label;
    switch(typeFlage)
    {
    case TEXTTYPE:    if(selectLabelIndex >= textLabel.size())    return; label = textLabel[selectLabelIndex];     textLabel.removeAt(selectLabelIndex);    break;
    case BINGLITYPE:  if(selectLabelIndex >= bingLiLabel.size())  return; label = bingLiLabel[selectLabelIndex];   bingLiLabel.removeAt(selectLabelIndex);  break;
    case QRCODETYPE:  if(selectLabelIndex >= qrCodeLabel.size())  return; label = qrCodeLabel[selectLabelIndex];   qrCodeLabel.removeAt(selectLabelIndex);  break;
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
    }

    //获取当前字体
    QFont currentFont = fontBox->currentFont();

    //设置字体大小
    currentFont.setPointSize(fontSizeBox->currentText().toInt());

    //设置字体
    listLabel.at(selectLabelIndex)->setFont(currentFont);

    //设置颜色
    QPalette pal = listLabel.at(selectLabelIndex)->palette();
    pal.setColor(QPalette::WindowText, labelFontColor);
    listLabel.at(selectLabelIndex)->setPalette(pal);
    listLabel.at(selectLabelIndex)->setAutoFillBackground(true);

    for(int i = 0; i < dataList[templateName].size(); i ++)
    {
        if(dataList[templateName].at(i).labelType.toInt() == typeFlage
                && dataList[templateName].at(i).label->geometry().x() == listLabel.at(selectLabelIndex)->geometry().x()
                && dataList[templateName].at(i).label->geometry().y() == listLabel.at(selectLabelIndex)->geometry().y())
        {
            dataList[templateName][i].labelType   = QString::number(typeFlage);
            dataList[templateName][i].labelText   = listLabel.at(selectLabelIndex)->text();
            dataList[templateName][i].fontType    = currentFont.styleName();
            dataList[templateName][i].fontSize    = QString::number(currentFont.pointSize());
            dataList[templateName][i].fontColor   = QString::number(labelFontColor.rgb());
            dataList[templateName][i].labelWidth  = QString::number(listLabel.at(selectLabelIndex)->width());
            dataList[templateName][i].labelHeight = QString::number(listLabel.at(selectLabelIndex)->height());
            dataList[templateName][i].gemoryX     = QString::number(listLabel.at(selectLabelIndex)->geometry().x());
            dataList[templateName][i].gemoryY     = QString::number(listLabel.at(selectLabelIndex)->geometry().y());

            break;
        }
    }

    listLabel.clear();
}

/**********************    字体颜色改变         ************************/
void TemplateSetUp::colorChange()
{
    labelFontColor = QColorDialog::getColor(Qt::white, this);
    QPalette pal = colorFrame->palette();
    pal.setColor(QPalette::Button,labelFontColor);
    colorFrame->setPalette(pal);
    colorFrame->setAutoFillBackground(true);
    colorFrame->setFlat(true);

    currentFontChange();
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
    }

    //设置内容
    listLabel.at(selectLabelIndex)->setText(textEdit->text());
}

/**********************    组合json数据        *************************/
void TemplateSetUp::writeJson()
{
    if(templateName.isEmpty()) return;

    QJsonObject jsonTotal;
    QJsonArray  jsonArray;

    for(int i = 0; i < dataList[templateName].size(); i ++)
    {
        QJsonObject jsonData;
        QMap<QString, QString> mapData;

        const QList<LabelData> &dataLabel = dataList[templateName];

        mapData[labelType]   = dataLabel.at(i).labelType;
        mapData[labelText]   = dataLabel.at(i).labelText;
        mapData[fontType]    = dataLabel.at(i).fontType;
        mapData[fontSize]    = dataLabel.at(i).fontSize;
        mapData[fontColor]   = dataLabel.at(i).fontColor;
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

    if(!TEMPLATEDATA->insertData(templateName, arrayData))
    {
        TEMPLATEDATA->updateData(templateName, arrayData);
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
            data.fontColor   = mapData[fontColor];
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

    deleteAll();  //先删除
    writeAll();   //再写入
}

/**********************    保存模板            *************************/
void TemplateSetUp::on_pushButtonSave_clicked()
{
    writeJson();
}
