#ifndef TYPESETDIALOG_H
#define TYPESETDIALOG_H

/***************************************************************
   功能:新建更新对话框

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#include <QMainWindow>

namespace Ui {
class typesetdialog;
}

class TypeSetDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit TypeSetDialog(QWidget *parent = 0);                        //构造函数
    ~TypeSetDialog();                                                   //析构函数

    void showUpdateDialog(QString typeAbbreviation, QString typeName);  //显示更新窗口
    void showNewDialog();                                               //显示窗口
    void setInfo();                                                     //设置信息

private slots:
    void on_pushButtonOk_clicked();          //确定按钮
    void on_pushButtonCancel_clicked();      //取消按钮

signals:
    void sendString(QString, QString, int);  //发送信号
    void sendString(QString, int);           //发送信号

private:
    Ui::typesetdialog *ui;
    int dataType;                            //数据类型
};

#endif // TYPESETDIALOG_H
