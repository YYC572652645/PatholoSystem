#ifndef CODEROLE_H
#define CODEROLE_H

#include <QWidget>
#include <QThread>
#include <QMutex>

namespace Ui {
class coderole;
}

enum NUMBERTYPEENUM
{
    NUMBER,
    SMALLLETTER,
    BIGLETTER,
};

class CodeRole : public QWidget
{
    Q_OBJECT

public:
    explicit CodeRole(QWidget *parent = 0);
    ~CodeRole();

private slots:
    void on_checkBoxType_clicked();                            //类别
    void on_checkBoxYear_clicked();                            //年份
    void on_radioButtonTwo_clicked();                          //两位年份
    void on_radioButtonFour_clicked();                         //四位年份
    void on_checkBoxMonth_clicked();                           //月份
    void on_checkBoxDay_clicked();                             //日
    void on_lineEditPrefix_textChanged(const QString &arg1);   //前缀
    void on_spinBoxLength_valueChanged(const QString &arg1);   //流水号长度
    void on_lineEditSpin_textChanged(const QString &arg1);     //间隔符
    void on_checkBoxBingLiNumber_clicked();                    //病理号
    void on_checkBoxHyphen_clicked();                          //连字符
    void on_comboBoxNumberType_activated(const QString &arg1); //流水号类型
    void on_pushButtonOk_clicked();                            //确定按钮
    void on_pushButtonCancel_clicked();                        //取消按钮

private:
    Ui::coderole *ui;
    void changeBingLiCodeRule();   //病理号编码规则
    void changQuCaiCodeRule();     //取材编码规则
    void initCodeRule();           //初始化编码规则
};

class InsertThread: public QThread
{
public:
    InsertThread();

    void run();

public:
    QString customPrefix;
    QString usePrefix;
    QString useYear;
    QString yearType;
    QString useMonth;
    QString useDay;
    QString spin;
    QString snLength;
    QString bLNumber;
    QString hyphen;
    QString numberType;
    QMutex mutex;
};

#endif // CODEROLE_H
