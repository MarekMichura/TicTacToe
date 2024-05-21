#pragma once

#include <memory>
#include <string>
#include "glad/glad.h"
#include "vbo.hpp"

namespace gl {
class Program {
private:
  const GLuint ID;

public:
  Program(Program&&) = delete;
  Program& operator=(const Program&) = delete;
  Program& operator=(Program&&) = delete;
  Program(const Program&) = delete;

  Program(const std::string& nameOfVertexShader, const std::string& nameOfFragmentShader);
  ~Program();

  void combineUniform(const std::string& name, const std::shared_ptr<VBO> vbo, const GLuint lp) const;
  GLuint getID() const;
  void use() const;
};
}  // namespace gl
