#pragma once

#include <sys/types.h>
#include <array>

namespace gl {
using uint = unsigned int;
class TriangleFace {
private:
  const std::array<uint, 3> vertexLP;

public:
  TriangleFace(const TriangleFace&) = delete;
  TriangleFace(TriangleFace&&) = delete;
  TriangleFace& operator=(const TriangleFace&) = delete;
  TriangleFace& operator=(TriangleFace&&) = delete;
  ~TriangleFace() = default;

  TriangleFace(const uint vertex1, const uint vertex2, const uint vertex3);

  std::array<uint, 3> getFace() const;
};
}  // namespace gl