TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    fraction.cpp \
    mixednumbersv2.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stack.h \
    rpn.h \
    fraction.h \
    parser.h \
    queh ue.\
    mixednumbersv2.h \
    queue.h

