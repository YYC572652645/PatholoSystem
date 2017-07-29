#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "logindata.h"

#pragma execution_character_set("utf-8")

namespace Ui {
class logindialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::logindialog *ui;

    LoginData loginData;
};

#endif // LOGINDIALOG_H
