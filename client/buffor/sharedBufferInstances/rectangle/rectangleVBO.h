#pragma once

#include <memory>
#include "buffer.hpp"

namespace gl {
enum class rectangleVboLp : uint {  //
  LeftTop = 0,
  rightTop = 1,
  rightBottom = 2,
  leftBottom = 3
};

std::shared_ptr<Buffer> rectangleVBO();
}  // namespace gl