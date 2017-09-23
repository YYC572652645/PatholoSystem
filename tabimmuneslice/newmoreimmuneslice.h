#ifndef NEWMOREIMMUNESLICE_H
#define NEWMOREIMMUNESLICE_H

#include <QMainWindow>
#include "immuneslicedata.h"

namespace Ui {
class newmoreimmuneslice;
}

class NewMoreImmuneSlice : public QMainWindow
{
    Q_OBJECT

signals:
    void sendSelect();

public:
    explicit NewMoreImmuneSlice(QWidget *parent = 0);
    ~NewMoreImmuneSlice();
    void showWidget();

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::newmoreimmuneslice *ui;

    QString subFinger(QString number);

    void setComboBoxInfo();
};

#endif // NEWMORENORMALSLICE_H
