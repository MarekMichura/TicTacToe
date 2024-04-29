#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
  GLFWwindow* window;
  const unsigned int width;
  const unsigned int height;

public:
  Window(const unsigned int width,
         const unsigned int height,
         const char* title,
         GLFWmonitor* monitor = nullptr,
         Window* win = nullptr);
  ~Window();

  void select();
  void swapBuffer();
  void close();
  bool shouldClose();
  void setFullViewPort();
  int getKey(int key);

  static void clear();
  static void setClearColor(float red,
                            float green,
                            float blue,
                            float alpha = 1.f);
};

#endif