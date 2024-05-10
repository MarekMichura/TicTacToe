#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include <vector>

#include "window.hpp"
#include "glfw.hpp"

#include "engineParam.h"

class Engine {
public:
  GLFW glfw;
  Window window;
  std::vector<std::shared_ptr<StoragePipeline>> pipelines;

public:
  Engine(EngineParamConstructor param);

  void setBgColor(Color color = COLORS::BG);

  size_t createPipeline(EngineCreatePipeline param);

  void bindPipeline(size_t ID);

  void mainLoop();

private:
  static void errorCallBack(int errorCode, const char* message);
};

#endif