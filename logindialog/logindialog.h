#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "logindata.h"


namespace Ui {
class logindialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

    int getAuthority() const;

    int getAdminster() const;

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::logindialog *ui;

    LoginData loginData;
    int authority;
    int adminster;
};

#endif // LOGINDIALOG_H
