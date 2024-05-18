#include "vbo.hpp"
#include <X11/X.h>
#include <iostream>

namespace gl {

VBO::~VBO()
{
  std::cout << "VBO will be deleted: " << ID << "\n";
  glDeleteBuffers(1, &ID);
}

void VBO::use() const
{
  glBindBuffer(bufferType, ID);
}

GLuint VBO::genVBO()
{
  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  return vbo;
}

}  // namespace gl
