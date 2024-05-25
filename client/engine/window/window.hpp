#pragma once

#include <string>
#include <GLFW/glfw3.h>

#include "color.hpp"

namespace gl {
struct WindowConstructor {
  static constexpr uint WINDOW_DEFAULT_WIDTH = 800;
  static constexpr uint WINDOW_DEFAULT_HEIGHT = 600;
  static constexpr char WINDOW_DEFAULT_TITLE[] = "Window title";

  uint windowWidth = WINDOW_DEFAULT_WIDTH;
  uint windowHeight = WINDOW_DEFAULT_HEIGHT;
  std::string windowTitle = WINDOW_DEFAULT_TITLE;
  GLFWmonitor* windowMonitor = nullptr;
  GLFWwindow* windowShare = nullptr;
};

class Window {
private:
  GLFWwindow* window;

public:
  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  Window(const WindowConstructor& param = WindowConstructor{});
  ~Window();

  void use();
  void close();
  void swapBuffer();
  bool shouldClose();
  GLFWwindow* getWindow();
  void setKeyCallBack(GLFWkeyfun callBack);

  static void clearSelectedWindow();
  static void setViewPortSelectedWindow(const int width, const int height);
  static void setClearColor(const Color& color);

private:
  static GLFWwindow* CreateWindow(const WindowConstructor& params);
  static void eventViewBufferChange(GLFWwindow* window, const int width, const int height);
};
};  // namespace gl