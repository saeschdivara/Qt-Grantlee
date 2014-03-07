#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T14:50:52
#
#-------------------------------------------------

QT       -= gui

TARGET = loadertags
TEMPLATE = lib

DEFINES += LOADERTAGS_LIBRARY

SOURCES += \
    block.cpp \
    blockcontext.cpp \
    extends.cpp \
    include.cpp \
    loadertags.cpp

HEADERS +=\
        loadertags_global.h \
    loadertags.h \
    block.h \
    blockcontext.h \
    extends.h \
    include.h

INCLUDEPATH += ..

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES +=


macx: LIBS += -L$$PWD/../../../../dist/3rdparty/grantlee/template_library/debug/ -ltemplate_library

INCLUDEPATH += $$PWD/../../../../dist/3rdparty/grantlee/template_library/debug
DEPENDPATH += $$PWD/../../../../dist/3rdparty/grantlee/template_library/debug
