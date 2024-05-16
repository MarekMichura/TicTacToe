#pragma once

#include "glad/glad.h"
#include <cstddef>
#include "vao.hpp"

namespace gl {
class VBO {
private:
  const GLuint ID;
  const GLenum bufferType;

public:
  VBO(const VBO&) = delete;
  template <typename T>
  VBO(const VAO& vao,
      const GLenum& bufferType,
      const T* data,
      const size_t& data_size,
      const GLenum& usageType);
  template <typename T>
  VBO(const GLenum& bufferType,
      const T* data,
      const size_t& data_size,
      const GLenum& usageType);
  ~VBO();

  void use();

private:
  static GLuint genVBO();
};
}  // namespace gl