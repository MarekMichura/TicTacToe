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

  static void clear();
  static void setClearColor(Color color);
};

#endif  // !WINDOW_HPP