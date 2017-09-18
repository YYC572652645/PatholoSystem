#ifndef TABSPECIASLICE_H
#define TABSPECIASLICE_H

#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class tabspecialslice;
}


class TabSpeciaSlice : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabSpeciaSlice(QWidget *parent = 0);
    ~TabSpeciaSlice();


private:
    Ui::tabspecialslice *ui;

    void initControl();  //初始化控件

    void initData();    //初始化数据
};

#endif // TABNORMALSLICE_H
