#pragma once

#include <sys/types.h>

#include "glad/glad.h"

namespace gl {
enum class BUFFER_USAGE : uint {
  DRAW_STREAM = GL_STREAM_DRAW,
  READ_STREAM = GL_STREAM_READ,
  COPY_STREAM = GL_STREAM_COPY,
  DRAW_STATIC = GL_STATIC_DRAW,
  READ_STATIC = GL_STATIC_READ,
  COPY_STATIC = GL_STATIC_COPY,
  DRAW_DYNAMIC = GL_DYNAMIC_DRAW,
  READ_DYNAMIC = GL_DYNAMIC_READ,
  COPY_DYNAMIC = GL_DYNAMIC_COPY
};
}