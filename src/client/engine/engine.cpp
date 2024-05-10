#include "vertexBuffer.hpp"
#include "vertexArray.hpp"
#include "engineParam.h"
#include "window.hpp"
#include "engine.hpp"
#include <memory>
#include "glfw.hpp"
#include <iostream>

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

size_t Engine::createPipeline(EngineCreatePipeline p)
{
  auto shared = new StoragePipeline(
      VertexArray(p.vertexArraySize),                      //
      VertexBuffer(p.vertexBufferSize),                    //
      PipeLine(p.pipelineSize),                            //
      Shader(p.fragmentShaderSource, GL_FRAGMENT_SHADER),  //
      Shader(p.vertexShaderSource, GL_VERTEX_SHADER)       //
  );

  VertexArray& vao = shared->vao;
  VertexBuffer& vbo = shared->vbo;

  vbo.sendData(p.pipelineData, p.pipelineDataSize);
  vao.format(0, &vbo);

  PipeLine& pipeline = shared->pipeline;
  Shader& vertex = shared->vertex;
  Shader& fragment = shared->fragment;
  pipeline.attach(GL_VERTEX_SHADER_BIT, &vertex);
  pipeline.attach(GL_FRAGMENT_SHADER_BIT, &fragment);

  pipelines.push_back(std::shared_ptr<StoragePipeline>(shared));
  return 0;
}

void Engine::bindPipeline(size_t ID)
{
  std::shared_ptr<StoragePipeline> storage = pipelines[ID];

  storage->pipeline.bind();
  storage->vao.bind();
}

void Engine::mainLoop()
{
  while (window.shouldClose()) {
    if (window.getKey(GLFW_KEY_Q) == GLFW_PRESS)
      window.close();

    window.clear();

    glDrawArrays(GL_TRIANGLES, 0, 3);
    window.swapBuffer();

    glfwPollEvents();
  }
}
