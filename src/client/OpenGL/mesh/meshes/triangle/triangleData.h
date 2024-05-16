#include <memory>
#include "vbo.hpp"

namespace gl {
constexpr static float TRIANGLE_POINTS[] = {
    .0f,  .5f,   //
    -.5f, -.5f,  //
    .5f,  -.5f,  //
};

inline std::shared_ptr<VBO> VBO_TRIANGLE_POINTS()
{
  return std::make_shared<VBO>(  //
      GL_ARRAY_BUFFER,           //
      TRIANGLE_POINTS,           //
      sizeof(TRIANGLE_POINTS),   //
      GL_STATIC_DRAW);
}
}  // namespace gl