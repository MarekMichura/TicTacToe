#pragma once
#include <memory>
#include "vbo.hpp"

namespace gl {

struct TimeDataVBO {
  float currentTime;
  float timeDifference;
};

inline std::shared_ptr<VBO> VBO_TIME()
{
  return std::make_shared<VBO>(GL_UNIFORM_BUFFER, std::array<float, 2>{1, 1}, sizeof(TimeDataVBO), GL_STATIC_DRAW);
}
}  // namespace gl