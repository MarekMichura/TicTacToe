#pragma once

#include "color.hpp"
#include "glfwConstructor.h"
#include "windowConstructor.h"

namespace gl {
struct EngineConstructor {
  GlfwConstructor glfwConstructor = GlfwConstructorDefault;
  WindowConstructor windowConstructor = windowConstructorDefault;
  Color windowBackgroundColor = Color::hexadecimalColorCode("#DBB4AD");
};

constexpr EngineConstructor EngineConstructorDefault = {};
}  // namespace gl