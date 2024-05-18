#pragma once
#include "mesh.hpp"

namespace gl {
class ColoredSquare : public Mesh {
public:
  ColoredSquare(const ColoredSquare&) = delete;
  ColoredSquare(ColoredSquare&&) = delete;
  ColoredSquare& operator=(const ColoredSquare&) = delete;
  ColoredSquare& operator=(ColoredSquare&&) = delete;

  ColoredSquare();
  ~ColoredSquare() override;

  void draw() const override;
};
}  // namespace gl