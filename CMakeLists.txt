cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(
    libsatk
    VERSION 0.1.0.0
    LANGUAGES CXX
)

include(GNUInstallDirs)

add_library(
    libsatk
    src/ecs/Ecs.cpp
)

target_include_directories(
    libsatk
    PUBLIC include/common
    PUBLIC include/ecs
    PRIVATE src/common
    PRIVATE src/ecs
)

set_target_properties(
    libsatk PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("BUILDING IN DEBUG MODE")
    add_subdirectory(tests/ecs)
ENDIF()

IF(CMAKE_BUILD_TYPE MATCHES Release)
    message("BUILDING IN RELEASE MODE")
ENDIF()