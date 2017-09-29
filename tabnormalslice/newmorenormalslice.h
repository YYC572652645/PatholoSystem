#ifndef NEWMORENORMALSLICE_H
#define NEWMORENORMALSLICE_H

/***************************************************************
   功能:批量切片

   创建人:殷宇辰

   创建时间:2017-9-22
**************************************************************/

#include <QMainWindow>
#include <QKeyEvent>
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

    void keyPressEvent(QKeyEvent * event);
};

#endif // NEWMORENORMALSLICE_H
