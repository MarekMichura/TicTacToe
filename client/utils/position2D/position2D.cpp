#include "position2D.hpp"

namespace gl {
Position2D::Position2D(const float xComponent, const float yComponent) : xComponent(xComponent), yComponent(yComponent)
{
}

Position2D Position2D::copy() const
{
  return Position2D(xComponent, yComponent);
}
}  // namespace gl