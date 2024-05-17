#pragma once

#include <string>
#include "GLFW/glfw3.h"

struct WindowConstructor {
  int windowWidth = 800;
  int windowHeight = 800;
  std::string windowTitle = "Window title";
  GLFWmonitor* monitorToFullScreen = nullptr;
  GLFWwindow* windowToShareResource = nullptr;
};

constexpr WindowConstructor windowConstructorDefault = {};