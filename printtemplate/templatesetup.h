#ifndef TEMPLATESETUP_H
#define TEMPLATESETUP_H

#include <QMainWindow>
#include <QLabel>
#include "QRcode/qrencode.h"
#include <QFontComboBox>
#include <QPushButton>
#include <QSpinBox>
#include "../tabnormalslice/normalslicedata.h"

namespace Ui {
class templatesetup;
}

typedef struct LabelData
{
    QLabel * label;        //控件
    QString labelType;     //控件类型
    QString labelText;     //控件文本
    QString fontType;      //字体类型
    QString fontSize;      //字体大小
    QString labelWidth;    //控件宽度
    QString labelHeight;   //控件高度
    QString gemoryX;       //控件位置X
    QString gemoryY;       //控件位置Y
}LabelData;

class TemplateSetUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemplateSetUp(int type, QWidget *parent = 0);
    ~TemplateSetUp();

    void showWidget();                                             //显示对话框
    void printImage(QString number);                               //打印图像
    const QImage generateQrCode(QString number);                   //生成二维码
    void printQrCode(QPixmap & pixmap);                            //打印二维码
    void setQrCodeNumber(const QString &value);                    //设置二维码
    void setDataNormalSlice(const DataNormalSlice &value);         //设置常规切片数据

signals:
    void sendType(int);

private slots:
    void on_pushButtonAdd_clicked();                               //添加模板
    void on_pushButtonSub_clicked();                               //删除模板
    void on_listWidgetControl_clicked(const QModelIndex &index);   //点击控件列表
    void on_actionDelete_triggered();                              //删除控件
    void on_listWidgetTemplate_clicked(const QModelIndex &index);  //点击模板列表
    void on_pushButtonSave_clicked();                              //保存按钮
    void currentFontChange();                                      //字体改变
    void textChange();                                             //内容改变
    void sizeChange();                                             //大小改变

private:
    Ui::templatesetup *ui;

    QLineEdit *textEdit;                                           //内容
    QFontComboBox *fontBox;                                        //字体下拉框
    QComboBox *fontSizeBox;                                        //字号下拉框
    QLineEdit *widthEdit;                                          //宽度
    QLineEdit *heightEdit;                                         //高度
    QRcode *qrcode;                                                //生成二维码对象
    QList<QLabel*>textLabel;                                       //文字
    QList<QLabel*>bingLiLabel;                                     //病理号
    QList<QLabel*>qrCodeLabel;                                     //二维码
    QList<QLabel*>fourLabel;                                       //后面匹配控件,切片中使用
    QList<QLabel*>fiveLabel;                                       //后面匹配控件,切片中使用
    QList<QLabel*>sixLabel;                                        //后面匹配控件,切片中使用
    QList<QLabel*>sevenLabel;                                      //后面匹配控件,切片中使用
    QList<QLabel*>eightLabel;                                      //后面匹配控件,切片中使用
    QList<QLabel*>nineLabel;                                       //后面匹配控件,切片中使用
    QList<QLabel*>tenLabel;                                        //后面匹配控件,切片中使用
    QList<QLabel*>elevenLabel;                                     //后面匹配控件,切片中使用
    QList<QLabel*>twelveLabel;                                     //后面匹配控件,切片中使用
    QString templateName;                                          //模板名称
    QString qrCodeNumber;                                          //二维码数字
    int selectLabelIndex;                                          //被选中的下标
    int selectIndex;                                               //被选中的下标
    int typeFlage;                                                 //被选中的类型
    int widgetType;                                                //当前界面
    QMap<QString, QList<LabelData>>dataList;                       //控件内容
    bool deleteFlage;                                              //删除标志位
    DataNormalSlice dataNormalSlice;                               //常规切片数据

private:
    void initControl();                                            //初始化控件
    void initConnect();                                            //连接信号与槽
    void initValue();                                              //初始化数据
    void deleteAll();                                              //删除所有控件
    void writeAll();                                               //写入控件
    bool eventFilter(QObject *watched, QEvent *event);             //事件过滤
    void writeJson();                                              //组合JSON
    bool readJson(QString arrayData, QString name);                //读取JSON
};

#endif // TEMPLATESETUP_H
