#ifndef PATIENTINFO_H
#define PATIENTINFO_H

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
    explicit PatientInfo(QWidget *parent = 0);
    ~PatientInfo();

    void setRegId(const QString &value);
    void setPaintId(const QString &value);
    void setSelect();

private slots:
    void on_actionSavePatientInfo_triggered();    //保存患者信息
    void on_actionClearPatientInfo_triggered();   //清除患者信息

private:
    Ui::patientinfo *ui;
    void initControl();      //初始化控件
    void clearInfo();        //清除信息
private:
    QLabel *labelInfo;       //设置信息
    QCheckBox *autoSaveBox;  //自动保存
    QString regId;           //登记ID
    QString paintId;         //患者ID
};

#endif // PATIENTINFO_H
