#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T14:42:29
#
#-------------------------------------------------

QT       -= gui

TARGET = defaulttags
TEMPLATE = lib

DEFINES += DEFAULTTAGS_LIBRARY

SOURCES += \
    autoescape.cpp \
    comment.cpp \
    cycle.cpp \
    debug.cpp \
    defaulttags.cpp \
    filtertag.cpp \
    firstof.cpp \
    for.cpp \
    if.cpp \
    ifchanged.cpp \
    ifequal.cpp \
    load.cpp \
    mediafinder.cpp \
    now.cpp \
    range.cpp \
    regroup.cpp \
    spaceless.cpp \
    templatetag.cpp \
    widthratio.cpp \
    with.cpp

HEADERS +=\
        defaulttags_global.h \
    autoescape.h \
    comment.h \
    cycle.h \
    debug.h \
    defaulttags.h \
    filtertag.h \
    firstof.h \
    for.h \
    if.h \
    ifchanged.h \
    ifequal.h \
    load.h \
    mediafinder.h \
    now.h \
    range.h \
    regroup.h \
    spaceless.h \
    templatetag.h \
    widthratio.h \
    with.h

INCLUDEPATH += ..

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES +=
