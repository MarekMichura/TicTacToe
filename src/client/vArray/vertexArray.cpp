#include "vertexArray.hpp"
#include <iostream>

VertexArray::VertexArray(const GLsizei size) : size(size)
{
  std::cout << "Create VertexArray\n";
  glCreateVertexArrays(size, &ID);
}

VertexArray::~VertexArray()
{
  std::cout << "Delete VertexArray\n";
  glDeleteVertexArrays(size, &ID);
}

void VertexArray::format(const GLuint id, const VertexBuffer* buffer)
{
  glEnableVertexArrayAttrib(ID, id);
  glVertexArrayAttribFormat(ID, id, 2, GL_FLOAT, GL_FALSE, 0);
  glVertexArrayVertexBuffer(ID, id, buffer->getID(), 0, 2 * sizeof(float));
  glVertexArrayAttribBinding(ID, id, id);
}

void VertexArray::bind()
{
  glBindVertexArray(ID);
}