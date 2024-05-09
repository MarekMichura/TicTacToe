#ifndef VertexBuffer_HPP
#define VertexBuffer_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexBuffer {
private:
  GLuint ID;
  const unsigned int size;

public:
  VertexBuffer(const unsigned int size);
  ~VertexBuffer();

  void sendData(const float data[], const unsigned int size);
  GLuint getID() const;
};

#endif