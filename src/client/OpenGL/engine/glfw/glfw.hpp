#pragma once

#include "glfwConstructor.h"

namespace gl {

class GLFW {
private:
public:
  GLFW(const GLFW&) = delete;
  GLFW(GLFW&&) = delete;
  GLFW& operator=(const GLFW&) = delete;
  GLFW& operator=(GLFW&&) = delete;

  GLFW(const GlfwConstructor& params = GlfwConstructorDefault);
  ~GLFW();

private:
};
}  // namespace gl