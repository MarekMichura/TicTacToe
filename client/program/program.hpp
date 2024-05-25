#pragma once

#include <memory>
#include <string>

#include "buffer.hpp"
#include "parameter.h"

namespace gl {
class Program {
private:
  const uint ID;

public:
  Program(const Program&) = delete;
  Program(Program&&) = delete;
  Program& operator=(const Program&) = delete;
  Program& operator=(Program&&) = delete;

  Program(const std::string& nameOfVertexShader, const std::string& nameOfFragmentShader);
  ~Program();

  void use() const;
  uint getID() const;
  std::string getInfoLog() const;
  int getParameter(PARAMETER_TYPE type) const;
  void connectUBO(const std::string& nameOfUBO, const std::shared_ptr<Buffer> ubo, const uint uboLP) const;
};
}  // namespace gl