#-------------------------------------------------
#
# Project created by QtCreator 2017-07-29T10:15:35
#
#-------------------------------------------------

QT       += core gui sql printsupport axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PatholoSystem
TEMPLATE = app
DEFINES += HAVE_CONFIG_H
INCLUDEPATH += printtemplate/include

include($$PWD/printtemplate/qtpropertybrowser/src/qtpropertybrowser.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog/logindialog.cpp \
    config/qreadini.cpp \
    logindialog/logindata.cpp \
    messagebox/messagedialog.cpp \
    singleton/singleton.cpp \
    tabregister/tabregister.cpp \
    tabregister/registerdata.cpp \
    tabregister/newslices.cpp \
    tabregister/patientinfo.cpp \
    tabregister/newmoreslices.cpp \
    tabsystemset/tabsystemset.cpp \
    tabsystemset/otherwidget/typeset.cpp \
    tabmaterial/tabmaterial.cpp \
    tabnormalslice/tabnormalslice.cpp \
    printtemplate/templatesetup.cpp \
    printtemplate/movewidgetcontrol/movewidgetcontrol.cpp \
    printtemplate/qcustomplot/qcustomplot.cpp \
    printtemplate/QRcode/bitstream.c \
    printtemplate/QRcode/mask.c \
    printtemplate/QRcode/mmask.c \
    printtemplate/QRcode/mqrspec.c \
    printtemplate/QRcode/qrenc.c \
    printtemplate/QRcode/qrencode.c \
    printtemplate/QRcode/qrinput.c \
    printtemplate/QRcode/qrspec.c \
    printtemplate/QRcode/rscode.c \
    printtemplate/QRcode/split.c \
    printtemplate/qselectwidget/qselectwidget.cpp

HEADERS  += mainwindow.h \
    logindialog/logindialog.h \
    config/qreadini.h \
    logindialog/logindata.h \
    databasedef.h \
    messagebox/messagedialog.h \
    singleton/singleton.h \
    globaldef.h \
    tabregister/tabregister.h \
    tabregister/registerdata.h \
    tabregister/newslices.h \
    tabregister/patientinfo.h \
    tabregister/newmoreslices.h \
    tabsystemset/tabsystemset.h \
    tabsystemset/otherwidget/typeset.h \
    tabmaterial/tabmaterial.h \
    tabnormalslice/tabnormalslice.h \
    printtemplate/globaldef.h \
    printtemplate/templatesetup.h \
    printtemplate/include/crc32.h \
    printtemplate/include/deflate.h \
    printtemplate/include/gzguts.h \
    printtemplate/include/inffast.h \
    printtemplate/include/inffixed.h \
    printtemplate/include/inflate.h \
    printtemplate/include/inftrees.h \
    printtemplate/include/png.h \
    printtemplate/include/pngconf.h \
    printtemplate/include/pngdebug.h \
    printtemplate/include/PngFile.h \
    printtemplate/include/pnginfo.h \
    printtemplate/include/pnglibconf.h \
    printtemplate/include/pngpriv.h \
    printtemplate/include/pngstruct.h \
    printtemplate/include/trees.h \
    printtemplate/include/zconf.h \
    printtemplate/include/zint.h \
    printtemplate/include/zlib.h \
    printtemplate/include/zutil.h \
    printtemplate/movewidgetcontrol/movewidgetcontrol.h \
    printtemplate/qcustomplot/qcustomplot.h \
    printtemplate/QRcode/bitstream.h \
    printtemplate/QRcode/config.h \
    printtemplate/QRcode/mask.h \
    printtemplate/QRcode/mmask.h \
    printtemplate/QRcode/mqrspec.h \
    printtemplate/QRcode/png.h \
    printtemplate/QRcode/qrencode.h \
    printtemplate/QRcode/qrencode_inner.h \
    printtemplate/QRcode/qrinput.h \
    printtemplate/QRcode/qrspec.h \
    printtemplate/QRcode/rscode.h \
    printtemplate/QRcode/split.h \
    printtemplate/qselectwidget/qselectwidget.h

FORMS  += mainwindow.ui \
    logindialog/logindialog.ui \
    messagebox/messagedialog.ui \
    tabregister/tabregister.ui \
    tabregister/newslices.ui \
    tabregister/patientinfo.ui \
    tabregister/newmoreslices.ui \
    tabsystemset/tabsystemset.ui \
    tabsystemset/otherwidget/typeset.ui \
    tabmaterial/tabmaterial.ui \
    tabnormalslice/tabnormalslice.ui \
    printtemplate/templatesetup.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc


LIBS += $$PWD//lib/libpng16.lib \
        $$PWD//lib/zlib.lib
