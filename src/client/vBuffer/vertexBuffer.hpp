#ifndef VertexBuffer_HPP
#define VertexBuffer_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexBuffer {
private:
  GLuint ID;
  const GLsizei size;

public:
  VertexBuffer(const GLsizei size);
  ~VertexBuffer();

  void sendData(const float data[], const GLsizei size);
  GLuint getID() const;
};

#endif