project(textedit_grantlee)

cmake_minimum_required(VERSION 2.8.11)

find_package(Grantlee REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

include(${Grantlee_USE_FILE})

## Grantlee plugin

add_library(customtags MODULE
  customtagslibrary.cpp
  audiotextdocumentoutputter.cpp
  filters.cpp
)
grantlee_adjust_plugin_name(customtags)

target_link_libraries(customtags
  ${Grantlee_TEMPLATES_LIBRARIES}
  ${Grantlee_TEXTDOCUMENT_LIBRARIES}
)


## Application

configure_file(grantlee_paths.h.cmake ${PROJECT_BINARY_DIR}/grantlee_paths.h)

set(textedit_example_SRCS
  main.cpp
  audiotextedit.cpp
  audioobject.cpp
  textedit.cpp
)

set(textedit_example_RCSS
  textedit.qrc
)

qt5_add_resources(
  textedit_example_RCS_SRCS
  ${textedit_example_RCSS}
)

add_executable(textedit
  ${textedit_example_SRCS}
  ${textedit_example_RCS_SRCS}
  ${textedit_example_UI_SRCS}
)

target_link_libraries(
  textedit
  Qt4::QtWebKit
  Qt4::phonon
  ${Grantlee_TEMPLATES_LIBRARIES}
)



