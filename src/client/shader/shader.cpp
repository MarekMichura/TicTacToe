#include <iostream>

#include "shader.hpp"

Shader::Shader(const char* source, const GLenum type)
    : ID(glCreateShaderProgramv(type, 1, &source))
{
  std::cout << "Create shader\n";
}

Shader::~Shader()
{
  std::cout << "Delete shader\n";
  glDeleteShader(ID);
}

GLuint Shader::getID() const
{
  return ID;
}