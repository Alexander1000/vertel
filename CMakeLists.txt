cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

project(vertel)

include_directories(
    include
)

set(VERTEL_SHARED_SOURCES
    src/image.cpp
)

set(VERTEL_SOURCES
    src/main.cpp
    ${VERTEL_SHARED_SOURCES}
)

add_executable(
    ${PROJECT_NAME} src/main.cpp
    ${VERTEL_SOURCES}
)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package (jpeg REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${JPEG_INCLUDE_DIR})

target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
    ${JPEG_LIBRARIES}
)
