TEMPLATE = app

QT += qml quick webengine webenginewidgets widgets
CONFIG += c++11

SOURCES += main.cpp \
    Classes/HTMLHandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Classes/HTMLHandler.h
