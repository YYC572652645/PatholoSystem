#include "templatesetup.h"
#include "ui_templatesetup.h"
#include "QInputDialog"
#include "globaldef.h"
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QFontDialog>
#include <QFontDatabase>

/*****************      构造函数               ******************/
TemplateSetUp::TemplateSetUp(QWidget *parent) :
    QMainWindow(parent), selectIndex(INVALIDVALUE),typeFlage(INVALIDVALUE),
    selectLabelIndex(INVALIDVALUE),
    ui(new Ui::templatesetup)
{
    ui->setupUi(this);

    this->setWindowTitle("打印模板");

    this->initControl();     //初始化属性页
    this->initConnect();     //连接信号与槽
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

    ui->widgetControl->show();
}

/*****************      删除               ******************/
void TemplateSetUp::on_pushButtonSub_clicked()
{
    ui->listWidgetTemplate->removeItemWidget(ui->listWidgetTemplate->currentItem());
}

/*****************      初始化属性页控件    ******************/
void TemplateSetUp::initControl()
{
    ui->widgetControl->hide();

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
    fontBox = new QFontComboBox(this);
    fontBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontBox->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(0, 1, fontBox);

    QFontDatabase fontDb;
    fontSizeBox  = new QComboBox(this);
    fontSizeBox->setEditable(true);
    fontSizeBox->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(1, 1, fontSizeBox);

    foreach (int size, fontDb.standardSizes())
    {
        fontSizeBox->addItem(QString::number(size));
    }

    colorFrame = new QFrame(this);
    ui->tableWidget->setCellWidget(2, 1, colorFrame);

    widthEdit = new QLineEdit(this);
    widthEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(3, 1, widthEdit);

    heightEdit= new QLineEdit(this);
    heightEdit->setFrame(QFrame::NoFrame);
    ui->tableWidget->setCellWidget(4, 1, heightEdit);

    //添加名称
    QTableWidgetItem *fontItem = new QTableWidgetItem("字体:");
    fontItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0, 0, fontItem);

    QTableWidgetItem *fontSizeItem = new QTableWidgetItem("字号:");
    fontSizeItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1, 0, fontSizeItem);

    QTableWidgetItem *colorItem = new QTableWidgetItem("颜色:");
    colorItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2, 0, colorItem);

    QTableWidgetItem *widthItem = new QTableWidgetItem("宽度:");
    widthItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3, 0, widthItem);

    QTableWidgetItem *heightItem = new QTableWidgetItem("高度:");
    heightItem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4, 0, heightItem);
}

/*****************      连接信号与槽        ******************/
void TemplateSetUp::initConnect()
{

}

/*****************      点击列表框中控件     ******************/
void TemplateSetUp::on_listWidgetControl_clicked(const QModelIndex &index)
{
    if(ui->widgetControl->isHidden()) return;

    QLabel * label = new QLabel(this);   //声明一个Label

    label->setFont(STARTFONT);           //设置显示字体

    label->setScaledContents(true);      //设置自适应

    label->installEventFilter(this);     //注册监听事件

    switch(index.row())
    {
    case TEXTTYPE:    label->setText("文本");   textLabel.append(label);      textLabel.last()->setGeometry(80,100,100,100);   break;
    case BINGLITYPE:  label->setText("病理号");  bingLiLabel.append(label);   bingLiLabel.last()->setGeometry(80,200,100,100);  break;
    case BARCODETYPE: label->setText("条码");   barCodeLabel.append(label);   barCodeLabel.last()->setGeometry(180,100,100,100);break;
    case QRCODETYPE:  label->setText("二维码");  qrCodeLabel.append(label);   qrCodeLabel.last()->setGeometry(180,200,100,100); break;
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
