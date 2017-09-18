#ifndef NEWMORESLICES_H
#define NEWMORESLICES_H

#include <QDialog>
#include "registerdata.h"

namespace Ui {
class newmoreslices;
}

class CodeTypeInfo;

class NewMoreSlices : public QDialog
{
    Q_OBJECT

public:
    explicit NewMoreSlices(QWidget *parent = 0);
    ~NewMoreSlices();

    void showDialog();

signals:
    void signalSelect(int, int);        //查询信号

private slots:
    void on_pushButtonOk_clicked();     //确定按钮
    void on_pushButtonCancel_clicked(); //取消按钮

private:
    Ui::newmoreslices *ui;

    RegisterData registerData;

    QList<CodeTypeInfo> dataInfo;
};

#endif // NEWMORESLICES_H
