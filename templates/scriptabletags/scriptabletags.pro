#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T14:53:32
#
#-------------------------------------------------

QT       -= gui

TARGET = scriptabletags
TEMPLATE = lib

DEFINES += SCRIPTABLETAGS_LIBRARY

SOURCES += \
    scriptablecontext.cpp \
    scriptablefilter.cpp \
    scriptablefilterexpression.cpp \
    scriptablenode.cpp \
    scriptableparser.cpp \
    scriptablesafestring.cpp \
    scriptabletags.cpp \
    scriptabletemplate.cpp \
    scriptablevariable.cpp

HEADERS +=\
        scriptabletags_global.h \
    scriptablecontext.h \
    scriptablefilter.h \
    scriptablefilterexpression.h \
    scriptablenode.h \
    scriptableparser.h \
    scriptablesafestring.h \
    scriptabletags.h \
    scriptabletemplate.h \
    scriptablevariable.h

INCLUDEPATH += ..

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES +=
