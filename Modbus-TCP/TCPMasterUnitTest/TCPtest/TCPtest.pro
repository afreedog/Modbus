#-------------------------------------------------
#
# Project created by QtCreator 2021-08-09T09:56:27
#
#-------------------------------------------------

QT       += widgets testlib core gui network

TARGET = tst_tcptesttest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += tst_tcptesttest.cpp \
    ../../Modbus-TCP-Master/ModBus_TCP_master/historymessagedialog.cpp \
    ../../Modbus-TCP-Master/ModBus_TCP_master/inputdialog.cpp \
    ../../Modbus-TCP-Master/ModBus_TCP_master/widget.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

FORMS += \
    ../../Modbus-TCP-Master/ModBus_TCP_master/historymessagedialog.ui \
    ../../Modbus-TCP-Master/ModBus_TCP_master/inputdialog.ui \
    ../../Modbus-TCP-Master/ModBus_TCP_master/widget.ui

HEADERS += \
    ../../Modbus-TCP-Master/ModBus_TCP_master/historymessagedialog.h \
    ../../Modbus-TCP-Master/ModBus_TCP_master/inputdialog.h \
    ../../Modbus-TCP-Master/ModBus_TCP_master/widget.h
