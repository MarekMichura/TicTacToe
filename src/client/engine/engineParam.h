#ifndef ENGINE_PARAM_H
#define ENGINE_PARAM_H

#include "glfwParam.h"
#include "pipeline.hpp"
#include "shader.hpp"
#include "vertexArray.hpp"
#include "vertexBuffer.hpp"
#include "windowParam.h"

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