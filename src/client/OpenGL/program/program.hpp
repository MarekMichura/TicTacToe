#pragma once

#include <string>
#include "glad/glad.h"

namespace gl {
class Program {
private:
  const GLuint ID;

public:
  Program(const Program&) = delete;
  Program(const std::string& nameOfVertexShader,
          const std::string& nameOfFragmentShader);
  ~Program();

  void use() const;
};
}  // namespace gl