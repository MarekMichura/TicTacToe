#include <iostream>
#include "glfw.hpp"
#include "GLFW/glfw3.h"

namespace gl {

GLFW::GLFW(const GlfwConstructor& param)
{
  if (glfwInit() == 0) {
    throw "Failed to initialize glfw\n";
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, param.glfwVersionMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, param.glfwVersionMinor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  std::cout << "GLFW has been created\n";
  std::cout << glfwGetVersionString() << "\n";
}

GLFW::~GLFW()
{
  std::cout << "terminate glfw\n";
  glfwTerminate();
}
}  // namespace gl