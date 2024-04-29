#include "shader.hpp"

Shader::Shader(const char* source, const GLenum type, const std::string text)
    : ID(glCreateShaderProgramv(type, 1, &source))
{
  std::string log;
  log.resize(1024);

  glGetProgramInfoLog(ID, log.size(), nullptr, &log.front());
  std::cout << text << log;
  // glShaderSource(ID, 1, &source, NULL);
  // glCompileShader(ID);
}

Shader::~Shader()
{
  glDeleteShader(ID);
}

GLuint Shader::getID()
{
  return ID;
}