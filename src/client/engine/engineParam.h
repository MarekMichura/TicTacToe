#ifndef ENGINE_PARAM_H
#define ENGINE_PARAM_H

#include "vertexBuffer.hpp"
#include "vertexArray.hpp"
#include "pipeline.hpp"
#include "shader.hpp"

#include "windowParam.h"
#include "glfwParam.h"

struct EngineParamConstructor {
  WindowParamConstructor windowParam;
  GlfwParamConstructor glfwParam;
};

struct StoragePipeline {
  VertexArray vao;
  VertexBuffer vbo;
  PipeLine pipeline;

  Shader fragment;
  Shader vertex;
};

struct EngineCreatePipeline {
  const GLsizei pipelineSize = 1;
  const GLsizei vertexArraySize = 1;
  const GLsizei vertexBufferSize = 1;

  const char* fragmentShaderSource;
  const char* vertexShaderSource;

  const float* pipelineData;
  const GLsizei pipelineDataSize;
};

#endif