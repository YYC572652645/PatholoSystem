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

private:
    Ui::patientinfo *ui;
    void initControl();   //初始化控件
private:
    QLabel *labelInfo;
    QCheckBox *autoSaveBox;
};

#endif // PATIENTINFO_H
