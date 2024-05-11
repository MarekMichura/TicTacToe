#include <iostream>

#include "shader.hpp"

Shader::Shader(const char* source, const GLenum type)
    : ID(glCreateShader(type))
{
  glShaderSource(ID, 1, &source, NULL);
  glCompileShader(ID);
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