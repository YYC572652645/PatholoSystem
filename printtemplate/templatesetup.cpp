#include "templatesetup.h"
#include "ui_templatesetup.h"
#include "QInputDialog"
#include "globaldef.h"
#include <QDebug>

/*****************      构造函数               ******************/
TemplateSetUp::TemplateSetUp(QWidget *parent) :
    QMainWindow(parent), selectIndex(INVALIDVALUE),typeFlage(INVALIDVALUE),
    selectLabelIndex(INVALIDVALUE),
    ui(new Ui::templatesetup)
{
    ui->setupUi(this);

    this->initWidgetPaint();      //初始化绘图控件
    this->initWidgetProperty();   //初始化属性页
    this->initConnect();          //连接信号与槽
}

/*****************      析构函数               ******************/
TemplateSetUp::~TemplateSetUp()
{
    delete ui;
}

/*****************      添加               ******************/
void TemplateSetUp::on_pushButtonAdd_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "系统提示", "请输入模板名称", QLineEdit::Normal, QString::null, &ok);

    if(ok && !text.isEmpty())
    {
        ui->listWidgetTemplate->addItem(text);
    }

    ui->widgetPaint->show();
}

/*****************      删除               ******************/
void TemplateSetUp::on_pushButtonSub_clicked()
{
    ui->listWidgetTemplate->removeItemWidget(ui->listWidgetTemplate->currentItem());

    ui->widgetPaint->hide();    //初始将画图区域隐藏
}

/*****************      初始化绘图控件      ******************/
void TemplateSetUp::initWidgetPaint()
{
    ui->widgetPaint->axisRect()->setupFullAxesBox(true);  //显示为四周坐标框
    ui->widgetPaint->setBackground(Qt::white);            //设置背景色为白色
    ui->widgetPaint->xAxis->grid()->setVisible(false);    //去掉背景网格虚线
    ui->widgetPaint->yAxis->grid()->setVisible(false);    //去掉背景网格虚线

    //设置坐标隐藏
    ui->widgetPaint->yAxis->setTicks(false);
    ui->widgetPaint->xAxis->setTicks(false);
    ui->widgetPaint->yAxis2->setTicks(false);
    ui->widgetPaint->xAxis2->setTicks(false);

    //设置控件无边框
    ui->listWidgetControl->setFrameShape(QFrame::NoFrame);
    ui->labelTitle->setFrameShape(QFrame::NoFrame);
    ui->labelTemplateTitle->setFrameShape(QFrame::NoFrame);
    ui->labelTitle->setFrameShape(QFrame::NoFrame);
    ui->listWidgetTemplate->setFrameShape(QFrame::NoFrame);

    //设置隐藏
    ui->widgetPaint->hide();
}

/*****************      初始化属性页控件    ******************/
void TemplateSetUp::initWidgetProperty()
{
    varManager = new QtVariantPropertyManager(ui->widgetProperty);

    varFactory = new QtVariantEditorFactory(ui->widgetProperty);

    //设置分组最上层
    QtProperty *groupItem = varManager->addProperty(QtVariantPropertyManager::groupTypeId(),QStringLiteral("外观："));

    //设置内容
    QtVariantProperty *item = varManager->addProperty(QVariant::String, QStringLiteral("内容："));
    groupItem->addSubProperty(item);
    propertyData[item] = QStringLiteral("内容：");
    propertyList.append(item);

    //设置大小
    item = varManager->addProperty(QVariant::Size, QStringLiteral("大小："));
    groupItem->addSubProperty(item);
    propertyData[item] = QStringLiteral("大小：");
    item->setValue(STARTSIZE);
    for(int i = 0; i < item->subProperties().size(); i ++)
    {
        propertyData[item->subProperties().at(i)] = item->subProperties().at(i)->propertyName();
    }

    //设置字体
    item = varManager->addProperty(QVariant::Font, QStringLiteral("字体："));
    groupItem->addSubProperty(item);
    item->setValue(STARTFONT);
    for(int i = 0; i < item->subProperties().size(); i ++)
    {
        propertyData[item->subProperties().at(i)] = item->subProperties().at(i)->propertyName();
    }

    //添加至分组中
    ui->widgetProperty->addProperty(groupItem);

    ui->widgetProperty->setFactoryForManager(varManager, varFactory);
}

/*****************      连接信号与槽        ******************/
void TemplateSetUp::initConnect()
{
    connect(varManager, SIGNAL(valueChanged(QtProperty*,QVariant)), this, SLOT(propertyValueChanged(QtProperty*,QVariant)));
}

/*****************      点击列表框中控件     ******************/
void TemplateSetUp::on_listWidgetControl_clicked(const QModelIndex &index)
{
    if(ui->widgetPaint->isHidden()) return;

    QLabel * label = new QLabel(this);   //声明一个Label

    label->setFont(STARTFONT);           //设置显示字体

    label->setScaledContents(true);      //设置自适应

    label->installEventFilter(this);     //注册监听事件

    switch(index.row())
    {
    case TEXTTYPE:    label->setText("文本");   textLabel.append(label);     textLabel.last()->setGeometry(80,100,100,100);  break;
    case BINGLITYPE:  label->setText("病理号");  bingLiLabel.append(label);   bingLiLabel.last()->setGeometry(80,200,100,100);break;
    case BARCODETYPE: label->setText("条码");    barCodeLabel.append(label);  barCodeLabel.last()->setGeometry(180,100,100,100);break;
    case QRCODETYPE:  label->setText("二维码");  qrCodeLabel.append(label);   qrCodeLabel.last()->setGeometry(180,200,100,100);break;
    }

    label->setWordWrap(true); //设置换行

    label->show();            //显示出来

    ui->widgetControl->selectWidget->addWidget(label);  //添加控件
}

/*****************      事件过滤            ******************/
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
        case BARCODETYPE: listLabel = barCodeLabel;break;
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

                    if(i == TEXTTYPE)
                    {
                        selectIndex = j;                                                              //判断出当前被选中的下标
                        varManager->variantProperty(propertyList.first())->setEnabled(true);          //设置当前为可用状态
                    }
                    else
                    {
                        varManager->variantProperty(propertyList.first())->setEnabled(false);          //设置当前为不可用状态
                    }

                    varManager->variantProperty(propertyList.first())->setValue(listLabel[j]->text()); //将选中的文本字放到属性页

                    ui->widgetControl->selectWidget->addWidget(listLabel[j]);
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

    return QWidget::eventFilter(watched, event);
}

/*****************      属性页槽函数         ******************/
void TemplateSetUp::propertyValueChanged(QtProperty *property, const QVariant &value)
{
    if(selectIndex == INVALIDVALUE)     return;
    if(selectIndex >= textLabel.size()) return;
    if(typeFlage == INVALIDVALUE)       return;

    //设置字体
    {
        static QFont font = STARTFONT;
        if(FAMILY    == propertyData[property]) font.setFamily(value.toString());
        if(POINTSIZE == propertyData[property]) font.setPointSize(value.toInt());
        if(BOLD      == propertyData[property]) font.setBold(value.toBool());
        if(ITALIC    == propertyData[property]) font.setItalic(value.toBool());
        if(UNDERLINE == propertyData[property]) font.setUnderline(value.toBool());
        if(STRIKEOUT == propertyData[property]) font.setStrikeOut(value.toBool());
        if(KERNING   == propertyData[property]) font.setKerning(value.toBool());

        switch(typeFlage)
        {
        case TEXTTYPE:    textLabel[selectIndex]->setFont(font);     break;
        case BINGLITYPE:  bingLiLabel[selectIndex]->setFont(font);   break;
        case BARCODETYPE: barCodeLabel[selectIndex]->setFont(font);  break;
        case QRCODETYPE:  qrCodeLabel[selectIndex]->setFont(font);   break;
        }
    }

    //设置大小
    {
        static QSize size = STARTSIZE;
        if(WIDTH  == propertyData[property]) size.setWidth(value.toInt());
        if(HEIGHT == propertyData[property]) size.setHeight(value.toInt());

        switch(typeFlage)
        {
        case TEXTTYPE:    textLabel[selectIndex]->setMinimumSize(size);     break;
        case BINGLITYPE:  bingLiLabel[selectIndex]->setMinimumSize(size);   break;
        case BARCODETYPE: barCodeLabel[selectIndex]->setMinimumSize(size);  break;
        case QRCODETYPE:  qrCodeLabel[selectIndex]->setMinimumSize(size);   break;
        }

    }

    if(typeFlage == TEXTTYPE && property == propertyList.first())
    {
        textLabel[selectIndex]->setText(value.toString());
    }
}

/*****************      生成条形码           ******************/
void TemplateSetUp::generateBarCode(QString number)
{

}

/*****************      生成二维码           ******************/
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

/*****************      打印条形码           ******************/
void TemplateSetUp::printBarCode(QString number)
{

}

/*****************      打印二维码           ******************/
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

/*****************      打印图像             ******************/
void TemplateSetUp::on_pushButtonPrint_clicked()
{
    generateQrCode("123456789");

    QPixmap printPixMap = QWidget::grab(QRect(STARTPOINT.x(), STARTPOINT.y(), ui->widgetControl->width() - PAINTDATA , ui->widgetControl->height() - PAINTDATA));

    this->printQrCode(printPixMap);
}

/*****************      删除控件             ******************/
void TemplateSetUp::on_actionDelete_triggered()
{
    if(selectLabelIndex == INVALIDVALUE) return;

    QLabel * label;
    switch(typeFlage)
    {
    case TEXTTYPE:    if(selectLabelIndex >= textLabel.size())    return; label = textLabel[selectLabelIndex];     textLabel.removeAt(selectLabelIndex);    break;
    case BINGLITYPE:  if(selectLabelIndex >= bingLiLabel.size())  return; label = bingLiLabel[selectLabelIndex];   bingLiLabel.removeAt(selectLabelIndex);  break;
    case BARCODETYPE: if(selectLabelIndex >= barCodeLabel.size()) return; label = barCodeLabel[selectLabelIndex];  barCodeLabel.removeAt(selectLabelIndex); break;
    case QRCODETYPE:  if(selectLabelIndex >= qrCodeLabel.size())  return; label = qrCodeLabel[selectLabelIndex];   qrCodeLabel.removeAt(selectLabelIndex);  break;
    }

    label->setText("");

    ui->widgetControl->selectWidget->removeWidget(label);

    selectLabelIndex = INVALIDVALUE;
}
