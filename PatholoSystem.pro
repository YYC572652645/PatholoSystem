#-------------------------------------------------
#
# Project created by QtCreator 2017-07-29T10:15:35
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PatholoSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog/logindialog.cpp \
    config/qreadini.cpp \
    logindialog/logindata.cpp \
    messagebox/messagedialog.cpp \
    singleton/singleton.cpp

HEADERS  += mainwindow.h \
    logindialog/logindialog.h \
    config/qreadini.h \
    logindialog/logindata.h \
    databasedef.h \
    messagebox/messagedialog.h \
    singleton/singleton.h \
    globaldef.h

FORMS  += mainwindow.ui \
    logindialog/logindialog.ui \
    messagebox/messagedialog.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc
