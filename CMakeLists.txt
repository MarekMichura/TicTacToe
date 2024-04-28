cmake_minimum_required(VERSION 3.28)
project(TicTacToe CXX)

# compillation flags
# -lstdc+ -Ofast
set(FLAGS
  -Wall
  -Wextra
  -Werror
  -pedantic
  -Wconversion)

include(FetchContent)

# library for testing
# FetchContent_Declare(
# GoogleTest
# GIT_REPOSITORY https://github.com/google/googletest.git
# GIT_TAG main)

# FetchContent_MakeAvailable(GoogleTest)
# include(GoogleTest)

# OpenGL
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw)

FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git)

FetchContent_MakeAvailable(glad)

# QT6
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

# find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

# Static files
include_directories(${CMAKE_BINARY_DIR}/_deps/src/)

# directory
add_subdirectory(src/lib)
add_subdirectory(src/client)
