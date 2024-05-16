#pragma once

#include "glad//glad.h"

namespace gl {

class VAO {
private:
  const GLuint ID;

public:
  VAO(const VAO&) = delete;
  VAO();
  ~VAO();

  void use() const;
  void makePointer(  //
      const GLuint& indexOfVertexArray,
      const GLint& howManyVariablesPerVertex,
      const GLenum& typeOfVariables,
      const GLboolean& isDataInt,
      const GLsizei& howManyBytesFromDataPerVertex) const;

  static void lose();

private:
  static GLuint genVAO();
};
}  // namespace gl