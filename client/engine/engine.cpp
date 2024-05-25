#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <cstdlib>
#include <functional>
#include <unistd.h>
#include <memory>

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
    : glfw(param),
      window(std::make_shared<Window>(param)),
      keyHandler(std::make_shared<KeysHandler>(window)),
      shareBuffer(std::make_shared<ShareBufferContainer>()),
      shareProgram(std::make_shared<ShareProgramContainer>())
{
  window->use();
  gladLoadGL();
  Window::setClearColor(COLORS::COLOR_CLEAR);
  glfwSwapInterval(1);

  glfwSetErrorCallback([](const int errorCode, const char* message) {
    Assert(false, std::format("GLFW error code: {}, message: {}", errorCode, message));
    abort();
  });

  Log("Enable transparency in fragment shaders");
  glad_glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Log("Engine has been created");
}

Engine::~Engine()
{
  Log("Engine will be destroyed");
}

void Engine::mainLoop()
{
  FpsDefine;

  while (window->shouldClose()) {
    double currentTime = glfwGetTime();
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
