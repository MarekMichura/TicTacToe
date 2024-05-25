#include <array>
#include <cmath>
#include <memory>

#include "buffer.hpp"
#include "position2D.hpp"
#include "triangleVBO.h"
#include "bufferUsage.h"

namespace gl {

const static std::array<Position2D, 3> triangleVboData = {
    Position2D(.0f, sqrtf(3) / 4),   // top
    Position2D(.5f, -sqrtf(3) / 4),  // right
    Position2D(-.5f, -sqrtf(3) / 4)  // left
};

std::shared_ptr<Buffer> triangleVBO()
{
  return std::make_shared<Buffer>(  //
      BUFFER_TYPE::VBO,             //
      sizeof(triangleVboData),      //
      triangleVboData.data(),       //
      BUFFER_USAGE::DRAW_STATIC     //
  );
}
}  // namespace gl