QT += core script
QT -= gui

TEMPLATE = lib

DEFINES += TEMPLATE_LIBRARY

OTHER_FILES += \
    grantlee_test_export.h.in \
    CMakeLists.txt \
    grantlee_config_p.h.cmake \
    grantlee_version.h.cmake

HEADERS += \
    abstractlocalizer.h \
    cachingloaderdecorator.h \
    context.h \
    customtyperegistry_p.h \
    engine_p.h \
    engine.h \
    exception.h \
    filter.h \
    filterexpression.h \
    grantlee_core.h \
    grantlee_tags_p.h \
    grantlee_templates.h \
    lexer_p.h \
    metaenumvariable_p.h \
    metatype.h \
    node.h \
    util.h \
    variable.h \
    nodebuiltins_p.h \
    nulllocalizer_p.h \
    outputstream.h \
    parser.h \
    pluginpointer_p.h \
    qtlocalizer.h \
    rendercontext.h \
    safestring.h \
    statemachine_p.h \
    taglibraryinterface.h \
    template.h \
    templateloader.h \
    textprocessingmachine_p.h \
    token.h \
    typeaccessor.h \
    template_p.h \
    ../grantlee_templates_export.h \
    ../scriptabletags/scriptabletags.h \
    ../scriptabletags/scriptablecontext.h \
    ../scriptabletags/scriptablefilter.h \
    ../scriptabletags/scriptablefilterexpression.h \
    ../scriptabletags/scriptablenode.h \
    ../scriptabletags/scriptableparser.h \
    ../scriptabletags/scriptablesafestring.h \
    ../scriptabletags/scriptabletags_global.h \
    ../scriptabletags/scriptabletemplate.h \
    ../scriptabletags/scriptablevariable.h

SOURCES += \
    abstractlocalizer.cpp \
    cachingloaderdecorator.cpp \
    context.cpp \
    customtyperegistry.cpp \
    engine.cpp \
    filterexpression.cpp \
    lexer.cpp \
    metatype.cpp \
    node.cpp \
    util.cpp \
    variable.cpp \
    nodebuiltins.cpp \
    nulllocalizer.cpp \
    outputstream.cpp \
    parser.cpp \
    qtlocalizer.cpp \
    rendercontext.cpp \
    safestring.cpp \
    template.cpp \
    templateloader.cpp \
    textprocessingmachine.cpp \
    typeaccessors.cpp \
    ../scriptabletags/scriptabletags.cpp \
    ../scriptabletags/scriptablecontext.cpp \
    ../scriptabletags/scriptablefilter.cpp \
    ../scriptabletags/scriptablefilterexpression.cpp \
    ../scriptabletags/scriptablenode.cpp \
    ../scriptabletags/scriptableparser.cpp \
    ../scriptabletags/scriptablesafestring.cpp \
    ../scriptabletags/scriptabletemplate.cpp \
    ../scriptabletags/scriptablevariable.cpp

INCLUDEPATH += ..
