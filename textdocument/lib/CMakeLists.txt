project(grantlee_textdocument)

set (grantlee_textdocument_SRCS
  bbcodebuilder.cpp
  markupdirector.cpp
  plaintextmarkupbuilder.cpp
  texthtmlbuilder.cpp
  mediawikimarkupbuilder.cpp
)

set(Grantlee_TEXTDOCUMENT_LIB_SOVERSION ${Grantlee_VERSION_MAJOR})

add_library(Grantlee_TextDocument SHARED
  ${grantlee_textdocument_SRCS}
)
generate_export_header(Grantlee_TextDocument)
add_library(Grantlee::TextDocument ALIAS Grantlee_TextDocument)
set_property(TARGET Grantlee_TextDocument PROPERTY EXPORT_NAME TextDocument)

target_link_libraries(Grantlee_TextDocument
  LINK_PUBLIC Qt5::Gui
)

if (NOT CMAKE_BUILD_TYPE MATCHES TestCocoon)
  set_target_properties(Grantlee_TextDocument PROPERTIES
    VERSION    ${Grantlee_VERSION_MAJOR}.${Grantlee_VERSION_MINOR}.${Grantlee_VERSION_PATCH}
    SOVERSION  ${Grantlee_TEXTDOCUMENT_LIB_SOVERSION}
  )
endif()

install(TARGETS Grantlee_TextDocument EXPORT grantlee_targets
         RUNTIME DESTINATION ${BIN_INSTALL_DIR} COMPONENT TextDocument
         LIBRARY DESTINATION ${LIB_INSTALL_DIR} COMPONENT TextDocument
         ARCHIVE DESTINATION ${LIB_INSTALL_DIR} COMPONENT TextDocument
         INCLUDES DESTINATION include
)

install(FILES
  abstractmarkupbuilder.h
  bbcodebuilder.h
  markupdirector.h
  plaintextmarkupbuilder.h
  texthtmlbuilder.h
  mediawikimarkupbuilder.h
  ${PROJECT_BINARY_DIR}/grantlee_textdocument_export.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/grantlee COMPONENT TextDocument
)

install(FILES
  grantlee_textdocument.h
  DESTINATION ${INCLUDE_INSTALL_DIR} COMPONENT TextDocument
)
