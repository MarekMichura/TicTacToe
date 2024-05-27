#pragma once

#include <memory>
#include "program.hpp"

namespace gl {
class Programs {
public:
  static std::shared_ptr<Program> getProgramRed();
  static std::shared_ptr<Program> getProgramColored();
};
}  // namespace gl