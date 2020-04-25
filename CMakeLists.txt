cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

project(vertel)

#include_directories(
#    include
#)

#set(VERTEL_SHARED_SOURCES
#    src/some.cpp
#)

set(VERTEL_SOURCES
    src/main.cpp
    # ${VERTEL_SHARED_SOURCES}
)

add_executable(
    ${PROJECT_NAME} src/main.cpp
    ${VERTEL_SOURCES}
)
