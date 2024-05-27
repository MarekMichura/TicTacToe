#include <array>
#include <memory>

#include "buffer.hpp"
#include "color.hpp"
#include "position2D.hpp"

#include "rectangleVBO.h"
#include "bufferUsage.h"
#include "position2DWithColor.h"

namespace gl {

const static std::array<Position2D, 4> rectangleVboData = {
    Position2D(-.5f, .25f),  // left top
    Position2D(.5f, .25f),   // right top
    Position2D(.5f, -.25f),  // right bottom
    Position2D(-.5f, -.25f)  // left bottom
};

const static std::array<Position2DWithColor, 4> rectangleVboDataWithColor = {
    Position2DWithColor{rectangleVboData[0].copy(), COLORS::COLOR_RED},
    Position2DWithColor{rectangleVboData[1].copy(), COLORS::COLOR_GREEN},
    Position2DWithColor{rectangleVboData[2].copy(), COLORS::COLOR_BLUE},
    Position2DWithColor{rectangleVboData[3].copy(), COLORS::COLOR_WHITE},
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

std::shared_ptr<Buffer> rectangleVBOWithColor()
{
  return std::make_shared<Buffer>(        //
      BUFFER_TYPE::VBO,                   //
      sizeof(rectangleVboDataWithColor),  //
      rectangleVboDataWithColor.data(),   //
      BUFFER_USAGE::DRAW_STATIC           //
  );
}
}  // namespace gl