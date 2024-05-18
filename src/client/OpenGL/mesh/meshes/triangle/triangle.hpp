#pragma once

#include "mesh.hpp"
#include "triangleData.h"

namespace gl {
class Triangle : public Mesh {
public:
  Triangle(const Triangle&) = delete;
  Triangle(Triangle&&) = delete;
  Triangle& operator=(const Triangle&) = delete;
  Triangle& operator=(Triangle&&) = delete;

  Triangle();
  ~Triangle() override;

  void draw() const override;
};
}  // namespace gl