#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>
#include "glad/glad.h"
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

  template <typename T, size_t size>
  VBO(const VAO& vao,
      const GLenum& bufferType,
      const std::array<T, size>& data,
      const long& data_size,
      const GLenum& usageType)
      : ID(genVBO()), bufferType(bufferType)
  {
    vao.use();
    glBindBuffer(bufferType, ID);
    glBufferData(bufferType, (data_size), data, usageType);
    std::cout << "VBO has been created: " << ID << "\n";
  }
  template <typename T, size_t size>
  VBO(const GLenum& bufferType, const std::array<T, size>& data, const long& data_size, const GLenum& usageType)
      : ID(genVBO()), bufferType(bufferType)
  {
    VAO::lose();
    glBindBuffer(bufferType, ID);
    glBufferData(bufferType, (data_size), data.data(), usageType);
    std::cout << "VBO has been created: " << ID << "\n";
  }
  ~VBO();

  void use() const;

  static void lose()
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

private:
  static GLuint genVBO();
};
}  // namespace gl
