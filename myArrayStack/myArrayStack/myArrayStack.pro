TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base_stack.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    base_stack.h \
    stack.h

