#ifndef VertexArray_HPP
#define VertexArray_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "vertexBuffer.hpp"

class VertexArray {
private:
  GLuint ID;
  const unsigned int size;

public:
  VertexArray(const unsigned int size);
  ~VertexArray();

  void format(const unsigned id,
              const unsigned int size,
              const VertexBuffer* buffer);
  void bind();
};

#endif