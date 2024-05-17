#pragma once

#include <string>
#include "glad/glad.h"

namespace gl {
class Shader {
private:
  const GLuint ID;

public:
  Shader(Shader&&) = delete;
  Shader& operator=(const Shader&) = delete;
  Shader& operator=(Shader&&) = delete;
  Shader(const Shader&) = delete;

  Shader(const std::string& source, const GLenum& type);
  ~Shader();

  GLuint getID() const;

  static Shader createFromFile(const std::string fileName, const GLenum type);
};
}  // namespace gl