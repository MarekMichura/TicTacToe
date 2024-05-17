#pragma once

#include <string>
#include "glad/glad.h"

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

  void use() const;
};
}  // namespace gl
