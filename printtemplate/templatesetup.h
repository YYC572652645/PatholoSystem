#ifndef TEMPLATESETUP_H
#define TEMPLATESETUP_H

#include <QMainWindow>
#include <QLabel>
#include "QRcode/qrencode.h"
#include "qtvariantproperty.h"

namespace Ui {
class templatesetup;
}

class TemplateSetUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemplateSetUp(QWidget *parent = 0);
    ~TemplateSetUp();

signals:
    void sendType(int);

private slots:

    void propertyValueChanged(QtProperty*property, const QVariant &value);

    void on_pushButtonAdd_clicked();

    void on_pushButtonSub_clicked();

    void on_listWidgetControl_clicked(const QModelIndex &index);

    void on_pushButtonPrint_clicked();

    void on_actionDelete_triggered();

private:
    Ui::templatesetup *ui;

    QRcode *qrcode;                                    //生成二维码对象
    QList<QLabel*>textLabel;                           //文字
    QList<QLabel*>bingLiLabel;                         //病理号
    QList<QLabel*>barCodeLabel;                        //条形码
    QList<QLabel*>qrCodeLabel;                         //二维码
    QtVariantPropertyManager * varManager;             //声明属性页对象
    QtVariantEditorFactory * varFactory;               //属性页可编辑
    QMap<QtProperty*,QString>propertyData;             //属性页值
    QList<QtProperty*>propertyList;                    //属性项列表
    int selectLabelIndex;                              //被选中的下标
    int selectIndex;                                   //被选中的下标
    int typeFlage;                                     //被选中的类型

 private:
    void initWidgetPaint();                             //初始化绘图框
    void initWidgetProperty();                          //初始化属性框
    void initConnect();                                 //连接信号与槽
    bool eventFilter(QObject *watched, QEvent *event);  //事件过滤
    void generateBarCode(QString number);               //生成条形码
    const QImage generateQrCode(QString number);        //生成二维码
    void printBarCode(QString number);                  //打印条形码
    void printQrCode(QPixmap & pixmap);                 //打印二维码
};

#endif // TEMPLATESETUP_H
