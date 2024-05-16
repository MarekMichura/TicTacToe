#pragma once

#include <string>
#include "GLFW/glfw3.h"

struct WindowConstructor {
  const int windowWidth = 800;
  const int windowHeight = 800;
  const std::string windowTitle = "Window title";
  GLFWmonitor* monitorToFullScreen = nullptr;
  GLFWwindow* windowToShareResource = nullptr;
};

constexpr WindowConstructor windowConstructorDefault = {};