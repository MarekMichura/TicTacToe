#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.hpp"

class PipeLine {
private:
  GLuint ID;
  const GLsizei size;
  /* data */
public:
  PipeLine(const GLsizei size);
  ~PipeLine();

  void attach(const GLbitfield stage, const Shader* shader) const;
  void bind() const;
};

#endif