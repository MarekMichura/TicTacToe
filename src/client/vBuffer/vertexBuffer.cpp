#include "vertexBuffer.hpp"
#include <iostream>

VertexBuffer::VertexBuffer(const unsigned int size) : size(size)
{
  std::cout << "Create VertexBuffer\n";
  glCreateBuffers(size, &ID);
}

VertexBuffer::~VertexBuffer()
{
  std::cout << "Delete VertexBuffer\n";
  glDeleteBuffers(size, &ID);
}

void VertexBuffer::sendData(const float data[], const unsigned int size)
{
  glNamedBufferStorage(ID, size, data, 0);
}

GLuint VertexBuffer::getID() const
{
  return ID;
}