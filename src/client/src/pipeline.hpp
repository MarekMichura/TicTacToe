#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.hpp"

class PipeLine {
private:
  GLuint ID;
  const unsigned int size;
  /* data */
public:
  PipeLine(const unsigned int size);
  ~PipeLine();

  void attach(GLbitfield stage, Shader* shader);
  void bind();
};

#endif