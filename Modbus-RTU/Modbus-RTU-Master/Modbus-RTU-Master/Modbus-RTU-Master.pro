#-------------------------------------------------
#
# Project created by QtCreator 2021-12-22T16:08:05
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modbus-RTU-Master
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    historymessagedialog.cpp \
    inputdatadialog.cpp

HEADERS  += widget.h \
    historymessagedialog.h \
    inputdatadialog.h

FORMS    += widget.ui \
    historymessagedialog.ui \
    inputdatadialog.ui
