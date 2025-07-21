cmake_minimum_required(VERSION 3.28)
project(Morpion LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include(CTest)
enable_testing()

include_directories(inc)
set(SOURCE_FILES 
    src/main.cpp 
    src/plateau.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(Morpion PRIVATE SFML::Graphics)
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
