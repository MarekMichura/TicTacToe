#include <array>
#include <memory>
#include "vbo.hpp"

namespace gl {
constexpr static std::array<float, 10> SQUARE_POINTS = {
    -.5f, .5f,   // left top
    -.5f, -.5f,  // left bottom
    .5f,  -.5f,  // right bottom
    .5f,  .5f,   // right top
    1.f,  1.f,   // right top
};

inline std::shared_ptr<VBO> VBO_SQUARE_POINTS()
{
  auto* ptr = new VBO(GL_ARRAY_BUFFER, SQUARE_POINTS.data(), sizeof(SQUARE_POINTS), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}

constexpr static std::array<unsigned int, 6> SQUARE_INDEX = {
    0, 1, 2,  //
    0, 2, 3   //
};

inline std::shared_ptr<VBO> VBO_SQUARE_INDEX()
{
  auto* ptr = new VBO(GL_ELEMENT_ARRAY_BUFFER, SQUARE_INDEX.data(), sizeof(SQUARE_INDEX), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}

constexpr static std::array<unsigned int, 6> SQUARE_INDEX_PROBLEM = {
    2, 1, 4,  //
    0, 3, 4   //
};

inline std::shared_ptr<VBO> VBO_SQUARE_INDEX_PROBLEM()
{
  auto* ptr =
      new VBO(GL_ELEMENT_ARRAY_BUFFER, SQUARE_INDEX_PROBLEM.data(), sizeof(SQUARE_INDEX_PROBLEM), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}
}  // namespace gl