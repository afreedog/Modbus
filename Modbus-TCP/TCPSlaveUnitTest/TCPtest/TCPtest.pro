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
    ../../Modbus-TCP-Slave/Modbus-TCP-Slave/historymessagedialog.cpp \
    ../../Modbus-TCP-Slave/Modbus-TCP-Slave/widget.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

FORMS += \
    ../../Modbus-TCP-Slave/Modbus-TCP-Slave/historymessagedialog.ui \
    ../../Modbus-TCP-Slave/Modbus-TCP-Slave/widget.ui

HEADERS += \
    ../../Modbus-TCP-Slave/Modbus-TCP-Slave/historymessagedialog.h \
    ../../Modbus-TCP-Slave/Modbus-TCP-Slave/widget.h
