#pragma once
#include <memory>
#include "mesh.hpp"
#include "program.hpp"
#include "vao.hpp"
#include "vbo.hpp"

namespace gl {
class ColoredSquare : public virtual Mesh {
private:
  std::shared_ptr<Program> program;

  VAO vao;
  std::shared_ptr<VBO> vbo;
  std::shared_ptr<VBO> ebo;
  std::shared_ptr<VBO> ubo;

public:
  ColoredSquare(const ColoredSquare&) = delete;
  ColoredSquare(ColoredSquare&&) = delete;
  ColoredSquare& operator=(const ColoredSquare&) = delete;
  ColoredSquare& operator=(ColoredSquare&&) = delete;

  ColoredSquare();
  ~ColoredSquare() override;

  void draw() override;
};
}  // namespace gl