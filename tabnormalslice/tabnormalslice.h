#ifndef TABNORMALSLICE_H
#define TABNORMALSLICE_H

#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class tabnormalslice;
}


class TabNormalSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabNormalSlice(QWidget *parent = 0);
    ~TabNormalSlice();


private:
    Ui::tabnormalslice *ui;

    void initControl();  //初始化控件

    void initData();    //初始化数据
};

#endif // TABNORMALSLICE_H
