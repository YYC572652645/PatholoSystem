#ifndef TABSYSTEMSET_H
#define TABSYSTEMSET_H

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
    explicit TabSystemSet(QWidget *parent = 0);
    ~TabSystemSet();

private slots:
    void listWidgetClicked(const QModelIndex &index);

    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::tabsystemset *ui;

    void initControl();      //初始化控件

private:
    QListWidget *listWidget; //列表控件

private:
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
