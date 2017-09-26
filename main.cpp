#include "mainwindow.h"
#include <QApplication>
#include "logindialog/logindialog.h"
#include "messagebox/messagedialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    LOADQSS(":/qss/qss/style.qss");

    LoginDialog login;

    a.setFont(QFont("ZYSong", 10));

    if(login.exec() == QDialog::Accepted)
    {
        w.setAuthority(login.getAuthority());
        w.setAdminster(login.getAdminster());
        w.showMainWindow();
        return a.exec();
    }

    return 0;
}
