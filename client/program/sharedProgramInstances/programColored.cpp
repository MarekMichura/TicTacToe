#include <memory>

#include "programs.hpp"

namespace gl {
std::shared_ptr<Program> Programs::getProgramColored()
{
  return std::make_shared<Program>("v_colored.GLSL", "f_colored.GLSL");
}
}  // namespace gl