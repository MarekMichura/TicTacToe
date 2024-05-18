#include <array>
#include <memory>
#include "position2d.hpp"
#include "triangleID.hpp"
#include "vbo.hpp"

namespace gl {
constexpr static std::array<Position2d, 4> SQUARE_POINTS = {
    Position2d(-.5f, .5f),   // left top
    Position2d(-.5f, -.5f),  // left bottom
    Position2d(.5f, -.5f),   // right bottom
    Position2d(.5f, .5f),    // right top
};

inline std::shared_ptr<VBO> VBO_SQUARE_POINTS()
{
  auto* ptr = new VBO(GL_ARRAY_BUFFER, SQUARE_POINTS, sizeof(SQUARE_POINTS), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}

constexpr static std::array<TriangleID, 2> SQUARE_INDEX = {
    TriangleID(0, 1, 2),  //
    TriangleID(0, 2, 3)   //
};

inline std::shared_ptr<VBO> VBO_SQUARE_INDEX()
{
  auto* ptr = new VBO(GL_ELEMENT_ARRAY_BUFFER, SQUARE_INDEX, sizeof(SQUARE_INDEX), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}
}  // namespace gl