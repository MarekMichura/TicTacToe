#pragma once

#include <memory>

#include "buffer.hpp"
#include "drawable.hpp"
#include "engine.hpp"
#include "program.hpp"
#include "vao.hpp"

namespace gl {
class Rectangle : public IDrawable {
private:
  std::shared_ptr<Program> program;

  VAO vao;
  std::shared_ptr<Buffer> vbo;
  std::shared_ptr<Buffer> ebo;
  std::shared_ptr<Buffer> timeUBO;

public:
  Rectangle(const Rectangle&) = delete;
  Rectangle(Rectangle&&) = delete;
  Rectangle& operator=(const Rectangle&) = delete;
  Rectangle& operator=(Rectangle&&) = delete;

  Rectangle(std::shared_ptr<Engine> engine);
  virtual ~Rectangle() = default;

  void draw() override;
};
}  // namespace gl