add_executable(${PROJECT_NAME}-Client)
target_sources(${PROJECT_NAME}-Client PRIVATE "${CMAKE_CURRENT_LIST_DIR}/main.cpp")
target_compile_options(${PROJECT_NAME}-Client PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME}-Client PRIVATE "cxx_std_23")
target_link_libraries(${PROJECT_NAME}-Client glfw glad)

set(CLIENT_PATH ${CMAKE_CURRENT_BINARY_DIR})

# target_link_libraries(${PROJECT_NAME}-Client "${CMAKE_CURRENT_LIST_DIR}\\preGLEW\\lib-vc2015\\glfw3.lib")
file(GLOB_RECURSE CMAKELISTS_FILES "${CMAKE_CURRENT_LIST_DIR}/**/CMakeLists.txt")

foreach(CMAKELIST_PATH IN LISTS CMAKELISTS_FILES)
  get_filename_component(SUBDIR_PATH "${CMAKELIST_PATH}" DIRECTORY)

  add_subdirectory("${SUBDIR_PATH}")
endforeach()