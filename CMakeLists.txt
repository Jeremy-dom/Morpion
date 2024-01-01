cmake_minimum_required(VERSION 3.16)
project(Morpion LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include(CTest)
enable_testing()

set(SOURCE_DIR 
    src/main.cpp)

include_directories(inc)

add_executable(Morpion ${SOURCE_DIR})
target_link_libraries(Morpion PRIVATE sfml-graphics)
target_compile_features(Morpion PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Morpion
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Morpion>
        VERBATIM)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
install(TARGETS Morpion)
