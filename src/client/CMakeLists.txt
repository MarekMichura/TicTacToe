set(CLIENT_FILES
  main.cpp
  OpenGl/Window.cpp
  OpenGl/Shader.cpp
  OpenGl/Obj/Triangle.cpp
  OpenGl/GLFW.cpp
)
add_subdirectory("OpenGl/Shaders")

add_executable(${PROJECT_NAME}-client ${CLIENT_FILES})
target_compile_options(${PROJECT_NAME}-client PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME}-client PRIVATE cxx_std_23)
target_link_libraries(${PROJECT_NAME}-client glfw glad)