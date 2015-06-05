#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T15:00:29
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetworkClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp

HEADERS  += mainwindow.h \
    tcpclient.h

FORMS    += mainwindow.ui
