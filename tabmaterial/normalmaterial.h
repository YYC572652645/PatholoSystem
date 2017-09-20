#ifndef NORMALMATERIAL_H
#define NORMALMATERIAL_H

#include <QMainWindow>

namespace Ui {
class normalmaterial;
}

class NormalMaterial : public QMainWindow
{
    Q_OBJECT

signals:
    void sendSelect();

public:
    explicit NormalMaterial(QWidget *parent = 0);
    ~NormalMaterial();

    void showWidget(QString number, QString id);
    void showWidget();

private slots:
    void on_pushButtonOk_clicked();      //确定按钮
    void on_pushButtonCancel_clicked();  //取消按钮

private:
    Ui::normalmaterial *ui;
    QString id;

    QString subFinger(QString number);  //去字母
};

#endif // NORMALMATERIAL_H
