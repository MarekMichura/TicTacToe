#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "shader.hpp"

namespace gl {
Shader::Shader(const std::string& source, const GLenum& type)
    : ID(glCreateShader(type))
{
  const char* c_source = source.c_str();
  glShaderSource(ID, 1, &c_source, nullptr);
  glCompileShader(ID);

  std::cout << "Shader has been created and compiled: " << ID << "\n";
}

Shader::~Shader()
{
  glDeleteShader(ID);
  std::cout << "Shader has been destroyed: " << ID << "\n";
}

GLuint Shader::getID() const
{
  return ID;
}

Shader Shader::createFromFile(const std::string fileName, const GLenum type)
{
  std::ifstream file("Shader/" + fileName);
  std::stringstream buffer;
  buffer << file.rdbuf();

  return Shader(buffer.str(), type);
}
}  // namespace gl