TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    word.cpp \
    ftoken.cpp \
    stoken.cpp \
    orchard.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pair.h \
    vectorHeap.h \
    word.h \
    ftoken.h \
    stoken.h \
    orchard.h

