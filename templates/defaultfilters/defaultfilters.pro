#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T14:37:54
#
#-------------------------------------------------

QT       -= gui

TARGET = defaultfilters
TEMPLATE = lib

DEFINES += DEFAULTFILTERS_LIBRARY

SOURCES += \
    datetime.cpp \
    defaultfilters.cpp \
    integers.cpp \
    lists.cpp \
    logic.cpp \
    misc.cpp \
    stringfilters.cpp

HEADERS +=\
        defaultfilters_global.h \
    datetime.h \
    defaultfilters.h \
    integers.h \
    lists.h \
    logic.h \
    misc.h \
    stringfilters.h

INCLUDEPATH += ..

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES +=

macx: LIBS += -L$$PWD/../../../../dist/3rdparty/grantlee/template_library/debug/ -ltemplate_library

INCLUDEPATH += $$PWD/../../../../dist/3rdparty/grantlee/template_library/debug
DEPENDPATH += $$PWD/../../../../dist/3rdparty/grantlee/template_library/debug
