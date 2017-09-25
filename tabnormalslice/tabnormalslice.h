#ifndef TABNORMALSLICE_H
#define TABNORMALSLICE_H

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
    explicit TabNormalSlice(QWidget *parent = 0);
    ~TabNormalSlice();

private slots:
    void receiveSelect();                         //接收查询信号
    void updateMovie();                           //更新Gif
    void on_actionNewSlice_triggered();           //新建切片
    void on_actionPrintLabel_triggered();
    void on_actionPrintMoreLabel_triggered();
    void on_actionDeleteInfo_triggered();
    void on_actionClearInfo_triggered();
    void on_pushButtonRefresh_clicked();
    void on_tableWidget_doubleClicked(const QModelIndex &index);
    void on_pushButtonFind_clicked();
    void on_actionNewMore_triggered();
    void on_actionPrintTemplate_triggered();
    void on_actionImportTxt_triggered();

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
