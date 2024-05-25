#pragma once

#include "mesh.hpp"

namespace gl {
class IDrawable : public virtual IGlObject {
private:
  bool drawable = true;

public:
  virtual void draw() = 0;
};
}  // namespace gl