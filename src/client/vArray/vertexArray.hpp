#ifndef VertexArray_HPP
#define VertexArray_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vertexBuffer.hpp"

class VertexArray {
private:
  GLuint ID;
  const GLsizei size;

public:
  VertexArray(const GLsizei size);
  ~VertexArray();

  void format(const GLuint id, const VertexBuffer* buffer);
  void bind();
};

#endif