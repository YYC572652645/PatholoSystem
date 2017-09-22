#ifndef NEWMORENORMALSLICE_H
#define NEWMORENORMALSLICE_H

#include <QMainWindow>
#include "normalslicedata.h"

namespace Ui {
class newmorenormalslice;
}

class NewMoreNormalSlice : public QMainWindow
{
    Q_OBJECT

signals:
    void sendSelect();

public:
    explicit NewMoreNormalSlice(QWidget *parent = 0);
    ~NewMoreNormalSlice();
    void showWidget();

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::newmorenormalslice *ui;

    QString subFinger(QString number);
};

#endif // NEWMORENORMALSLICE_H
