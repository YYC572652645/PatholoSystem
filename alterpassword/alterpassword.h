#ifndef ALTERPASSWORD_H
#define ALTERPASSWORD_H

#include <QMainWindow>
#include "logindialog/logindata.h"

namespace Ui {
class alterpassword;
}

class AlterPassword : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlterPassword(QWidget *parent = 0);
    ~AlterPassword();

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::alterpassword *ui;
    LoginData loginData;
};

#endif // ALTERPASSWORD_H
