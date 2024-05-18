#pragma once
namespace gl {
class Position2d {
public:
  float x;
  float y;

  constexpr Position2d(const float& x, const float& y) : x(x), y(y) {}
};
}  // namespace gl
