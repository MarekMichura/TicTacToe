
#ifndef NDEBUG
#include <format>
#include <chrono>

#include "fps.hpp"
#include "my_log.h"

namespace gl {
void FPS::update(const double time, const double samples)
{
  ++frameCount;

  if (time - lastTimeUpdate >= samples) {
    Log(std::format("FPS: {}, Time: {} - {}", frameCount / samples, lastTimeUpdate, time));
    lastTimeUpdate = time;
    frameCount = 0;
  }
}
}  // namespace gl
#endif