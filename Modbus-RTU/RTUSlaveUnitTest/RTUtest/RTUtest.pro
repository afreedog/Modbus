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
    ../../Modbus-RTU-Slave/ModBus_RTU_slaver/historymessagedialog.cpp \
    ../../Modbus-RTU-Slave/ModBus_RTU_slaver/widget.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

FORMS += \
    ../../Modbus-RTU-Slave/ModBus_RTU_slaver/historymessagedialog.ui \
    ../../Modbus-RTU-Slave/ModBus_RTU_slaver/widget.ui

HEADERS += \
    ../../Modbus-RTU-Slave/ModBus_RTU_slaver/historymessagedialog.h \
    ../../Modbus-RTU-Slave/ModBus_RTU_slaver/widget.h
