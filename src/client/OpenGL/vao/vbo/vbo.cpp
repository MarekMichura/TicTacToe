#include "vbo.hpp"
#include <X11/X.h>
#include <iostream>
#include "vao.hpp"

namespace gl {

template <typename T>
VBO::VBO(const VAO& vao, const GLenum& bufferType, const T* data, const size_t& data_size, const GLenum& usageType)
    : ID(genVBO()), bufferType(bufferType)
{
  vao.use();
  glBindBuffer(bufferType, ID);
  glBufferData(bufferType, data_size, data, usageType);
  std::cout << "VBO has been created: " << ID << "\n";
}

template <typename T>
VBO::VBO(const GLenum& bufferType, const T* data, const size_t& data_size, const GLenum& usageType)
    : ID(genVBO()), bufferType(bufferType)
{
  VAO::lose();
  glBindBuffer(bufferType, ID);
  glBufferData(bufferType, data_size, data, usageType);
  std::cout << "VBO has been created: " << ID << "\n";
}

template VBO::VBO(const VAO& vao,
                  const GLenum& bufferType,
                  const float* data,
                  const size_t& data_size,
                  const GLenum& usageType);

template VBO::VBO(const GLenum& bufferType, const float* data, const size_t& data_size, const GLenum& usageType);

template VBO::VBO(const GLenum& bufferType, const unsigned int* data, const size_t& data_size, const GLenum& usageType);

template VBO::VBO(const VAO& vao,
                  const GLenum& bufferType,
                  const unsigned int* data,
                  const size_t& data_size,
                  const GLenum& usageType);

VBO::~VBO()
{
  std::cout << "VBO: " << ID << " has been deleted: " << ID << "\n";
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
