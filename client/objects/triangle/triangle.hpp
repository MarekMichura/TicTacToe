#pragma once

#include <memory>

#include "buffer.hpp"
#include "drawable.hpp"
#include "engine.hpp"
#include "program.hpp"
#include "vao.hpp"

namespace gl {
class Triangle : public IDrawable {
private:
  std::shared_ptr<Program> program;

  VAO vao;
  std::shared_ptr<Buffer> vbo;

public:
  Triangle(const Triangle&) = delete;
  Triangle(Triangle&&) = delete;
  Triangle& operator=(const Triangle&) = delete;
  Triangle& operator=(Triangle&&) = delete;

  Triangle(std::weak_ptr<Engine> engine);

  void draw();
};
}  // namespace gl