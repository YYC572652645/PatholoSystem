#ifndef NEWMORESPECIALSLICE_H
#define NEWMORESPECIALSLICE_H

#include <QMainWindow>
#include <QKeyEvent>
#include "specialslicedata.h"

namespace Ui {
class newmorespecialslice;
}

class NewMoreSpecialSlice : public QMainWindow
{
    Q_OBJECT

signals:
    void sendSelect();

public:
    explicit NewMoreSpecialSlice(QWidget *parent = 0);
    ~NewMoreSpecialSlice();
    void showWidget();

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::newmorespecialslice *ui;
void keyPressEvent(QKeyEvent * event);
    QString subFinger(QString number);

    void setComboBoxInfo();
};

#endif // NEWMORENORMALSLICE_H
