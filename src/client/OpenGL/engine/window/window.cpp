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
  if (window == nullptr) {
    throw "Failed to create window\n";
  }
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

// #define TOP_Y_VIEWPORT 0;
// #define LEFT_X_VIEWPORT 0;
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