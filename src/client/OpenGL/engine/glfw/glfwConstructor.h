#pragma once

namespace gl {

struct GlfwConstructor {
  const int glfwVersionMajor = 3;
  const int glfwVersionMinor = 3;
};

constexpr GlfwConstructor GlfwConstructorDefault = {};
}  // namespace gl