#ifndef TABREGISTER_H
#define TABREGISTER_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QStyleOptionViewItem>
#include <QStyledItemDelegate>
#include "registerdata.h"
#include "newslices.h"
#include "paintinfo/patientinfo.h"
#include "newmoreslices.h"
#include "printtemplate/templatesetup.h"
#include "registerdata.h"
#include <QTimer>
#include <QMenu>
#include <QContextMenuEvent>
namespace Ui {
class tabregister;
}

class TabRegister : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabRegister(QWidget *parent = 0);
    ~TabRegister();

signals:
    void sendNumber(QString, QString);

private slots:
    void updateMovie();                                                 //更新gif
    void printBLNumber(int count, QString number);                      //打印数据
    void selectData(int type, int scrollFlage);                         //查询数据
    void on_actionNewNumber_triggered();                                //新建编号
    void on_actionNewMoreNumber_triggered();                            //批量编号
    void on_actionPrintTemplate_triggered();                            //打印模版
    void on_actionDeleteInfo_triggered();                               //删除数据
    void on_actionClearInfo_triggered();                                //清空数据
    void on_actionExtendExcel_triggered();                              //导出Excel
    void on_pushButtonRefresh_clicked();                                //刷新数据
    void on_pushButtonFind_clicked();                                   //查找数据
    void on_tableWidget_clicked(const QModelIndex &currentIndex);       //单击列表
    void on_tableWidget_doubleClicked(const QModelIndex &currentIndex); //双击列表
    void on_actionPrintLabel_triggered();                               //打印标签
    void on_actionPrintMoreLabel_triggered();                           //批量打印

private:
    Ui::tabregister *ui;

    void contextMenuEvent(QContextMenuEvent *event); //显示菜单
    void initControl();                              //初始化控件
    void initData();                                 //初始化数据
    void createActions();                            //创建菜单栏

private:
    RegisterData registerData;                       //登记数据库
    PatientInfo patientInfo;                         //患者信息
    NewSlices *newSlices;                            //新编号
    NewMoreSlices *newMoreSlices;                    //批量编号
    TemplateSetUp *templateSetUp;                    //打印模板
    QMovie  *movie;                                  //播放gif
    QTimer  *timer;                                  //设置定时器
    QString deleteID;                                //删除的ID
    QMenu   *menu;                                   //菜单
    QAction *print;                                  //打印
    QAction *del;                                    //删除
    QAction *refresh;                                //刷新
};


#endif // TABREGISTER_H
