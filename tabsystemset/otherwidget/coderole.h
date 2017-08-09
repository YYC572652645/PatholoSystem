#ifndef CODEROLE_H
#define CODEROLE_H

#include <QWidget>

namespace Ui {
class coderole;
}

class CodeRole : public QWidget
{
    Q_OBJECT

public:
    explicit CodeRole(QWidget *parent = 0);
    ~CodeRole();


private slots:
    void controlChanged();

private:
    Ui::coderole *ui;

    void initConnect();  //初始化信号和槽
};

#endif // CODEROLE_H
