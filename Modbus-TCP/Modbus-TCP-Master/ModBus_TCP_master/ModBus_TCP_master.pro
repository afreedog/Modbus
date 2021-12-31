#-------------------------------------------------
#
# Project created by QtCreator 2021-07-20T15:29:59
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModBus_TCP_master
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    historymessagedialog.cpp \
    inputdialog.cpp

HEADERS  += widget.h \
    historymessagedialog.h \
    inputdialog.h

FORMS    += widget.ui \
    historymessagedialog.ui \
    inputdialog.ui

CONFIG += c++11

RESOURCES +=
