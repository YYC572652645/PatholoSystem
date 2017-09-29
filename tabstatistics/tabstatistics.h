#ifndef TABSTATISTICS_H
#define TABSTATISTICS_H

/***************************************************************
   功能:统计数据

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QMenu>
#include <QContextMenuEvent>
#include <QAction>
#include "tabmaterial/materialdata.h"

namespace Ui {
class tabstatistics;
}

class TabsSatistics : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabsSatistics(QWidget *parent = 0);
    ~TabsSatistics();

private slots:
    void on_actionReferesh_triggered();              //刷新
    void on_actionExtend_triggered();                //导出
    void on_pushButtonSum_clicked();                 //统计

private:
    Ui::tabstatistics *ui;
    QMenu   *menu;                                   //菜单
    QAction *refresh;                                //刷新
    QAction *extend;                                 //导出

    void contextMenuEvent(QContextMenuEvent *event); //显示菜单
    void initControl();                              //初始化控件
    void initData();                                 //初始化数据
    void createActions();                            //创建菜单栏
    void dataSelect(int type);                       //查询数据
};

#endif // TABSTATISTICS_H
