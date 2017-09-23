#ifndef TABIMMUNESLICE_H
#define TABIMMUNESLICE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QTimer>
#include <QMovie>
#include <QCheckBox>
#include "immuneslicedata.h"
#include "newimmuneslice.h"
#include "newmoreimmuneslice.h"
#include "printtemplate/templatesetup.h"

namespace Ui {
class tabimmuneslice;
}

class TabImmuneSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabImmuneSlice(QWidget *parent = 0);
    ~TabImmuneSlice();

private slots:
    void receiveSelect();                               //接收查询
    void updateMovie();                                 //更新Gif
    void on_actionNewSlice_triggered();                 //新建切片
    void on_actionNewMore_triggered();                  //批量打印
    void on_actionPrintLabel_triggered();               //打印标签
    void on_actionDeleteInfo_triggered();               //删除信息
    void on_actionPrintTemplate_triggered();            //打印模板
    void on_pushButtonRefresh_clicked();                //刷新数据
    void on_tableWidget_doubleClicked(const QModelIndex &index);
    void on_pushButtonFind_clicked();                   //查找数据

private:
    Ui::tabimmuneslice *ui;
    void initControl();                                  //初始化控件
    void initData();                                     //初始化数据
    void createActions();                                //创建菜单
    void contextMenuEvent(QContextMenuEvent *event);     //鼠标响应
    void dataSelect(int type);                           //查询数据

    NewImmuneSlice *newImmuneSlice;                      //新建切片
    NewMoreImmuneSlice * newMoreSlice;                   //批量新增
    TemplateSetUp *templateSetUp;                        //模板
    QMenu   *menu;                                       //菜单
    QAction *print;                                      //打印
    QAction *del;                                        //删除
    QAction *refresh;                                    //刷新
    QMovie  *movie;                                      //播放gif
    QTimer  *timer;                                      //设置定时器
};

#endif // TABNORMALSLICE_H
