#include <array>
#include <memory>
#include "vbo.hpp"

namespace gl {
constexpr static std::array<float, 6> TRIANGLE_POINTS = {
    .0f,  .5f,   //
    -.5f, -.5f,  //
    .5f,  -.5f,  //
};

inline std::shared_ptr<VBO> VBO_TRIANGLE_POINTS()
{
  auto* ptr = new VBO(GL_ELEMENT_ARRAY_BUFFER, TRIANGLE_POINTS.data(), sizeof(TRIANGLE_POINTS), GL_STATIC_DRAW);
  return std::shared_ptr<VBO>(ptr);
}
}  // namespace gl