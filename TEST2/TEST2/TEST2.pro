TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    word.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pair.h \
    vectorHeap.h \
    word.h

