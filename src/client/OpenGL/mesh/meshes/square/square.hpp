#pragma once

#include <memory>
#include "mesh.hpp"
#include "program.hpp"
#include "squareData.h"
#include "vbo.hpp"

namespace gl {
class Square : public Mesh {
private:
  std::shared_ptr<Program> program;

  VAO vao;
  std::shared_ptr<VBO> vbo;
  std::shared_ptr<VBO> ebo;

public:
  Square(const Square&) = delete;
  Square(Square&&) = delete;
  Square& operator=(const Square&) = delete;
  Square& operator=(Square&&) = delete;

  Square();
  ~Square() override;

  void draw() override;
};
}  // namespace gl