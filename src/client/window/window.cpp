#include <iostream>

#include "window.hpp"

GLFWwindow* createWindow(const WindowParamConstructor p)
{
  GLFWwindow* win =
      glfwCreateWindow(p.windowWidth, p.windowHeight, p.windowTitle.c_str(),
                       p.monitorToFullScreen, p.windowToShareResource);

  return win;
}

Window::Window(const WindowParamConstructor param) : win(createWindow(param))
{
  std::cout << "trying to create window\n";

  if (win == nullptr) {
    throw "Failed to create window\n";
  }
}

Window::~Window()
{
  std::cout << "Window destroy\n";
  glfwDestroyWindow(win);
}

void Window::clear()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setClearColor(Color c)
{
  glClearColor(c.red, c.green, c.blue, c.alpha);
}

void Window::select()
{
  glfwMakeContextCurrent(win);
}

void Window::swapBuffer()
{
  glfwSwapBuffers(win);
}

void Window::close()
{
  glfwSetWindowShouldClose(win, 1);
}

bool Window::shouldClose()
{
  return !glfwWindowShouldClose(win);
}

int Window::getKey(int key)
{
  return glfwGetKey(win, key);
}

void Window::viewPort(const int width, const int height)
{
  glViewport(0, 0, width, height);
  glfwSetFramebufferSizeCallback(win, Window::viewPortChange);
}

void Window::viewPortChange(GLFWwindow* window,
                            const int width,
                            const int height)
{
  std::cout << "window size change\n";
  glViewport(0, 0, width, height);
}