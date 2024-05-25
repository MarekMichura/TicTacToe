#include <format>
#include <fstream>
#include <sstream>
#include <string>

#include "shader/shader.hpp"
#include "my_log.h"

namespace gl {
Shader::Shader(const std::string& source, const SHADER_TYPE type) : ID(glCreateShader((uint)type))
{
  const auto* c_source = source.c_str();
  glShaderSource(ID, 1, &c_source, nullptr);
  glCompileShader(ID);

  Log(std::format("Created shader id: {}", ID));
}

Shader::~Shader()
{
  Log(std::format("Deleted shader id: {}", ID));
  glDeleteShader(ID);
}

uint Shader::getID() const
{
  return ID;
}

Shader Shader::compileFromFile(const std::string& fileName, const SHADER_TYPE type)
{
  std::ifstream file("Shaders/" + fileName);
  std::stringstream shaderData;
  shaderData << file.rdbuf();
  std::string data = shaderData.str();
  file.close();

  return Shader(data, type);
}
}  // namespace gl