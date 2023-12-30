cmake_minimum_required(VERSION 3.0.0)
project(Morpion VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCE_DIR 
    src/main.cpp)

include_directories(inc)

add_executable(Morpion ${SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
