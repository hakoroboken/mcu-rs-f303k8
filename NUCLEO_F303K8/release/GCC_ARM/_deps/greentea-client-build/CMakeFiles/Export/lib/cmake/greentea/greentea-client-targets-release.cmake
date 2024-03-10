#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "greentea::client" for configuration "release"
set_property(TARGET greentea::client APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(greentea::client PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclient.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS greentea::client )
list(APPEND _IMPORT_CHECK_FILES_FOR_greentea::client "${_IMPORT_PREFIX}/lib/libclient.a" )

# Import target "greentea::client_userio" for configuration "release"
set_property(TARGET greentea::client_userio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(greentea::client_userio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclient_userio.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS greentea::client_userio )
list(APPEND _IMPORT_CHECK_FILES_FOR_greentea::client_userio "${_IMPORT_PREFIX}/lib/libclient_userio.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
