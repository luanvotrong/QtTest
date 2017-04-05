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

# Add lib gumbo parser
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/gumbo_parser/lib/release/ -lgumbo_parser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/gumbo_parser/lib/debug/ -lgumbo_parser
else:unix: LIBS += -L$$PWD/Libs/gumbo_parser/lib/release/ -lgumbo_parser

INCLUDEPATH += $$PWD/Libs/gumbo_parser/src
DEPENDPATH += $$PWD/Libs/gumbo_parser/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_parser/lib/release/libgumbo_parser.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_parser/lib/debug/libgumbo_parser.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_parser/lib/release/gumbo_parser.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_parser/lib/debug/gumbo_parser.lib
else:unix: PRE_TARGETDEPS += $$PWD/Libs/gumbo_parser/lib/debug/libgumbo_parser.a

# Add lib gumbo query
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/gumbo_query/lib/release/ -lgumbo_query
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/gumbo_query/lib/debug/ -lgumbo_query
else:unix: LIBS += -L$$PWD/Libs/gumbo_query/lib/release/ -lgumbo_query

INCLUDEPATH += $$PWD/Libs/gumbo_query/src
DEPENDPATH += $$PWD/Libs/gumbo_query/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_query/lib/release/libgumbo_query.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_query/lib/debug/libgumbo_query.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_query/lib/release/gumbo_query.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Libs/gumbo_query/lib/debug/gumbo_query.lib
else:unix: PRE_TARGETDEPS += $$PWD/Libs/gumbo_query/lib/debug/libgumbo_query.a
