#pragma once

#include <sys/types.h>
#include <glad/glad.h>

namespace gl {
enum class SHADER_TYPE : uint {
  VERTEX = GL_VERTEX_SHADER,
  FRAGMENT = GL_FRAGMENT_SHADER,
};
}