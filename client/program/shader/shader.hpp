#pragma once

#include <sys/types.h>
#include <string>

#include "shaderType.h"

namespace gl {
class Shader {
private:
  const uint ID;

public:
  Shader(Shader&&) = delete;
  Shader& operator=(const Shader&) = delete;
  Shader& operator=(Shader&&) = delete;
  Shader(const Shader&) = delete;

  Shader(const std::string& source, const SHADER_TYPE type);
  ~Shader();

  uint getID() const;
  static Shader compileFromFile(const std::string& file, const SHADER_TYPE type);
};
}  // namespace gl