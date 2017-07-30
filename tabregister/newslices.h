#ifndef NEWSLICES_H
#define NEWSLICES_H

#include <QDialog>
#include "registerdata.h"
namespace Ui {
class newslices;
}

class NewSlices : public QDialog
{
    Q_OBJECT

public:
    explicit NewSlices(QWidget *parent = 0);
    ~NewSlices();

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::newslices *ui;

    RegisterData registerData;
};

#endif // NEWSLICES_H
