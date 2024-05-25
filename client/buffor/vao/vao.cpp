#include "glad/glad.h"

#include "vao.hpp"
#include <format>
#include "my_log.h"

namespace gl {
static uint generateVAO()
{
  uint vao = 0;
  glGenVertexArrays(1, &vao);
  return vao;
}

VAO::VAO() : ID(generateVAO())
{
  Log(std::format("Created VAO id: {}", ID));
};

VAO::~VAO()
{
  Log(std::format("Deleted VAO id: {}", ID));
  glDeleteVertexArrays(1, &ID);
}

void VAO::use() const
{
  glBindVertexArray(ID);
}

void VAO::unUse()
{
  glBindVertexArray(0);
}

void VAO::createAttributePointerToSelectedVAO(  //
    const uint index,
    const int howManyVariables,
    const GL_VARIABLE_TYPE variableType,
    const uchar normalized,
    const int sizeOfAttribute,
    const void* offset)
{
  glVertexAttribPointer(index, howManyVariables, (uint)variableType, normalized, sizeOfAttribute, offset);
  glEnableVertexAttribArray(index);
}
}  // namespace gl