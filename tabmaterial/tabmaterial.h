#ifndef TABMATERIAL_H
#define TABMATERIAL_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "paintinfo/patientinfo.h"
#include "printtemplate/templatesetup.h"
#include "normalmaterial.h"
#include <QTreeWidgetItem>
#include <QContextMenuEvent>
#include <QTimer>
#include <QMovie>
#include <QMenu>
#include "exceloperate/exceloperate.h"

namespace Ui {
class tabmaterial;
}

class TabMaterial : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabMaterial(QWidget *parent = 0);
    ~TabMaterial();

private slots:
    void receiveSelect();                                               //查询
    void updateMovie();                                                 //更新Gif
    void receiveNumber(QString number, QString id);                     //接收病理号
    void on_actionNormalMaterial_triggered();                           //常规取材
    void on_actionAddBaoMai_triggered();                                //添加包埋
    void on_actionPrintLabel_triggered();                               //打印
    void on_actionPrintMoreLabel_triggered();                           //批量打印
    void on_actionAddBingLiNumber_triggered();                          //添加病理号
    void on_pushButtonRefresh_clicked();                                //刷新数据
    void on_treeWidget_doubleClicked(const QModelIndex &index);         //双击按钮
    void on_treeWidget_clicked(const QModelIndex &index);               //单击
    void on_pushButtonFind_clicked();                                   //查询
    void on_actionDeleteInfo_triggered();                               //删除数据
    void on_actionPrintTemplate_triggered();                            //打印模板
    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);  //内容改变
    void on_actionExtendExcel_triggered();                              //导出Excel

private:
    Ui::tabmaterial *ui;

    void initControl();                                  //初始化控件
    void initData();                                     //初始化数据
    void initConnect();                                  //初始化信号与槽
    void selectData(int type);                           //查询数据
    void createActions();                                //创建菜单
    QString getIndexNumber(int type, QString blNumber);  //获取id
    void contextMenuEvent(QContextMenuEvent *event);     //鼠标响应
    int subFinger(QString number);                       //去字母

    PatientInfo patientInfo;                             //患者信息
    NormalMaterial *normalMaterial;                      //常规取材
    int currentRow;                                      //当前行
    int currentColume;                                   //当前列
    bool updateFlage;                                    //更新标志位
    QTreeWidgetItem *currentItem;                        //当前Item
    QMovie  *movie;                                      //播放gif
    QTimer  *timer;                                      //设置定时器
    QMenu   *menu;                                       //菜单
    QAction *print;                                      //打印
    QAction *del;                                        //删除
    QAction *refresh;                                    //刷新
    TemplateSetUp *templateSetUp;                        //打印模板
    QString numberToLetter(int type, int number);        //数字转字母
    QString currentCode;                                 //当前病理号
    DataChild  getDataChild(QString blNumber);           //获取子节点数据
    DataParent getDataParent(QString blNumber);          //获取父节点数据
    DataChild dataUpdate;                                //需要更新的数据
    bool isEmpty(DataChild data);                        //判断结构体是否为空
    void dataChildClear();                               //清空结构体
};

#endif // TABREGISTER_H
