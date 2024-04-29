#include "glfw.hpp"

GLFW::GLFW(int versionMajor, int versionMinor)
{
  if (!glfwInit()) {
    throw "Failed to initialize glfw\n";
  }

  // set version of openGL
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
  // do not use backward compatibility
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFW::~GLFW()
{
  glfwTerminate();
}