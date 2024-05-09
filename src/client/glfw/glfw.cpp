#include "glfw.hpp"
#include <iostream>
#include "GLFW/glfw3.h"

GLFW::GLFW(const GlfwParamConstructor param)
{
  std::cout << "create glfw\n";
  // check if glfw initialize successful
  if (!glfwInit()) {
    throw "Failed to initialize glfw\n";
  }

  // set version of openGL
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, param.versionMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, param.versionMinor);
  // do not use backward compatibility
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFW::~GLFW()
{
  glfwTerminate();
}