#include "vbo.hpp"
#include <iostream>

namespace gl {

VBO::~VBO()
{
  std::cout << "VBO will be deleted: " << ID << "\n";
  glDeleteBuffers(1, &ID);
}

GLuint VBO::getID() const
{
  return ID;
}

void VBO::use() const
{
  glBindBuffer(bufferType, ID);
}

void VBO::use(GLuint bindingPoint) const
{
  glBindBufferBase(bufferType, bindingPoint, ID);
}

void VBO::changeData(const long& offset, const long& size, const void* data)
{
  use();
  glBufferSubData(bufferType, offset, size, data);
}

GLuint VBO::genVBO()
{
  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  return vbo;
}

void VBO::lose()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

}  // namespace gl
