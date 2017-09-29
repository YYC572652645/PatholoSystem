#ifndef TABSYSTEMSET_H
#define TABSYSTEMSET_H

/***************************************************************
   功能:系统设置

   创建人:殷宇辰

   创建时间:2017-7-25
**************************************************************/

#include <QMainWindow>
#include <QListWidget>
#include <QAction>
#include "otherwidget/typeset.h"
#include "otherwidget/coderole.h"
#include "tabsystemdata.h"
#include "otherwidget/printset.h"
#include "otherwidget/immuneindexset.h"
#include "otherwidget/immunetypeset.h"
#include "otherwidget/specialindexset.h"
#include "otherwidget/specialtypeset.h"
#include "otherwidget/userset.h"

namespace Ui {
class tabsystemset;
}

class TabSystemSet : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabSystemSet(QWidget *parent = 0);       //构造函数
    ~TabSystemSet();                                  //析构函数

private slots:
    void listWidgetClicked(const QModelIndex &index); //点击列表
    void on_pushButtonOk_clicked();                   //确定按钮
    void on_pushButtonCancel_clicked();               //取消按钮

private:
    Ui::tabsystemset *ui;
    void initControl();       //初始化控件

private:
    QListWidget *listWidget;  //列表控件

    //系统设置窗口
    TypeSet typeSet;
    CodeRole codeRole;
    PrintSet printSet;
    UserSet userSet;
    SpeciaIndexSet speciaIndexSet;
    SpeciaTypeSet speciaTypeSet;
    ImmuneIndexSet immuneIndexSet;
    ImmuneTypeSet immuneTypeSet;

    //显示窗口
    void showCentralwidget();
    void showTypeSet();
    void showCodeRule();
    void showPrintSet();
    void showUserSet();
    void showImmuneTypeSet();
    void showImmuneIndexSet();
    void showSpecialTypeSet();
    void showSpecialIndexSet();

};

#endif // TABSYSTEMSET_H
