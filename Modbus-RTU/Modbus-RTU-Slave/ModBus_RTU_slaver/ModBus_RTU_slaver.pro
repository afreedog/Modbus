#-------------------------------------------------
#
# Project created by QtCreator 2021-07-28T08:28:53
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModBus_RTU_slaver
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    historymessagedialog.cpp

HEADERS  += widget.h \
    historymessagedialog.h

FORMS    += widget.ui \
    historymessagedialog.ui

CONFIG += c++11

RESOURCES +=
