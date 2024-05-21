#pragma once

#include "mesh.hpp"
#include "program.hpp"
#include "triangleData.h"
#include "vao.hpp"

namespace gl {
class Triangle : public virtual Mesh {
private:
  std::shared_ptr<Program> program;

  VAO vao;
  std::shared_ptr<VBO> vbo;

public:
  Triangle(const Triangle&) = delete;
  Triangle(Triangle&&) = delete;
  Triangle& operator=(const Triangle&) = delete;
  Triangle& operator=(Triangle&&) = delete;

  Triangle();
  virtual ~Triangle();

  void draw() override;
};
}  // namespace gl