#pragma once

#include <memory>
#include <vector>
#include "glfw.hpp"
#include "mesh.hpp"
#include "program.hpp"
#include "window.hpp"
#include "engineConstructor.h"

namespace gl {

class Engine {
private:
  GLFW glfw;
  Window window;
  std::vector<std::unique_ptr<Mesh>> meshes;

public:
  Engine(Engine&&) = delete;
  Engine& operator=(const Engine&) = delete;
  Engine& operator=(Engine&&) = delete;
  Engine(const Engine&) = delete;

  Engine(const EngineConstructor& params = EngineConstructorDefault);
  ~Engine();

  void mainLoop();
  void loadProgram(const std::shared_ptr<Program> program);
  void loadMesh(std::unique_ptr<Mesh> mesh);

private:
  static void errorCallBack(int errorCode, const char* message);
};
}  // namespace gl