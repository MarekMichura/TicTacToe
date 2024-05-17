#pragma once

#include "glad//glad.h"

namespace gl {

class VAO {
private:
  const GLuint ID;

public:
  VAO(VAO&&) = delete;
  VAO& operator=(const VAO&) = delete;
  VAO& operator=(VAO&&) = delete;
  VAO(const VAO&) = delete;

  VAO();
  ~VAO();

  void use() const;

  static void makePointer(  //
      const GLuint& indexOfVertexArray,
      const GLint& howManyVariablesPerVertex,
      const GLenum& typeOfVariables,
      const GLboolean& isDataInt,
      const GLsizei& howManyBytesFromDataPerVertex);
  static void lose();

private:
  static GLuint genVAO();
};
}  // namespace gl