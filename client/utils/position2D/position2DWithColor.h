#pragma once

#include "color.hpp"
#include "position2D.hpp"

namespace gl {
typedef struct Position2DWithColor {
  Position2D position;
  Color color;
} Position2DWithColor;
}  // namespace gl