#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "shader.hpp"

class Program {
private:
  const GLuint ID;
  const GLuint VAO;
  const GLuint VBO;
  /* data */
public:
  Program();
  ~Program();

  void attach(const Shader* shader);
  void afterAttach();
  void bind();
  void bindVAO();
  void bindVBO(GLenum bufferType = GL_ARRAY_BUFFER);
  template<typename T>
  void sendData(const T* data,
                size_t dataSize,
                GLenum bufferType = GL_ARRAY_BUFFER,
                GLenum usageType = GL_STATIC_DRAW);
  

private:
  static GLuint genVAO(const GLsizei size = 1)
  { 
    std::cout << "Gen VAO\n";
    GLuint VAO;
    glGenVertexArrays(size, &VAO);
    return VAO;
  }
  static GLuint genVBO(const GLsizei size = 1)
  {
    std::cout << "Gen VBO\n";
    GLuint VBO;
    glGenBuffers(size, &VBO);
    return VBO;
  }
  static void resetBinding(GLenum bufferType = GL_ARRAY_BUFFER);
};

template void Program::sendData(const float* data,
                                       size_t dataSize,
                                       GLenum bufferType,
                                       GLenum usageType);

#endif
