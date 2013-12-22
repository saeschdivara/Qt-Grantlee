#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T14:46:07
#
#-------------------------------------------------

QT       -= gui

TARGET = i18n
TEMPLATE = lib

DEFINES += I18N_LIBRARY

SOURCES += \
    i18ntags.cpp \
    l10n_money.cpp \
    with_locale.cpp \
    i18n.cpp \
    i18nc.cpp \
    i18ncp.cpp \
    i18np.cpp

HEADERS +=\
        i18n_global.h \
    i18np.h \
    i18ntags.h \
    l10n_money.h \
    with_locale.h \
    i18n.h \
    i18nc.h \
    i18ncp.h

INCLUDEPATH += ..

unix {
    target.path = /usr/lib
    INSTALLS += target
}
