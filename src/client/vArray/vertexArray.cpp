#include "vertexArray.hpp"
#include <iostream>

VertexArray::VertexArray(const unsigned int size) : size(size)
{
  std::cout << "Create VertexArray\n";
  glCreateVertexArrays(size, &ID);
}

VertexArray::~VertexArray()
{
  std::cout << "Delete VertexArray\n";
  glDeleteVertexArrays(size, &ID);
}

void VertexArray::format(const unsigned id,
                         const unsigned int size,
                         const VertexBuffer* buffer)
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