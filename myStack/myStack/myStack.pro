TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base_node.cpp \
    base_stack.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    base_node.h \
    base_stack.h \
    node.h \
    stack.h

