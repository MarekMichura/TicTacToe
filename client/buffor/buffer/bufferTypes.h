#pragma once

#include <sys/types.h>

#include <glad/glad.h>

namespace gl {
enum class BUFFER_TYPE : uint {  //
  VBO = GL_ARRAY_BUFFER,
  EBO = GL_ELEMENT_ARRAY_BUFFER,
  UBO = GL_UNIFORM_BUFFER,

  ARRAY = GL_ARRAY_BUFFER,
  ATOMIC_COUNTER = GL_ATOMIC_COUNTER_BUFFER,
  COPY_READ = GL_COPY_READ_BUFFER,
  COPY_WRITE = GL_COPY_WRITE_BUFFER,
  DISPATCH = GL_DISPATCH_INDIRECT_BUFFER,
  DRAW = GL_DRAW_INDIRECT_BUFFER,
  ELEMENT_ARRAY = GL_ELEMENT_ARRAY_BUFFER,
  PIXEL_PACK = GL_PIXEL_PACK_BUFFER,
  PIXEL_UNPACK = GL_PIXEL_UNPACK_BUFFER,
  QUERY = GL_QUERY_BUFFER,
  SHADER_STORAGE = GL_SHADER_STORAGE_BUFFER,
  TEXTURE = GL_TEXTURE_BUFFER,
  TRANSFORM = GL_TRANSFORM_FEEDBACK_BUFFER,
  UNIFORM = GL_UNIFORM_BUFFER
};

}  // namespace gl
