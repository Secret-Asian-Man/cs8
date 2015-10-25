TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base_node.cpp \
    driver.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    base_node.h \
    driver.h \
    node.h \
    queue.h

