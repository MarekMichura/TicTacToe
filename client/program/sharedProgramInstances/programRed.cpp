#include <memory>

#include "programs.hpp"

namespace gl {
std::shared_ptr<Program> Programs::getProgramRed()
{
  return std::make_shared<Program>("v_redColor.GLSL", "f_redColor.GLSL");
}
}  // namespace gl