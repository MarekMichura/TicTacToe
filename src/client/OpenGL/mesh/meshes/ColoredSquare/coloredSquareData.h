#include <array>
#include <memory>
#include "color.hpp"
#include "position2d.hpp"
#include "triangleID.hpp"
#include "vbo.hpp"

namespace gl {
struct ColPos {
  Position2d pos;
  Color col;
};
constexpr static std::array<ColPos, 4> COLORED_SQUARE_POINTS = {
    ColPos{Position2d(-.6f, .3f), COLOR::COLOR_BG},     // left top
    ColPos{Position2d(-.6f, -.3f), COLOR::COLOR_RED},   // left bottom
    ColPos{Position2d(.6f, -.3f), COLOR::COLOR_GREEN},  // right bottom
    ColPos{Position2d(.6f, .3f), COLOR::COLOR_BLUE},    // right top
};

inline std::shared_ptr<VBO> VBO_COLORED_SQUARE_POINTS()
{
  auto* ptr = new VBO(GL_ARRAY_BUFFER, COLORED_SQUARE_POINTS, sizeof(COLORED_SQUARE_POINTS), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}

constexpr static std::array<TriangleID, 2> COLORED_SQUARE_INDEX = {
    TriangleID(0, 1, 2),  //
    TriangleID(0, 2, 3)   //
};

inline std::shared_ptr<VBO> VBO_COLORED_SQUARE_INDEX()
{
  auto* ptr = new VBO(GL_ELEMENT_ARRAY_BUFFER, COLORED_SQUARE_INDEX, sizeof(COLORED_SQUARE_INDEX), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}
}  // namespace gl