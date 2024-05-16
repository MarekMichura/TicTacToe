#pragma once

#include <memory>
#include <vector>
#include "program.hpp"
#include "staticContainer/programEnum.h"
#include "vao.hpp"
#include "vbo.hpp"

namespace gl {
class Mesh {
protected:
  std::shared_ptr<Program> program;

  VAO vao;
  std::vector<std::shared_ptr<VBO>> vbo;

public:
  Mesh(PROGRAM_NAME name);
  ~Mesh();

  virtual void draw() const;
};
}  // namespace gl