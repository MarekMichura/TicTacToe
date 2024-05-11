#ifndef ENGINE_PARAM_H
#define ENGINE_PARAM_H

#include "vertexBuffer.hpp"
#include "vertexArray.hpp"
#include "program.hpp"
#include "shader.hpp"

#include "windowParam.h"
#include "glfwParam.h"

struct EngineParamConstructor {
  WindowParamConstructor windowParam;
  GlfwParamConstructor glfwParam;
};

#endif