TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    driver.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    driver.h \
    queue.h

