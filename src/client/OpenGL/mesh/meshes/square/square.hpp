#pragma once

#include "mesh.hpp"
#include "squareData.h"

namespace gl {
class Square : public Mesh {
public:
  Square(const Square&) = delete;
  Square(Square&&) = delete;
  Square& operator=(const Square&) = delete;
  Square& operator=(Square&&) = delete;

  Square();
  ~Square() override;

  void draw() const override;
};
}  // namespace gl