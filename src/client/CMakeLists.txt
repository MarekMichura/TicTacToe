set(CLIENT_FILES
  main.cpp

  obj/myFirstObj.cpp

  src/window.cpp
  src/shader.cpp
  src/glfw.cpp

  src/pipeline.cpp
  src/vertexArray.cpp
  src/vertexBuffer.cpp
)
add_subdirectory("Shaders")

add_executable(${PROJECT_NAME}-client ${CLIENT_FILES})
target_compile_options(${PROJECT_NAME}-client PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME}-client PRIVATE cxx_std_23)
target_link_libraries(${PROJECT_NAME}-client glfw glad)