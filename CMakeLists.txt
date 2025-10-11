cmake_minimum_required(VERSION 4.0.0)

project(utils
        VERSION 0.0.0
        DESCRIPTION "Utils library"
        LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

set(PATH_VERSION "${INCLUDE_DIR}/Utils/Generated/Version.hpp")
set(TEMPLATE_PATH "${PROJECT_SOURCE_DIR}/cmake/config/Version.hpp.in")
file(GLOB_RECURSE FILES_TO_FORMAT
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/Utils/*.hpp")

include(ClangTidy)
include(ClangFormat)
include(MakeVersion)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
        PRIVATE ${SOURCES}
        PUBLIC  FILE_SET HEADERS BASE_DIRS ${INCLUDE_DIR} FILES ${HEADERS}
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        "${PROJECT_SOURCE_DIR}/third-party/stb"
)

target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        CXX_EXTENSIONS OFF
        PREFIX ""
)