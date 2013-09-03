
include(CMakeParseArguments)

macro(grantlee_adjust_plugin_name pluginname)
  set_target_properties(${pluginname}
    PROPERTIES PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/grantlee/${Grantlee_VERSION_MAJOR}.${Grantlee_VERSION_MINOR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/grantlee/${Grantlee_VERSION_MAJOR}.${Grantlee_VERSION_MINOR}"
  )
endmacro()

macro(qt4_wrap_cpp)
  qt5_wrap_cpp(${ARGN})
endmacro()

macro(qt4_wrap_ui)
  qt5_wrap_ui(${ARGN})
endmacro()

macro(qt4_add_resources)
  qt5_add_resources(${ARGN})
endmacro()

macro(qt4_generate_moc)
  qt5_generate_moc(${ARGN})
endmacro()
