﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required(VERSION 3.5)

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("TicTacToe" "CXX")

# if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
if(MSVC)
  set(FLAGS )
else()
  set(FLAGS -Wall -pedantic -Wextra -Werror -Wconversion -fno-exceptions)
endif()

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad)
FetchContent_MakeAvailable(glad)

# FetchContent_Declare(
# glm
# GIT_REPOSITORY https://github.com/g-truc/glm)
# FetchContent_MakeAvailable(glm)

# Include sub-projects.
add_subdirectory("client")
add_subdirectory("debug")