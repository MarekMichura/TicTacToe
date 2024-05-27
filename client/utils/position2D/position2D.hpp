#pragma once

namespace gl {
class Position2D {
private:
  const float xComponent;
  const float yComponent;

public:
  Position2D(const Position2D&) = delete;
  Position2D(Position2D&&) = delete;
  Position2D& operator=(const Position2D&) = delete;
  Position2D& operator=(Position2D&&) = delete;
  ~Position2D() = default;

  Position2D(const float xComponent, const float yComponent);

  float getX() const;
  float geyY() const;

  Position2D copy() const;
};
}  // namespace gl