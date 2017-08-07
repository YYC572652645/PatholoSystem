#ifndef TYPESET_H
#define TYPESET_H

#include <QWidget>

namespace Ui {
class typeset;
}

class TypeSet : public QWidget
{
    Q_OBJECT

public:
    explicit TypeSet(QWidget *parent = 0);
    ~TypeSet();

private:
    Ui::typeset *ui;

    void initControl();  //初始化控件
};

#endif // TYPESET_H
