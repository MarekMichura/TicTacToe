#pragma once

#include <memory>
#include "buffer.hpp"

namespace gl {
using uchar = unsigned char;

enum class rectangleVboLp { LeftTop, rightTop, rightBottom, leftBottom };

std::shared_ptr<Buffer> rectangleVBO();

std::shared_ptr<Buffer> rectangleVBOWithColor();
}  // namespace gl