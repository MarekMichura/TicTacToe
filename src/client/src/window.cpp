#include "window.hpp"
#include <iostream>

Window::Window(const unsigned int width,
               const unsigned int height,
               const char* title,
               GLFWmonitor* monitor,
               Window* win)
    : width(width), height(height)
{
  window = glfwCreateWindow(width, height, title, monitor,
                            win == nullptr ? nullptr : win->window);

  if (window == NULL) {
    throw "Failed to create window\n";
  }
}

Window::~Window()
{
  glfwDestroyWindow(window);
}

void Window::clear()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::select()
{
  glfwMakeContextCurrent(window);
}

void Window::setClearColor(float red, float green, float blue, float alpha)
{
  glClearColor(red, green, blue, alpha);
}

void Window::setFullViewPort()
{
  glViewport(0, 0, width, height);
}

bool Window::shouldClose()
{
  return !glfwWindowShouldClose(window);
}

void Window::swapBuffer()
{
  glfwSwapBuffers(window);
}

int Window::getKey(int key)
{
  return glfwGetKey(window, key);
}

void Window::close()
{
  glfwSetWindowShouldClose(window, 1);
}