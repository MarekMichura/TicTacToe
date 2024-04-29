#include "vertexArray.hpp"

VertexArray::VertexArray(const unsigned int size) : size(size)
{
  glCreateVertexArrays(size, &ID);
}

VertexArray::~VertexArray()
{
  glDeleteVertexArrays(size, &ID);
}

void VertexArray::format(const unsigned id,
                         const unsigned int size,
                         VertexBuffer* buffer)
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