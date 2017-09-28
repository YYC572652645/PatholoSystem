#ifndef TYPESET_H
#define TYPESET_H

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"

namespace Ui {
class typeset;
}

class TypeSet : public QWidget
{
    Q_OBJECT

public:
    explicit TypeSet(QWidget *parent = 0);
    ~TypeSet();

    void showDialog();

private slots:
    void receiveData(QString typeAbbreviation, QString typeName, int type);

    void on_pushButtonNew_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonExit_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::typeset *ui;

    void initControl();            //初始化控件

    void initValue();              //初始化值

private:
    int nowRow;                   //当前选中行
    TypeSetDialog *typeSetDialog; //新建输入框
};

#endif // TYPESET_H
