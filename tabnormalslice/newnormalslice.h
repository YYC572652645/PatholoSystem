#ifndef NEWNORMALSLICE_H
#define NEWNORMALSLICE_H

#include <QMainWindow>
#include "normalslicedata.h"

namespace Ui {
class newnormalslice;
}

class NewNormalSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewNormalSlice(QWidget *parent = 0);
    ~NewNormalSlice();

    void showWidget();
    void showWidget(DataNormalSlice data);
signals:
    void sendSelect();

private slots:
    void on_pushButtonOk_clicked();     //确定按钮
    void on_pushButtonCancel_clicked(); //取消按钮

private:
    Ui::newnormalslice *ui;
};

#endif // NEWNORMALSLICE_H
