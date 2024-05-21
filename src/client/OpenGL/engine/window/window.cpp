#include <cassert>
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "window.hpp"

namespace gl {
Window::Window(const WindowConstructor& param)
    : window(glfwCreateWindow(  //
          param.windowWidth,
          param.windowHeight,
          param.windowTitle.c_str(),
          param.monitorToFullScreen,
          param.windowToShareResource))
{
  assert(window != nullptr);
  glfwSetFramebufferSizeCallback(window, eventViewPortChange);

  std::cout << "Window has been created\n";
}

Window::~Window()
{
  std::cout << "Window will be destroyed\n";
  glfwDestroyWindow(window);
}

void Window::select()
{
  glfwMakeContextCurrent(window);
}

constexpr int GLFW_SIGNAL_WINDOW_CLOSE = 1;
void Window::close()
{
  glfwSetWindowShouldClose(window, GLFW_SIGNAL_WINDOW_CLOSE);
}

bool Window::shouldClose()
{
  return glfwWindowShouldClose(window) == 0;
}

void Window::swapBuffer()
{
  glfwSwapBuffers(window);
}

void Window::setFullScreen(bool main)
{
  GLFWmonitor* monitor = main ? glfwGetPrimaryMonitor() : glfwGetWindowMonitor(window);

  int width = 0;
  int height = 0;
  glfwGetWindowSize(window, &width, &height);

  int modesCount = 0;
  const GLFWvidmode* modes = glfwGetVideoModes(monitor, &modesCount);
  assert(modes);
  int refreshRate = modes[0].refreshRate;

  glfwSetWindowMonitor(window, monitor, 0, 0, width, height, refreshRate);
}

void Window::setViewPort(const int width, const int height)
{
  glViewport(0, 0, width, height);
}

void Window::eventViewPortChange(  //
    GLFWwindow* window,
    const int width,
    const int height)
{
  glfwMakeContextCurrent(window);
  Window::setViewPort(width, height);
}

void Window::clearSelectedWindow()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setClearColor(const Color& color)
{
  glClearColor(color.red, color.green, color.blue, color.alpha);
}

int Window::getKeyStatus(const int& key)
{
  return glfwGetKey(window, key);
}

}  // namespace gl