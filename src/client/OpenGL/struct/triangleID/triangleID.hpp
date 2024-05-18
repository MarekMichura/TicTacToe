#pragma once
#include <cstdint>

namespace gl {
class TriangleID {
public:
  uint32_t a;
  uint32_t b;
  uint32_t c;

  constexpr TriangleID(const uint32_t& a, const uint32_t& b, const uint32_t& c) : a(a), b(b), c(c) {}
};
}  // namespace gl
