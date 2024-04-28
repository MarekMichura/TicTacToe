set(C_FILES
  main.cpp
  OpenGl/Window.cpp
  OpenGl/GLFW.cpp

  # QObjectTest/signalSlotTest.hpp
  # QObjectTest/signalSlotTest.cpp
)

add_executable(${PROJECT_NAME}-client ${C_FILES})
target_compile_options(${PROJECT_NAME}-client PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME}-client PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME}-client glfw glad)