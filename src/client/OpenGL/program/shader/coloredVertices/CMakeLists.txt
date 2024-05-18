target_include_directories(${PROJECT_NAME}-Client PRIVATE ${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE SHADERS_FILES "**.GLSL")

foreach(SHADER_PATH IN LISTS SHADERS_FILES)
  get_filename_component(SHADER_NAME ${SHADER_PATH} NAME)
  configure_file(
    "${SHADER_PATH}"
    "${CLIENT_PATH}/Shader/${SHADER_NAME}"
    COPYONLY
  )
endforeach()
