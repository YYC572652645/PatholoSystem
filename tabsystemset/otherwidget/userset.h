#ifndef USERSET_H
#define USERSET_H

#include <QWidget>
#include "tabsystemset/tabsystemdata.h"
#include "tabsystemset/otherwidget/typesetdialog.h"
#include "userwidget.h"

namespace Ui {
class userset;
}

class UserSet : public QWidget
{
    Q_OBJECT

public:
    explicit UserSet(QWidget *parent = 0);
    ~UserSet();

    void showDialog();

private slots:
    void receiveData(UserData data);
    void on_pushButtonNew_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonUpdate_clicked();
    void on_pushButtonExit_clicked();

private:
    Ui::userset *ui;

    void initControl();            //初始化控件
    void initValue();              //初始化值
    void dataSelect();             //数据查询

private:
    UserWidget userWidget;
};

#endif // TYPESET_H
