#include <cassert>
#include <cstddef>
#include <iostream>
#include <memory>
#include "shader.hpp"
#include "program.hpp"
#include <GL/gl.h>

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

  assert(linkStatus != GL_FALSE);
  // if (linkStatus == GL_FALSE) {
  //   GLint logLength = 0;
  //   glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &logLength);

  //   auto log = std::make_unique<char>(static_cast<size_t>(logLength));
  //   glGetProgramInfoLog(ID, logLength, NULL, log.get());
  //   std::cout << "Error with linking program: " << log.get();
  // }

  std::cout << "Program has been created: " << ID << "\n";
}

Program::~Program()
{
  std::cout << "Program will be deleted: " << ID << "\n";
  glDeleteProgram(ID);
}

void Program::use() const
{
  glUseProgram(ID);
}

GLuint Program::getID() const
{
  return ID;
}

void Program::combineUniform(const std::string& name, const std::shared_ptr<VBO> vbo, const GLuint lp) const
{
  GLuint blockIndex = glGetUniformBlockIndex(ID, name.c_str());
  glUniformBlockBinding(ID, blockIndex, lp);
  glBindBufferBase(GL_UNIFORM_BUFFER, lp, vbo->getID());
}
}  // namespace gl
