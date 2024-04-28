#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "OpenGl/GLFW.cpp"
#include "OpenGl/Obj/Triangle.cpp"
#include "OpenGl/Shader.cpp"
#include "OpenGl/Window.cpp"

#include "fragmentShader.h"
#include "vertexShader.h"

extern const char* fragmentShaderSource;
extern const char* vertexShaderSource;

int main() {
  try {
    GLFW glfw;
    Window window;

    // shader

    window.select();
    gladLoadGL();
    window.setFullViewPort(&window);
    window.setClearColor(1, 1, 1, 1);
    Window::clear();
    window.swapBuffer();
    // Shader shader;
    Shader vertexShader(fragmentShaderSource, GL_VERTEX_SHADER);
    Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    ShaderProgram program;
    program.attach(&vertexShader);
    program.attach(&fragmentShader);
    program.link();

    Triangle t;
    // GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // glCompileShader(vertexShader);

    while (window.shouldClose()) {
      window.clear();
      program.use();

      t.bind();
      glDrawArrays(GL_TRIANGLES, 0, 3);

      window.swapBuffer();

      glfwPollEvents();
    }
  } catch (std::string error) {
    std::cout << error << "\n";
  }
}
