#pragma once

#include <memory>
#include <vector>

#include "my_log.h"
#include "shareProgramContainer.hpp"
#include "shareBufferContainer.hpp"
#include "keysHandler.hpp"
#include "drawable.hpp"
#include "updatable.hpp"
#include "window.hpp"
#include "mesh.hpp"
#include "glfw.hpp"

namespace gl {
struct EngineConstructor : public virtual GLFW_Constructor, public virtual WindowConstructor {};

class Engine {
private:
  GLFW glfw;
  std::weak_ptr<Engine> engine;
  std::shared_ptr<Window> window;

  std::shared_ptr<KeysHandler> keyHandler;
  std::shared_ptr<ShareBufferContainer> shareBuffer;
  std::shared_ptr<ShareProgramContainer> shareProgram;

  std::vector<std::weak_ptr<IDrawable>> drawList;
  std::vector<std::weak_ptr<IUpdatable>> updateList;
  std::vector<std::shared_ptr<IGlObject>> objectList;

  Engine(EngineConstructor param);

public:
  Engine(const Engine&) = delete;
  Engine(Engine&&) = delete;
  Engine& operator=(const Engine&) = delete;
  Engine& operator=(Engine&&) = delete;
  Engine() = delete;

  ~Engine();

  void mainLoop();

  std::shared_ptr<Window> getWindow() const;
  std::shared_ptr<KeysHandler> getKeyHandler() const;
  std::shared_ptr<ShareBufferContainer> getShareBuffer() const;
  std::shared_ptr<ShareProgramContainer> getShareProgram() const;

  template <typename T>
  void insertObj()
  {
    T* object = new T(std::shared_ptr<Engine>(engine));
    auto shared = std::shared_ptr<T>(object);

    if constexpr (std::is_base_of<IUpdatable, T>::value) {
      auto updatable = std::dynamic_pointer_cast<IUpdatable>(shared);
      updateList.push_back(updatable);
    }
    if constexpr (std::is_base_of<IDrawable, T>::value) {
      auto drawable = std::dynamic_pointer_cast<IDrawable>(shared);
      drawList.push_back(drawable);
    }

    objectList.push_back(std::dynamic_pointer_cast<IGlObject>(shared));
  }

  static std::shared_ptr<Engine> GenerateEngine(EngineConstructor param = EngineConstructor());
  friend Engine GenerateEngine(EngineConstructor);
};

}  // namespace gl
