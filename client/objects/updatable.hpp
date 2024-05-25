#pragma once

#include "mesh.hpp"

namespace gl {
class IUpdatable : public virtual IGlObject {
private:
  bool updatable = true;

public:
  virtual void tickUpdate() = 0;
};
}  // namespace gl