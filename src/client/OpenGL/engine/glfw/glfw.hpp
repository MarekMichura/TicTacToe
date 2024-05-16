#pragma once

#include "glfwConstructor.h"

namespace gl {

class GLFW {
private:
public:
  GLFW(const GLFW&) = delete;
  GLFW(const GlfwConstructor& params = GlfwConstructorDefault);
  ~GLFW();

private:
};
}  // namespace gl