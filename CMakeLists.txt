CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

PROJECT(OpenGL)

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)


############################## 3RD PARTIES LIBS ################################

SET(OpenGL_GL_PREFERENCE GLVND)
SET(LIBS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/include)

FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(SDL REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)

#SET(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

INCLUDE_DIRECTORIES(
        SYSTEM
        #${SDL2_INCLUDE_DIRS}
        ${SDL_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        ${LIBS_INCLUDE_DIR}
        ${EIGEN3_INCLUDE_DIR}
        ${C3GA_INCLUDE_DIRS}
)

LINK_LIBRARIES(
       # ${SDL2_LIBRARIES}
        ${SDL_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY}
        ${C3GA_LIBRARIES}
)

################################### PROJECT ####################################

SET(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)

FILE(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
FILE(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.hpp)
FILE(GLOB_RECURSE SHADER_FILES ${CMAKE_SOURCE_DIR}/shader/*.glsl)
FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

INCLUDE_DIRECTORIES(
        ${INCLUDE_DIR}
)

SET(TARGET_NAME openGL)
ADD_EXECUTABLE(${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES} include/camera/Camera.hpp src/camera/Camera.cpp)


TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -g
        -O3
        -std=c++17
)
# Adding as much warning as possible on GNU gcc/g++ and Clang
IF (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    TARGET_COMPILE_OPTIONS(
            ${TARGET_NAME} PRIVATE
            -Wall
            -Wextra
    )
ELSEIF (CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    TARGET_COMPILE_OPTIONS(
            ${TARGET_NAME} PRIVATE
            -Weverything
            -Werror
            -Wfatal-errors
    )
    IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.0.0")
    ELSE ()
    ENDIF ()
ENDIF ()


# Disable some warnings
TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -Wno-unused-parameter
        -Wno-shadow
)
IF (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS_EQUAL "8.0.0")
    ELSE ()
    ENDIF ()
ELSEIF (CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    TARGET_COMPILE_OPTIONS(
            ${TARGET_NAME} PRIVATE
            -Wno-padded
            -Wno-c++98-compat
            -Wno-weak-vtables
            -Wno-unknown-pragmas
            -Wno-exit-time-destructors
            -Wno-sign-conversion
            -Wno-sign-compare
    )
    IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.0.0")
    ELSE ()
    ENDIF ()
ENDIF ()