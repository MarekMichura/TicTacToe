#include "vao.hpp"
#include <GL/gl.h>
#include <iostream>

namespace gl {

VAO::VAO() : ID(genVAO())
{
  std::cout << "VAO has been created: " << ID << "\n";
}

VAO::~VAO()
{
  glDeleteVertexArrays(1, &ID);
  std::cout << "VAO has been deleted: " << ID << "\n";
}

GLuint VAO::genVAO()
{
  GLuint vao;
  glGenVertexArrays(1, &vao);
  return vao;
}

void VAO::use() const
{
  glBindVertexArray(ID);
}

void VAO::lose()
{
  glBindVertexArray(0);
}

void VAO::makePointer(  //
    const GLuint& index,
    const GLint& varCount,
    const GLenum& type,
    const GLboolean& isInt,
    const GLsizei& bytes) const
{
  glVertexAttribPointer(index, varCount, type, isInt, bytes, nullptr);
  glEnableVertexAttribArray(index);
}

}  // namespace gl