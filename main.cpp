#include "mainwindow.h"
#include <QApplication>
#include "logindialog/logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog login;

    a.setFont(QFont("ZYSong", 10));
    login.setFont(QFont("ZYSong", 10));

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
