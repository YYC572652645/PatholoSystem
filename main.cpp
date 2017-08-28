#include "mainwindow.h"
#include <QApplication>
#include "logindialog/logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile qssFile(":/qss/qss/style.qss");              //读取qss文件
    qssFile.open(QFile::ReadOnly);                     //以只读方式打开文件

    if(qssFile.isOpen())
    {
        QString strQss=QLatin1String(qssFile.readAll());//将qss信息读取到字符串
        qApp->setStyleSheet(strQss);                    //软件设置样式表
        qssFile.close();                                //关闭文件
    }

    LoginDialog login;

    a.setFont(QFont("ZYSong", 10));

    if(login.exec() == QDialog::Accepted)
    {
        w.showMaximized();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
