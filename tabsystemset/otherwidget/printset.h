#ifndef PRINTSET_H
#define PRINTSET_H

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"
#include <QPrinter>

namespace Ui {
class printset;
}

class PrintSet : public QWidget
{
    Q_OBJECT

public:
    explicit PrintSet(QWidget *parent = 0);
    ~PrintSet();

    void showDialog();

private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::printset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值
    void dataSelect();             //查询数据

private:
    int nowRow;                    //当前选中行
    QPrinter printer;              //打印对象
};

#endif // TYPESET_H
