#include <cstddef>
#include <iostream>
#include <memory>
#include "shader.hpp"
#include "program.hpp"

namespace gl {
Program::Program(  //
    const std::string& nameOfVertexShader,
    const std::string& nameOfFragmentShader)
    : ID(glCreateProgram())
{
  auto vertexShader = Shader::createFromFile(nameOfFragmentShader, GL_FRAGMENT_SHADER);
  auto fragmentShader = Shader::createFromFile(nameOfVertexShader, GL_VERTEX_SHADER);

  glAttachShader(ID, vertexShader.getID());
  glAttachShader(ID, fragmentShader.getID());

  glLinkProgram(ID);
  GLint linkStatus = 0;
  glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);

  if (linkStatus == GL_FALSE) {
    GLint logLength = 0;
    glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &logLength);

    auto log = std::make_unique<char>(static_cast<size_t>(logLength));
    glGetProgramInfoLog(ID, logLength, NULL, log.get());
    std::cout << "Error with linking program: " << log.get();

    throw "Error with linking program";
  }

  std::cout << "Program has been created: " << ID << "\n";
}

Program::~Program()
{
  std::cout << "Program has been deleted: " << ID << "\n";
  glDeleteProgram(ID);
}

void Program::use() const
{
  glUseProgram(ID);
}
}  // namespace gl
