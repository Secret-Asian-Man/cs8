#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T15:01:15
#
#-------------------------------------------------
QT       += core gui
QT += quickwidgets
QT += quick qml network positioning location
QT += positioning

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShortestPath
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shortestdistance.cpp

RESOURCES += \
    places_map.qrc \

HEADERS  += mainwindow.h \
    containers.h \
    shortestdistance.h

FORMS    += mainwindow.ui
