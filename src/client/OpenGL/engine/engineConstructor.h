#pragma once

#include "color.hpp"
#include "glfwConstructor.h"
#include "windowConstructor.h"

namespace gl {
struct EngineConstructor {
  GlfwConstructor glfwConstructor = GlfwConstructor();
  WindowConstructor windowConstructor = WindowConstructor();
  Color windowBackgroundColor = COLOR::COLOR_BG;
};


}  // namespace gl