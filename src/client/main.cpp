#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

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
    // init glfw
    GLFW glfw;
    // create window
    Window window;

    // select window
    window.select();
    // use glad
    gladLoadGL();
    // use full viewport context
    window.setFullViewPort(&window);

    // create program
    ShaderProgram program;
    {
      // create vertex shader
      Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER);
      // create fragment shade
      Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
      // attach shaders to program
      program.attach(&vertexShader);
      program.attach(&fragmentShader);
    }
    program.link();

    Triangle t;

    while (window.shouldClose()) {
      window.setClearColor(0.07f, 0.13f, 0.17f, 1.0f);

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