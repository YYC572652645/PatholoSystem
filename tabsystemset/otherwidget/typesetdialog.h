#ifndef TYPESETDIALOG_H
#define TYPESETDIALOG_H

#include <QMainWindow>

namespace Ui {
class typesetdialog;
}

class TypeSetDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit TypeSetDialog(QWidget *parent = 0);
    ~TypeSetDialog();

    void showUpdateDialog(QString typeAbbreviation, QString typeName);
    void showNewDialog();
    void setInfo();

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

signals:
    void sendString(QString, QString, int);
    void sendString(QString, int);

private:
    Ui::typesetdialog *ui;

    int dataType;
};

#endif // TYPESETDIALOG_H
