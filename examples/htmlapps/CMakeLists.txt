
cmake_minimum_required(VERSION 2.8.11)

project(htmlapps)

find_package(Grantlee REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

include(${Grantlee_USE_FILE})

configure_file(grantlee_paths.h.cmake ${PROJECT_BINARY_DIR}/grantlee_paths.h)

set(htmlapps_SRCS
  main.cpp
  mainwindow.cpp
  localrequestmanager.cpp
  templatereply.cpp
)

add_library(customplugin MODULE
  customplugin.cpp
  rssfeed.cpp
)
grantlee_adjust_plugin_name(customplugin)

target_link_libraries(customplugin
  ${Grantlee_TEMPLATES_LIBRARIES}
  Qt4::QtXmlPatterns
  Qt4::QtNetwork
)

add_executable(htmlapps
  ${htmlapps_SRCS}
)

target_link_libraries(htmlapps
  ${Grantlee_TEMPLATES_LIBRARIES}
  Qt4::QtWebKit
)
