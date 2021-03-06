project(grantlee_textdocument_tests)

find_package(Qt5Test 5.2.0 CONFIG REQUIRED)

set( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR} )

macro(GRANTLEE_TEXTDOCUMENT_UNIT_TESTS)
  foreach(_testname ${ARGN})
    set(_testSrcs ${_testname}.cpp coverageobject.cpp)
    set(moc_output_file "${CMAKE_CURRENT_BINARY_DIR}/${_testname}.moc")
    qt5_generate_moc(${_testname}.cpp ${moc_output_file})
    qt5_generate_moc(coverageobject.h coverageobject.moc )
    add_executable(${_testname}_exec ${_testSrcs} coverageobject.cpp ${CMAKE_CURRENT_BINARY_DIR}/coverageobject.moc ${moc_output_file} )
    add_test(${_testname} ${_testname}_exec )
    target_link_libraries(${_testname}_exec Qt5::Test Grantlee::TextDocument )
    set_property(GLOBAL APPEND PROPERTY TEST_COVERAGE "${CMAKE_CURRENT_BINARY_DIR}/${_testname}_exec" )
  endforeach(_testname)
endmacro(GRANTLEE_TEXTDOCUMENT_UNIT_TESTS)

grantlee_textdocument_unit_tests(
  htmlbuildertest
  plainmarkupbuildertest
)
