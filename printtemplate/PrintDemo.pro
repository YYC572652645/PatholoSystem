#-------------------------------------------------
#
# Project created by QtCreator 2017-08-03T21:28:35
#
#-------------------------------------------------

QT       += core gui printsupport axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PrintDemo
TEMPLATE = app
DEFINES += HAVE_CONFIG_H
INCLUDEPATH += include

SOURCES += main.cpp\
    templatesetup.cpp\
    qcustomplot/qcustomplot.cpp \
    qselectwidget/qselectwidget.cpp \
    movewidgetcontrol/movewidgetcontrol.cpp \
    QRcode/bitstream.c \
    QRcode/mqrspec.c \
    QRcode/qrenc.c \
    QRcode/qrencode.c \
    QRcode/qrinput.c \
    QRcode/qrspec.c \
    QRcode/rscode.c \
    QRcode/split.c \
    QRcode/mask.c \
    QRcode/mmask.c


HEADERS  += templatesetup.h \
    qcustomplot/qcustomplot.h \
    globaldef.h \
    qselectwidget/qselectwidget.h \
    movewidgetcontrol/movewidgetcontrol.h \
    QRcode/bitstream.h \
    QRcode/config.h \
    QRcode/mqrspec.h \
    QRcode/png.h \
    QRcode/qrencode.h \
    QRcode/qrencode_inner.h \
    QRcode/qrinput.h \
    QRcode/qrspec.h \
    QRcode/rscode.h \
    QRcode/split.h \
    QRcode/mask.h \
    QRcode/mmask.h \
    include/crc32.h \
    include/deflate.h \
    include/gzguts.h \
    include/inffast.h \
    include/inffixed.h \
    include/inflate.h \
    include/inftrees.h \
    include/png.h \
    include/pngconf.h \
    include/pngdebug.h \
    include/PngFile.h \
    include/pnginfo.h \
    include/pnglibconf.h \
    include/pngpriv.h \
    include/pngstruct.h \
    include/trees.h \
    include/zconf.h \
    include/zint.h \
    include/zlib.h \
    include/zutil.h \

FORMS    += templatesetup.ui

include($$PWD/qtpropertybrowser/src/qtpropertybrowser.pri)

RESOURCES += \
    res.qrc


LIBS += D:/Program/Qt/PrintDemo/lib/libpng16.lib \
        D:/Program/Qt/PrintDemo/lib/zlib.lib



win32: LIBS += -L$$PWD/lib/ -llibpng16

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32: LIBS += -L$$PWD/lib/ -lzlib

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
