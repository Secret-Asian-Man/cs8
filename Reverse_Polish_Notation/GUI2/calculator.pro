#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T14:11:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    fraction.cpp \
    mixednumbersv2.cpp

HEADERS  += mainwindow.h \
    fraction.h \
    mixednumbersv2.h \
    parser.h \
    queue.h \
    stack.h

FORMS    += mainwindow.ui
