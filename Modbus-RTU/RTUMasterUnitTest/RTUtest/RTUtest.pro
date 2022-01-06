#-------------------------------------------------
#
# Project created by QtCreator 2021-08-06T15:25:08
#
#-------------------------------------------------

QT       += widgets testlib core gui serialport

TARGET = tst_rtutesttest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11
TEMPLATE = app


SOURCES += tst_rtutesttest.cpp \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/historymessagedialog.cpp \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/widget.cpp \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/inputdatadialog.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

FORMS += \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/historymessagedialog.ui \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/widget.ui \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/inputdatadialog.ui

HEADERS += \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/historymessagedialog.h \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/widget.h \
    ../../Modbus-RTU-Master/Modbus-RTU-Master/inputdatadialog.h
