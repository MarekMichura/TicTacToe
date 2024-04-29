#include "vertexBuffer.hpp"

VertexBuffer::VertexBuffer(const unsigned int size) : size(size)
{
  glCreateBuffers(size, &ID);
}

VertexBuffer::~VertexBuffer()
{
  glDeleteBuffers(size, &ID);
}

void VertexBuffer::sendData(const float data[], const unsigned int size)
{
  glNamedBufferStorage(ID, size, data, 0);
}

GLuint VertexBuffer::getID()
{
  return ID;
}