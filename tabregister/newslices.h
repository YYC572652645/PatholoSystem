#ifndef NEWSLICES_H
#define NEWSLICES_H

#include <QDialog>
#include "registerdata.h"
#include "tabsystemset/tabsystemdata.h"
namespace Ui {
class newslices;
}

class NewSlices : public QDialog
{
    Q_OBJECT

public:
    explicit NewSlices(QWidget *parent = 0);
    ~NewSlices();

    void showDialog();                  //显示对话框

private slots:
    void on_pushButtonOk_clicked();     //确定按钮
    void on_pushButtonCancel_clicked(); //取消按钮

private:
    Ui::newslices *ui;

    RegisterData registerData;

    QList<CodeTypeInfo> dataInfo;
};

#endif // NEWSLICES_H
