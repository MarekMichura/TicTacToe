#include <array>
#include <memory>
#include "position2d.hpp"
#include "vbo.hpp"

namespace gl {
constexpr static std::array<Position2d, 3> TRIANGLE_POINTS = {
    Position2d(.0f, .0f),  //
    Position2d(.0f, 1.f),  //
    Position2d(1.f, 1.f),  //
};

inline std::shared_ptr<VBO> VBO_TRIANGLE_POINTS()
{
  auto* ptr = new VBO(GL_ARRAY_BUFFER, TRIANGLE_POINTS, sizeof(TRIANGLE_POINTS), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}
}  // namespace gl