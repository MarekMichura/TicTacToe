#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <memory>
#include "mesh.hpp"
#include "window.hpp"
#include "engine.hpp"
#include "glfw.hpp"
#include "square.hpp"

namespace gl {

Engine::Engine(const EngineConstructor& params)  //
    : glfw(params.glfwConstructor), window(params.windowConstructor)
{
  window.select();
  gladLoadGL();
  Window::setClearColor(params.windowBackgroundColor);
  Window::setViewPort(params.windowConstructor.windowWidth, params.windowConstructor.windowHeight);
  glfwSetErrorCallback(errorCallBack);

  glad_glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Engine::~Engine()
{
  std::cout << "Engine will be deleted\n";
}

void Engine::errorCallBack(int errorCode, const char* message)
{
  std::cout << errorCode << " -:- " << message << "\n";
  throw message;
}

void Engine::mainLoop()
{
  int press = 0;
  double time = glfwGetTime();
  int frame = 0;

  while (window.shouldClose()) {
    frame++;
    double t_time = glfwGetTime();
    press = (press > 0) ? press - 1 : press;
    if (t_time - time >= 1) {
      std::cout << "FPS: " << frame << "\n";
      frame = 0;
      time = glfwGetTime();
    }

    if (window.getKeyStatus(GLFW_KEY_Q) == GLFW_PRESS) {
      window.close();
    }
    if (window.getKeyStatus(GLFW_KEY_W) == GLFW_PRESS && !meshes.empty()) {
      meshes.clear();
    }

    if (window.getKeyStatus(GLFW_KEY_X) == GLFW_PRESS && press <= 0) {
      for (int i = 0; i < 100; i++) {
        loadMesh(std::move(std::make_unique<gl::Square>()));
      }
    }
    if (window.getKeyStatus(GLFW_KEY_Y) == GLFW_PRESS && press <= 0) {
      for (int i = 0; i < 100; i++) {
        loadMesh(std::move(std::make_unique<gl::Square2>()));
      }
    }

    Window::clearSelectedWindow();

    for (const auto& mesh : meshes) {
      mesh->draw();
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
