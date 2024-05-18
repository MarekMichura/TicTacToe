#include <memory>
#include "program.hpp"

namespace gl {

inline std::shared_ptr<Program> PROGRAM_COLORED_VERTICES()
{
  return std::make_shared<Program>("v_coloredVertices.GLSL", "f_coloredVertices.GLSL");
}
}  // namespace gl