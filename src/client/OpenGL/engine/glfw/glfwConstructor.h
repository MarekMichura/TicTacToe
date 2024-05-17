#pragma once

namespace gl {

struct GlfwConstructor {
  int glfwVersionMajor = 3;
  int glfwVersionMinor = 3;
};

constexpr GlfwConstructor GlfwConstructorDefault = {};
}  // namespace gl