#ifndef TABSTATISTICS_H
#define TABSTATISTICS_H

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
    void on_actionReferesh_triggered();
    void on_actionExtend_triggered();
    void on_pushButtonSum_clicked();

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
