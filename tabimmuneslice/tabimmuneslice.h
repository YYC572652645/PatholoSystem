#ifndef TABIMMUNESLICE_H
#define TABIMMUNESLICE_H

#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class tabimmuneslice;
}


class TabImmuneSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabImmuneSlice(QWidget *parent = 0);
    ~TabImmuneSlice();


private:
    Ui::tabimmuneslice *ui;

    void initControl();  //初始化控件

    void initData();    //初始化数据
};

#endif // TABNORMALSLICE_H
