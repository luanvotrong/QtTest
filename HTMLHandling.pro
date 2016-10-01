TEMPLATE = app

QT += qml quick webengine webenginewidgets widgets
CONFIG += c++11

SOURCES += main.cpp \
    Classes/HTMLHandler.cpp \
    Classes/Gumbo/attribute.c \
    Classes/Gumbo/char_ref.c \
    Classes/Gumbo/error.c \
    Classes/Gumbo/parser.c \
    Classes/Gumbo/string_buffer.c \
    Classes/Gumbo/string_piece.c \
    Classes/Gumbo/tag.c \
    Classes/Gumbo/tokenizer.c \
    Classes/Gumbo/utf8.c \
    Classes/Gumbo/util.c \
    Classes/Gumbo/vector.c \
    Classes/Tree/TreeItem.cpp \
    Classes/Tree/TreeModel.cpp

#RESOURCES += Resource/default.txt

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Classes/HTMLHandler.h \
    Classes/Gumbo/attribute.h \
    Classes/Gumbo/char_ref.h \
    Classes/Gumbo/char_ref.rl \
    Classes/Gumbo/error.h \
    Classes/Gumbo/gumbo.h \
    Classes/Gumbo/insertion_mode.h \
    Classes/Gumbo/parser.h \
    Classes/Gumbo/string_buffer.h \
    Classes/Gumbo/string_piece.h \
    Classes/Gumbo/tag_enum.h \
    Classes/Gumbo/tag_gperf.h \
    Classes/Gumbo/tag_sizes.h \
    Classes/Gumbo/tag_strings.h \
    Classes/Gumbo/token_type.h \
    Classes/Gumbo/tokenizer.h \
    Classes/Gumbo/tokenizer_states.h \
    Classes/Gumbo/utf8.h \
    Classes/Gumbo/util.h \
    Classes/Gumbo/vector.h \
    Classes/Tree/TreeItem.h \
    Classes/Tree/TreeModel.h

DISTFILES += \
    Classes/Gumbo/tag.in

RESOURCES += \
    Resource/resources.qrc
