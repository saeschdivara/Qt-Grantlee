#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T15:19:56
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SimpleTemplateRendering
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += $$PWD/../../templates/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/templates/lib/debug/release/ -ltemplate_library
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build/templates/lib/debug/debug/ -ltemplate_library
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/templates/lib/release/ -ltemplate_library
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build/templates/lib/debug/ -ltemplate_library
