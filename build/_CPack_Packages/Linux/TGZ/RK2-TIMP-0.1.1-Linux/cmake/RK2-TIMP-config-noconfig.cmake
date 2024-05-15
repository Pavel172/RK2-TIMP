#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "RK2-TIMP" for configuration ""
set_property(TARGET RK2-TIMP APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(RK2-TIMP PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libRK2-TIMP.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS RK2-TIMP )
list(APPEND _IMPORT_CHECK_FILES_FOR_RK2-TIMP "${_IMPORT_PREFIX}/lib/libRK2-TIMP.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
