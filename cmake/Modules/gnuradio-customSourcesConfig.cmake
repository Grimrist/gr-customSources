find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_customSources gnuradio-customSources)

FIND_PATH(
    GR_customSources_INCLUDE_DIRS
    NAMES gnuradio/customSources/api.h
    HINTS $ENV{customSources_DIR}/include
        ${PC_customSources_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_customSources_LIBRARIES
    NAMES gnuradio-customSources
    HINTS $ENV{customSources_DIR}/lib
        ${PC_customSources_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-customSourcesTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_customSources DEFAULT_MSG GR_customSources_LIBRARIES GR_customSources_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_customSources_LIBRARIES GR_customSources_INCLUDE_DIRS)
