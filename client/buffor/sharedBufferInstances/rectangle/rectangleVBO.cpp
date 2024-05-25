#include <array>
#include <memory>

#include "buffer.hpp"
#include "position2D.hpp"
#include "rectangleVBO.h"
#include "bufferUsage.h"

namespace gl {

const static std::array<Position2D, 4> rectangleVboData = {
    Position2D(-.5f, .25f),  // left top
    Position2D(.5f, .25f),   // right top
    Position2D(.5f, -.25f),  // right bottom
    Position2D(-.5f, -.25f)  // left bottom
};

std::shared_ptr<Buffer> rectangleVBO()
{
  return std::make_shared<Buffer>(  //
      BUFFER_TYPE::VBO,             //
      sizeof(rectangleVboData),     //
      rectangleVboData.data(),      //
      BUFFER_USAGE::DRAW_STATIC     //
  );
}
}  // namespace gl