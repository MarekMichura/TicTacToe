#ifndef WINDOW_PARAM_H
#define WINDOW_PARAM_H

#include <GLFW/glfw3.h>
#include <string>

struct WindowParamConstructor {
  int windowWidth = 1920;
  int windowHeight = 1080;
  std::string windowTitle = "Window title";
  GLFWmonitor* monitorToFullScreen = nullptr;
  GLFWwindow* windowToShareResource = nullptr;
};

#endif