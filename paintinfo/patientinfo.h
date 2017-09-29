#ifndef PATIENTINFO_H
#define PATIENTINFO_H

/***************************************************************
   功能:病人信息界面

   创建人:殷宇辰

   创建时间:2017-9-21
**************************************************************/

#include <QMainWindow>
#include <QLabel>
#include <QCheckBox>

namespace Ui {
class patientinfo;
}

class PatientInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit PatientInfo(QWidget *parent = 0);    //构造函数
    ~PatientInfo();                               //析构函数

    void setRegId(const QString &value);          //设置登记ID
    void setPaintId(const QString &value);        //设置病人ID
    void setSelect();                             //设置查询
    void initConnect();                           //初始化信号与槽
    bool getIsAutoSaveFlage() const;              //获取是否自动保存

public slots:
    void flageChange();                           //内容改变
    void on_actionSavePatientInfo_triggered();    //保存患者信息
    void on_actionClearPatientInfo_triggered();   //清除患者信息

private:
    Ui::patientinfo *ui;
    void initControl();            //初始化控件
    void clearInfo();              //清除信息

    QLabel *labelInfo;             //设置信息
    QCheckBox *autoSaveBox;        //自动保存
    QString regId;                 //登记ID
    QString paintId;               //患者ID
    bool isAutoSaveFlage;          //自动保存标志位
};

#endif // PATIENTINFO_H
