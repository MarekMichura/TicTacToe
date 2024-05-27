#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <functional>
#include <format>
#include <memory>

#include "timeUBO.h"
#include "window.hpp"
#include "engine.hpp"
#include "color.hpp"
#include "glfw.hpp"

#include "fps.hpp"
#include "my_assert.h"
#include "my_log.h"

namespace gl {
std::shared_ptr<std::function<void()>> tmp;

Engine::Engine(EngineConstructor param)
    : glfw((GLFW_Constructor)param),
      window(std::make_shared<Window>(param)),
      keyHandler(std::make_shared<KeysHandler>(window)),
      shareBuffer(std::make_shared<ShareBufferContainer>()),
      shareProgram(std::make_shared<ShareProgramContainer>())
{
  window->use();
  gladLoadGL();
  Window::setClearColor(COLORS::COLOR_CLEAR);
  glfwSwapInterval(0);

  glfwSetErrorCallback([](const int errorCode, const char* message) {
    Assert(false, std::format("GLFW error code: {}, message: {}", errorCode, message));
    abort();
  });

  Log("Enable transparency in fragment shaders");
  glad_glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  time = shareBuffer->getBuffer(SHARE_BUFFER::TIME);
  Log("Engine has been created");
}

Engine::~Engine()
{
  Log("Engine will be destroyed");
}

void Engine::mainLoop()
{
  FpsDefine;
  double prevTime = 0;

  while (window->shouldClose()) {
    double currentTime = glfwGetTime();
    auto bufferTime = std::make_unique<TimeUBO>(currentTime, currentTime - prevTime);
    time->updateData(bufferTime.get(), sizeof(TimeUBO), 0);
    prevTime = currentTime;
    FpsMeasure(currentTime);

    Window::clearSelectedWindow();
    for (const auto& draw : drawList) {
      if (auto lock = draw.lock()) {
        lock->draw();
      }
    }

    window->swapBuffer();
    glfwPollEvents();
  }
}

std::shared_ptr<KeysHandler> Engine::getKeyHandler() const
{
  return keyHandler;
}
std::shared_ptr<Window> Engine::getWindow() const
{
  return window;
}
std::shared_ptr<ShareBufferContainer> Engine::getShareBuffer() const
{
  return shareBuffer;
}
std::shared_ptr<ShareProgramContainer> Engine::getShareProgram() const
{
  return shareProgram;
}

std::shared_ptr<Engine> Engine::GenerateEngine(EngineConstructor param)
{
  Engine* engine = new Engine(param);
  auto shared = std::shared_ptr<Engine>(engine);
  engine->engine = shared;

  return shared;
}
}  // namespace gl
