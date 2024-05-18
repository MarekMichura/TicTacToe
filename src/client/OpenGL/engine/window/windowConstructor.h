#pragma once

#include <string>
#include "GLFW/glfw3.h"

constexpr int DEFAULT_WINDOW_SIZE = 800;

namespace gl {
struct WindowConstructor {
  int windowWidth = DEFAULT_WINDOW_SIZE;
  int windowHeight = DEFAULT_WINDOW_SIZE;
  std::string windowTitle = "Window title";
  GLFWmonitor* monitorToFullScreen = nullptr;
  GLFWwindow* windowToShareResource = nullptr;
};
}  // namespace gl