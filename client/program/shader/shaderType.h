#pragma once

#include <sys/types.h>
#include <glad/glad.h>

namespace gl {
using uint = unsigned int;
enum class SHADER_TYPE : uint {
  VERTEX = GL_VERTEX_SHADER,
  FRAGMENT = GL_FRAGMENT_SHADER,
};
}