#pragma once

#include <memory>

#include "buffer.hpp"

namespace gl {
struct TimeUBO {
  float currentTime;
  float deltaTime;
};

std::shared_ptr<Buffer> timeUBO();
}  // namespace gl