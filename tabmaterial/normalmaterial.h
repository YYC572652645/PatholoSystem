#ifndef NORMALMATERIAL_H
#define NORMALMATERIAL_H

/***************************************************************
   功能:常规取材

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QKeyEvent>
#include "materialdata.h"

namespace Ui {
class normalmaterial;
}

class NormalMaterial : public QMainWindow
{
    Q_OBJECT

signals:
    void sendSelect();

public:
    explicit NormalMaterial(QWidget *parent = 0);
    ~NormalMaterial();

    QString subFinger(QString number);            //去字母
    void showWidget(QString number, QString id);  //显示窗口
    void showWidget();                            //显示窗口
    void setData(DataParent data);                //设置数据

private slots:
    void on_pushButtonOk_clicked();               //确定按钮
    void on_pushButtonCancel_clicked();           //取消按钮

private:
    Ui::normalmaterial *ui;
    void keyPressEvent(QKeyEvent *event);         //按键点击
    QString numberToLetter(int type, int number); //数字转字母
    QString id;
};

#endif // NORMALMATERIAL_H
