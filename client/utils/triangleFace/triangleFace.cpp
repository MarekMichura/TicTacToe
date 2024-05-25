#include "triangleFace.hpp"

namespace gl {
using uint = unsigned int;
TriangleFace::TriangleFace(const uint vertex1, const uint vertex2, const uint vertex3)
    : vertexLP{vertex1, vertex2, vertex3}
{
}

std::array<uint, 3> TriangleFace::getFace() const
{
  return vertexLP;
}
}  // namespace gl