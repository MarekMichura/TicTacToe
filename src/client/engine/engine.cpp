#include "vertexBuffer.hpp"
#include "vertexArray.hpp"
#include "engineParam.h"
#include "window.hpp"
#include "engine.hpp"
#include <cstddef>
#include <memory>
#include "glfw.hpp"

Engine::Engine(EngineParamConstructor p)
    : window(p.windowParam), glfw(p.glfwParam)
{
  window.select();
  gladLoadGL();
}

void Engine::setBgColor(const Color c)
{
  window.setClearColor(c);
}

size_t Engine::createPipeline(EngineCreatePipeline p)
{
  auto shared = new StoragePipeline(                       //
      VertexArray(p.vertexArraySize),                      //
      VertexBuffer(p.vertexBufferSize),                    //
      PipeLine(p.pipelineSize),                            //
      Shader(p.fragmentShaderSource, GL_FRAGMENT_SHADER),  //
      Shader(p.vertexShaderSource, GL_VERTEX_SHADER)       //
  );

  VertexArray& vao = shared->vao;
  VertexBuffer& vbo = shared->vbo;

  vbo.sendData(p.pipelineData, p.pipelineDataSize);
  vao.format(0, 2, &vbo);

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
  auto storage = pipelines.back();

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
