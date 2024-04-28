#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "OpenGl/GLFW.cpp"
#include "OpenGl/Window.cpp"

int main() {
  try {
    GLFW glfw;
    Window window;

    window.select();
    gladLoadGL();
    window.setFullViewPort(&window);
    window.setClearColor(1, 1, 1, 1);
    Window::clear();
    window.swapBuffer();

    while (window.shouldClose()) {
      glfwPollEvents();
    }
  } catch (std::string error) {
    std::cout << error << "\n";
  }
}
