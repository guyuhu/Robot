#-------------------------------------------------
#
# Project created by QtCreator 2015-07-19T21:04:08
#
#-------------------------------------------------

QT       += core gui
QT +=testlib
QT +=network
QT +=core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robot
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    tcpsocket.cpp \
    tcpserver.cpp \
    protocolfromclient2server.cpp \
    jsonfromclient2server.cpp

HEADERS  += \
    mainwindow.h \
    tcpsocket.h \
    tcpserver.h \
    protocolfromclient2server.h \
    jsonfromclient2server.h

DISTFILES += \
    readme.doc

FORMS += \
    mainwindow.ui

#CONFIG +=qtestlib

RESOURCES += \
    resource.qrc

