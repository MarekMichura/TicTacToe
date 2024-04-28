#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
private:
  int width;
  int height;

public:
  GLFWwindow* window;
  Window(int width = 1200, int height = 600, std::string title = "Window title") {
    this->width = width;
    this->height = height;
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL) {
      throw "Failed to create window\n";
    }
  }

  ~Window() { glfwDestroyWindow(window); }

  void select() { glfwMakeContextCurrent(window); }

  void swapBuffer() { glfwSwapBuffers(window); }

  bool shouldClose() { return !glfwWindowShouldClose(window); }

  static void setFullViewPort(Window* window) { glViewport(0, 0, window->width, window->height); }

  static void setClearColor(float red, float green, float blue, float alpha) { glClearColor(red, green, blue, alpha); }

  static void clear() { glClear(GL_COLOR_BUFFER_BIT); }
};
