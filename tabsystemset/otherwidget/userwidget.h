#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include "../tabsystemdata.h"

namespace Ui {
class userwidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = 0);
    ~UserWidget();

    void showWidget(UserData data);

signals:
    void sendData(UserData data);

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::userwidget *ui;
    void clearInfo();
};

#endif // USERWIDGET_H
