#ifndef TEMPLATESETUP_H
#define TEMPLATESETUP_H

#include <QMainWindow>
#include <QLabel>
#include "QRcode/qrencode.h"
#include <QFontComboBox>

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
    void on_pushButtonAdd_clicked();

    void on_pushButtonSub_clicked();

    void on_listWidgetControl_clicked(const QModelIndex &index);

    void on_pushButtonPrint_clicked();

    void on_actionDelete_triggered();

private:
    Ui::templatesetup *ui;

    QFontComboBox *fontBox;                            //字体下拉框
    QComboBox *fontSizeBox;                            //字号下拉框
    QFrame    *colorFrame;                             //颜色
    QLineEdit *widthEdit;                              //宽度
    QLineEdit *heightEdit;                             //高度
    QRcode *qrcode;                                    //生成二维码对象
    QList<QLabel*>textLabel;                           //文字
    QList<QLabel*>bingLiLabel;                         //病理号
    QList<QLabel*>barCodeLabel;                        //条形码
    QList<QLabel*>qrCodeLabel;                         //二维码
    int selectLabelIndex;                              //被选中的下标
    int selectIndex;                                   //被选中的下标
    int typeFlage;                                     //被选中的类型

 private:
    void initControl();                                 //初始化控件
    void initConnect();                                 //连接信号与槽
    bool eventFilter(QObject *watched, QEvent *event);  //事件过滤
    void generateBarCode(QString number);               //生成条形码
    const QImage generateQrCode(QString number);        //生成二维码
    void printBarCode(QString number);                  //打印条形码
    void printQrCode(QPixmap & pixmap);                 //打印二维码
};

#endif // TEMPLATESETUP_H
