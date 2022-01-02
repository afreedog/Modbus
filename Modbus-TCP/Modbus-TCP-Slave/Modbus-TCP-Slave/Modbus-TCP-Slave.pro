#-------------------------------------------------
#
# Project created by QtCreator 2021-12-13T18:22:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modbus-TCP-Slave
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    historymessagedialog.cpp

HEADERS  += widget.h \
    historymessagedialog.h

FORMS    += widget.ui \
    historymessagedialog.ui
