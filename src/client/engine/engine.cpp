#include <iostream>
#include <memory>
#include <array>

#include "vertexBuffer.hpp"
#include "vertexArray.hpp"
#include "window.hpp"
#include "engine.hpp"
#include "glfw.hpp"

#include "engineParam.h"
#include "triangle.h"

Engine::Engine(EngineParamConstructor p)
    : glfw(p.glfwParam), window(p.windowParam)
{
  window.select();
  gladLoadGL();

  glfwSetErrorCallback(errorCallBack);
  window.viewPort(p.windowParam.windowWidth, p.windowParam.windowHeight);
}

void Engine::setBgColor(const Color c)
{
  window.setClearColor(c);
}

void Engine::errorCallBack(int code, const char* mess)
{
  // const GLubyte* tmp = glGetString(GL_VENDOR);
  std::cout << code << " -:- " << mess << "\n";
  throw mess;
}

size_t Engine::createProgram(const char* sourceVertexShader, const char* sourceFragmentShader)
{
  Shader vertex(sourceVertexShader, GL_VERTEX_SHADER);
  Shader fragment(sourceFragmentShader, GL_FRAGMENT_SHADER);
  auto program = std::make_shared<Program>();

  program->attach(&vertex);
  program->attach(&fragment);
  program->afterAttach();

  program->sendData(myFirstObj, sizeof(myFirstObj));

  programs.push_back(program);
  return programs.size() - 1;
}

void Engine::bindProgram(size_t ID)
{

}

void Engine::mainLoop()
{
  while (window.shouldClose()) {
    if (window.getKey(GLFW_KEY_Q) == GLFW_PRESS)
      window.close();

    window.clear();

    programs[0]->bind();
    programs[0]->bindVAO();

    glDrawArrays(GL_TRIANGLES, 0, 3);
    window.swapBuffer();

    glfwPollEvents();
  }
}
