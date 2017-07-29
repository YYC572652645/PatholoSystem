#-------------------------------------------------
#
# Project created by QtCreator 2017-07-29T10:15:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PatholoSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog/logindialog.cpp

HEADERS  += mainwindow.h \
    globaldef.hpp \
    logindialog/logindialog.h

FORMS    += mainwindow.ui \
    logindialog/logindialog.ui

RESOURCES += \
    res.qrc
