#include <iostream>
#include <memory>
#include "mesh.hpp"
#include "program.hpp"
#include "window.hpp"
#include "engine.hpp"
#include "glfw.hpp"

namespace gl {

Engine::Engine(const EngineConstructor& params)  //
    : glfw(params.glfwConstructor), window(params.windowConstructor)
{
  window.select();
  gladLoadGL();
  Window::setClearColor(params.windowBackgroundColor);
  Window::setViewPort(params.windowConstructor.windowWidth,
                      params.windowConstructor.windowHeight);
  glfwSetErrorCallback(errorCallBack);

  glad_glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Engine::errorCallBack(int errorCode, const char* message)
{
  std::cout << errorCode << " -:- " << message << "\n";
  throw message;
}

void Engine::mainLoop()
{
  while (window.shouldClose()) {
    if (window.getKeyStatus(GLFW_KEY_Q) == GLFW_PRESS)
      window.close();
    Window::clearSelectedWindow();

    for (const auto& mesh : meshes) {
      mesh.get()->draw();
    }

    window.swapBuffer();
    glfwPollEvents();
  }
}

void Engine::loadMesh(std::unique_ptr<Mesh> mesh)
{
  meshes.push_back(std::move(mesh));
}
}  // namespace gl