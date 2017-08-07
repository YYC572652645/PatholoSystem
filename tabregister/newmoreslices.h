#ifndef NEWMORESLICES_H
#define NEWMORESLICES_H

#include <QDialog>

namespace Ui {
class newmoreslices;
}

class NewMoreSlices : public QDialog
{
    Q_OBJECT

public:
    explicit NewMoreSlices(QWidget *parent = 0);
    ~NewMoreSlices();
private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::newmoreslices *ui;
};

#endif // NEWMORESLICES_H
