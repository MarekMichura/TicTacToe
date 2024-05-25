#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <format>
#include <string>

#include "window.hpp"
#include <GL/gl.h>
#include <stdbool.h>
#include "my_assert.h"
#include "my_log.h"

namespace gl {
GLFWwindow* Window::CreateWindow(const WindowConstructor& params)
{
  const int width = static_cast<int>(params.windowWidth);
  const int height = static_cast<int>(params.windowHeight);
  const char* title = params.windowTitle.c_str();
  GLFWmonitor* monitor = params.windowMonitor;
  GLFWwindow* window = params.windowShare;

  return glfwCreateWindow(width, height, title, monitor, window);
}

void Window::eventViewBufferChange(GLFWwindow* window, const int width, const int height)
{
  glfwMakeContextCurrent(window);
  Window::setViewPortSelectedWindow(width, height);
}

void Window::setViewPortSelectedWindow(const int width, const int height)
{
  glViewport(0, 0, width, height);
  Log(std::format("Changed window viewport to: {}, {}", width, height));
}

Window::Window(const WindowConstructor& params) : window(CreateWindow(params))
{
  Assert(window, "Window hasn't been created");

  glfwSetFramebufferSizeCallback(window, eventViewBufferChange);

  Log(std::format("Window {} has been created", params.windowTitle));
}

Window::~Window()
{
  glfwDestroyWindow(window);
  Log("Window has been destroyed");
}

GLFWwindow* Window::getWindow()
{
  return window;
}

void Window::use()
{
  glfwMakeContextCurrent(window);
}

void Window::close()
{
  constexpr int CLOSE_SIGNAL = 1;
  glfwSetWindowShouldClose(window, CLOSE_SIGNAL);
}

bool Window::shouldClose()
{
  return !static_cast<bool>(glfwWindowShouldClose(window));
}

void Window::swapBuffer()
{
  glfwSwapBuffers(window);
}

void Window::setKeyCallBack(GLFWkeyfun callBack)
{
  glfwSetKeyCallback(window, callBack);
}

void Window::clearSelectedWindow()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setClearColor(const Color& color)
{
  glClearColor(color.red, color.green, color.blue, color.alpha);
}

}  // namespace gl