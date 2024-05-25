#pragma once

#include <sys/types.h>

#include "glad/glad.h"

namespace gl {
enum class GL_VARIABLE_TYPE : uint {  //
  BYTE = GL_BYTE,
  UBYTE = GL_UNSIGNED_BYTE,
  SHORT = GL_SHORT,
  USHORT = GL_UNSIGNED_SHORT,
  INT = GL_INT,
  UINT = GL_UNSIGNED_INT,
  HALF_FLOAT = GL_HALF_FLOAT,
  FLOAT = GL_FLOAT,
  DOUBLE = GL_DOUBLE,
  FIXED = GL_FIXED,
  INT_2_10_10_10_10 = GL_INT_2_10_10_10_REV,
  UINT_2_10_10_10 = GL_UNSIGNED_INT_2_10_10_10_REV,
  UINT_10F_11F_11F = GL_UNSIGNED_INT_10F_11F_11F_REV
};
}