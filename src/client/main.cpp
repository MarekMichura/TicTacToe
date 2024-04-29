#include <iostream>
#include "src/glfw.hpp"
#include "src/shader.hpp"
#include "src/vertexArray.hpp"
#include "src/vertexBuffer.hpp"
#include "src/window.hpp"

#include "fragmentShader.h"
// #include "obj/myFirstObj.cpp"
#include "src/pipeline.hpp"
#include "vertexShader.h"
extern const char* fragmentShaderSource;
extern const char* vertexShaderSource;
const float myFirstObj[]{
    0.0f,  0.5f,   //
    0.5f,  -0.5f,  //
    -0.5f, -0.5f,  //
    -0.5f, 0.0f    //
};

int main()
{
  try {
    GLFW glfw(4, 5);
    Window window(1920, 1080, "Window tittle");
    window.select();

    gladLoadGL();
    window.setClearColor(0.1f, 0.1f, 0.1f, 1.f);

    VertexArray vao(1);
    VertexBuffer vbo(1);
    vbo.sendData(myFirstObj, sizeof(myFirstObj));
    vao.format(0, 2, &vbo);

    PipeLine pipeline(1);
    Shader vertex(vertexShaderSource, GL_VERTEX_SHADER, "vertex: ");
    Shader fragment(fragmentShaderSource, GL_FRAGMENT_SHADER, "fragment: ");
    pipeline.attach(GL_VERTEX_SHADER_BIT, &vertex);
    pipeline.attach(GL_FRAGMENT_SHADER_BIT, &fragment);

    pipeline.bind();
    vao.bind();

    while (window.shouldClose()) {
      if (window.getKey(GLFW_KEY_Q) == GLFW_PRESS)
        window.close();

      window.clear();

      glDrawArrays(GL_TRIANGLES, 0, 3);
      window.swapBuffer();

      glfwPollEvents();
    }
  }
  catch (std::string error) {
    std::cout << error << "\n";
    return -1;
  }
}