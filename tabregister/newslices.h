#ifndef NEWSLICES_H
#define NEWSLICES_H

#include <QDialog>
#include "registerdata.h"
namespace Ui {
class newslices;
}

class newslices : public QDialog
{
    Q_OBJECT

public:
    explicit newslices(QWidget *parent = 0);
    ~newslices();

private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::newslices *ui;

    RegisterData registerData;
};

#endif // NEWSLICES_H
