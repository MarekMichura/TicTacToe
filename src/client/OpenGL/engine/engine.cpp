#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <cassert>
#include <iostream>
#include <memory>
#include "mesh.hpp"
#include "staticContainer/vboContainer.hpp"
#include "timeVBO.hpp"
#include "window.hpp"
#include "engine.hpp"
#include <GL/gl.h>
#include "glfw.hpp"

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

  uniform_time = VBOContainer::getVBO(VBO_NAME::TIME);
}

Engine::~Engine()
{
  std::cout << "Engine will be deleted\n";
}

void Engine::errorCallBack(int errorCode, const char* message)
{
  std::cout << errorCode << ": " << message << "\n";
  assert(false);
}

void Engine::setFullScreen(bool main)
{
  window.setFullScreen(main);
}

void timeControl(double& prevTime, int& frame)
{
  frame++;
  double time = glfwGetTime();
  double difference = time - prevTime;
  if (difference >= 1) {
    std::cout << "FPS: " << frame << "\n";
    frame = 0;
    prevTime = glfwGetTime();
  }
}

void Engine::mainLoop()
{
  int frame = 0;
  double time = glfwGetTime();
  double prevTime = glfwGetTime();

  while (window.shouldClose()) {
    timeControl(time, frame);
    prevTime = glfwGetTime();

    TimeDataVBO data{.currentTime = float(glfwGetTime()), .timeDifference = float(glfwGetTime() - prevTime)};
    uniform_time->changeData(0, sizeof(TimeDataVBO), &data);

    Window::clearSelectedWindow();
    if (window.getKeyStatus(GLFW_KEY_Q) == GLFW_PRESS) {
      window.close();
    }

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
