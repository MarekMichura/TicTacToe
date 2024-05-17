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
  VBO(VBO&&) = delete;
  VBO& operator=(const VBO&) = delete;
  VBO& operator=(VBO&&) = delete;
  VBO(const VBO&) = delete;

  template <typename T>
  VBO(const VAO& vao, const GLenum& bufferType, const T* data, const long& data_size, const GLenum& usageType);
  template <typename T>
  VBO(const GLenum& bufferType, const T* data, const long& data_size, const GLenum& usageType);
  ~VBO();

  void use() const;

private:
  static GLuint genVBO();
};
}  // namespace gl
