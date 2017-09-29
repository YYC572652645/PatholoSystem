#ifndef TABNORMALSLICE_H
#define TABNORMALSLICE_H

/***************************************************************
   功能:常规切片

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QTimer>
#include <QMovie>
#include <QCheckBox>
#include "newnormalslice.h"
#include "newmorenormalslice.h"
#include "printtemplate/templatesetup.h"

namespace Ui {
class tabnormalslice;
}

class TabNormalSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabNormalSlice(QWidget *parent = 0);        //构造函数
    ~TabNormalSlice();                                   //析构函数

private slots:
    void receiveSelect();                                //接收查询信号
    void updateMovie();                                  //更新Gif
    void on_actionNewSlice_triggered();                  //新建切片
    void on_actionPrintLabel_triggered();                //打印标签
    void on_actionPrintMoreLabel_triggered();            //批量打印
    void on_actionDeleteInfo_triggered();                //删除信息
    void on_actionClearInfo_triggered();                 //清空信息
    void on_pushButtonRefresh_clicked();                 //刷新
    void on_tableWidget_doubleClicked(const QModelIndex &index);
    void on_pushButtonFind_clicked();                    //搜索数据
    void on_actionNewMore_triggered();                   //批量新建
    void on_actionPrintTemplate_triggered();             //打印模版
    void on_actionImportTxt_triggered();                 //导入Txt

private:
    Ui::tabnormalslice *ui;

    void initControl();                                  //初始化控件
    void initData();                                     //初始化数据
    void createActions();                                //创建菜单
    void contextMenuEvent(QContextMenuEvent *event);     //鼠标响应
    void dataSelect(int type);                           //查询数据

private:
    NewNormalSlice *newNormalSlice;                      //新建切片
    NewMoreNormalSlice * newMoreSlice;                   //批量新建
    TemplateSetUp *templateSetUp;                        //模板
    QMenu   *menu;                                       //菜单
    QAction *print;                                      //打印
    QAction *del;                                        //删除
    QAction *refresh;                                    //刷新
    QMovie  *movie;                                      //播放gif
    QTimer  *timer;                                      //设置定时器

};

#endif // TABNORMALSLICE_H
