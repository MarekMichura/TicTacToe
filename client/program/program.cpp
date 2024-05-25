#include <glad/glad.h>

#include <sys/types.h>
#include <format>
#include <string>
#include <vector>

#include "program.hpp"
#include "shader.hpp"
#include "parameter.h"
#include "my_assert.h"
#include "my_log.h"

namespace gl {
Program::Program(const std::string& nameOfVertexShader, const std::string& nameOfFragmentShader) : ID(glCreateProgram())
{
  Shader vertex = Shader::compileFromFile(nameOfVertexShader, SHADER_TYPE::VERTEX);
  Shader fragment = Shader::compileFromFile(nameOfFragmentShader, SHADER_TYPE::FRAGMENT);

  glAttachShader(ID, vertex.getID());
  glAttachShader(ID, fragment.getID());

  glLinkProgram(ID);

  getInfoLog();
  //  Assert(getParameter(PARAMETER_TYPE::LINK) != GL_FALSE,
  //   std::format("Shader id: {}, had a problem during creation\n {}", ID, getInfoLog()));
  Log(std::format("Created Program id: {}", ID));
}

Program::~Program()
{
  Log(std::format("Deleted Program id: {}", ID));
  glDeleteProgram(ID);
}

std::string Program::getInfoLog() const
{
  if (getParameter(PARAMETER_TYPE::LINK) == GL_FALSE) {
    int logLength = getParameter(PARAMETER_TYPE::INFO_LENGTH);
    auto log = std::make_unique<char>(static_cast<size_t>(logLength));
    glGetProgramInfoLog(ID, logLength, nullptr, log.get());
    Assert(false, std::string(log.get()));
  }
  return "";
}

int Program::getParameter(PARAMETER_TYPE type) const
{
  int data = -1;
  glGetProgramiv(ID, (uint)type, &data);
  return data;
}

void Program::use() const
{
  glUseProgram(ID);
}

uint Program::getID() const
{
  return ID;
}

void Program::connectUBO(const std::string& nameOfUBO, const std::shared_ptr<Buffer> ubo, const uint uboLP) const
{
  uint index = glGetUniformBlockIndex(ID, nameOfUBO.c_str());
  glUniformBlockBinding(ID, index, uboLP);
  glBindBufferBase((uint)BUFFER_TYPE::UBO, uboLP, ubo->getID());
}

}  // namespace gl