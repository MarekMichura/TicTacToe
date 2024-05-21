#pragma once

#include <array>
#include <cstddef>
#include <iostream>
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
    glBufferData(bufferType, data_size, data.data(), usageType);
    std::cout << "VBO has been created: " << ID << "\n";
  }
  template <typename T, size_t size>
  VBO(const GLenum& bufferType, const std::array<T, size>& data, const long& data_size, const GLenum& usageType)
      : ID(genVBO()), bufferType(bufferType)
  {
    VAO::lose();
    glBindBuffer(bufferType, ID);
    glBufferData(bufferType, data_size, data.data(), usageType);
    std::cout << "VBO has been created: " << ID << "\n";
  }
  template <typename T>
  VBO(const VAO& vao, const GLenum& bufferType, const T& data, const long& data_size, const GLenum& usageType)
      : ID(genVBO()), bufferType(bufferType)
  {
    vao.use();
    glBindBuffer(GL_UNIFORM_BUFFER, ID);
    glBufferData(bufferType, data_size, data, usageType);
    glBindBuffer(GL_UNIFORM_BUFFER, ID);
    std::cout << "VBO has been created: " << ID << "\n";
  }

  ~VBO();

  GLuint getID() const;
  void use() const;
  void use(GLuint bindingPoint) const;
  void changeData(const long& offset, const long& size, const void* data);

  static void lose();

private:
  static GLuint genVBO();
};
}  // namespace gl
