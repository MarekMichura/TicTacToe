#include "vao.hpp"
#include <GL/gl.h>
#include <cstddef>
#include <iostream>

namespace gl {

VAO::VAO() : ID(genVAO())
{
  std::cout << "VAO has been created: " << ID << "\n";
}

VAO::~VAO()
{
  std::cout << "VAO will be deleted: " << ID << "\n";
  glDeleteVertexArrays(1, &ID);
}

GLuint VAO::genVAO()
{
  GLuint vao = 0;
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
    const GLuint& indexOfVertexArray,
    const GLint& howManyVariablesPerVertex,
    const GLenum& typeOfVariables,
    const GLboolean& isDataInt,
    const GLsizei& howManyBytesFromDataPerVertex,
    const void* offset)
{
  glVertexAttribPointer(indexOfVertexArray, howManyVariablesPerVertex, typeOfVariables,  //
                        isDataInt, howManyBytesFromDataPerVertex, offset);
  glEnableVertexAttribArray(indexOfVertexArray);
}

}  // namespace gl