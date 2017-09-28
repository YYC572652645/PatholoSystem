#ifndef SPECIALINDEXSETSET_H
#define SPECIALINDEXSETSET_H

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"
#include "printtemplate/templatesetup.h"

namespace Ui {
class specialindexset;
}

class SpeciaIndexSet : public QWidget
{
    Q_OBJECT

public:
    explicit SpeciaIndexSet(QWidget *parent = 0);
    ~SpeciaIndexSet();

    void showDialog();

private slots:
    void receiveData(QString typeName, int type);
    void on_pushButtonNew_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonExit_clicked();
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_pushButtonPrint_clicked();
    void on_pushButtonPrintAll_clicked();
    void on_pushButtonTemplateSet_clicked();

private:
    Ui::specialindexset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值

private:
    int nowRow;                    //当前选中行
    TypeSetDialog *typeSetDialog;  //新建输入框
    TemplateSetUp *templateSetUp;  //打印模板
};

#endif // TYPESET_H
