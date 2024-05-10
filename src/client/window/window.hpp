#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "color.h"
#include "windowParam.h"

class Window {
private:
  GLFWwindow* win;

public:
  Window(WindowParamConstructor param);
  ~Window();

  void select();
  void swapBuffer();
  void close();
  bool shouldClose();
  int getKey(int key);
  void viewPort(const int width, const int height);

  static void clear();
  static void setClearColor(Color color);

private:
  static void viewPortChange(GLFWwindow* window,
                             const int width,
                             const int height);
};

#endif  // !WINDOW_HPP