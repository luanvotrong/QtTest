TEMPLATE = app

QT += qml quick widgets webview webengine webenginewidgets
CONFIG += c++11

SOURCES += main.cpp \
    Classes/HTMLHandler.cpp

RESOURCES += Resource/default.txt

INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10240.0/ucrt"
LIBS += -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10240.0/ucrt/x86/"

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Classes/HTMLHandler.h
