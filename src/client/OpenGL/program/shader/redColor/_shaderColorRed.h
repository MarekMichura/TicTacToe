#include <memory>
#include "program.hpp"

namespace gl {

inline std::shared_ptr<Program> PROGRAM_COLOR_RED()
{
  return std::make_shared<Program>("v_redColor.GLSL", "f_redColor.GLSL");
}
}  // namespace gl