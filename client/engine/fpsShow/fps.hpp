#pragma once
#ifndef NDEBUG
#include <sys/types.h>

#define FpsMeasure(time) fps.update(time)
#define FpsDefine FPS fps

namespace gl {
using uint = unsigned int;
class FPS {
private:
  double lastTimeUpdate = 0;
  uint frameCount = 0;

public:
  void update(const double time, const double samples = 10);
};
}  // namespace gl
#else
#define FpsMeasure(time) (void)(time)
#define FpsDefine
#endif