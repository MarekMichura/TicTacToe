#include <array>
#include <memory>

#include "buffer.hpp"
#include "triangleFace.hpp"

#include "bufferUsage.h"
#include "rectangleEBO.h"
#include "rectangleVBO.h"

namespace gl {

const static std::array<TriangleFace, 2> rectangleEboData = {
    TriangleFace((uint)rectangleVboLp::LeftTop, (uint)rectangleVboLp::rightTop, (uint)rectangleVboLp::rightBottom),   //
    TriangleFace((uint)rectangleVboLp::LeftTop, (uint)rectangleVboLp::rightBottom, (uint)rectangleVboLp::leftBottom)  //
};

std::shared_ptr<Buffer> rectangleEBO()
{
  return std::make_shared<Buffer>(  //
      BUFFER_TYPE::EBO,             //
      sizeof(rectangleEboData),     //
      rectangleEboData.data(),      //
      BUFFER_USAGE::DRAW_STATIC     //
  );
}
}  // namespace gl