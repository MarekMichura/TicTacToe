#include <iostream>

#include "vertexBuffer.hpp"

VertexBuffer::VertexBuffer(const GLsizei size) : size(size)
{
  std::cout << "Create VertexBuffer\n";
  glCreateBuffers(size, &ID);
}

VertexBuffer::~VertexBuffer()
{
  std::cout << "Delete VertexBuffer\n";
  glDeleteBuffers(size, &ID);
}

void VertexBuffer::sendData(const float data[], const GLsizei size)
{
  glNamedBufferStorage(ID, size, data, 0);
}

GLuint VertexBuffer::getID() const
{
  return ID;
}