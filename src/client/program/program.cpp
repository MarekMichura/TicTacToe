#include <iostream>

#include "program.hpp"

Program::Program()
    : ID(glCreateProgram()),
      VAO(genVAO()),
      VBO(genVBO())
{
  std::cout << "create program\n";
}

Program::~Program()
{
  std::cout << "delete program\n";
   glDeleteVertexArrays(1, &VAO);
   glDeleteBuffers(1, &VBO);
  glDeleteProgram(ID);
}

void Program::attach(const Shader* shader)
{
  
  glAttachShader(ID, shader->getID());
}

void Program::afterAttach() {
  glLinkProgram(ID);

  GLint linked;
  glGetProgramiv(ID, GL_LINK_STATUS, &linked);

  if (linked == GL_FALSE) {
    // Program nie zosta³ pomyœlnie po³¹czony.
    // Pobierz informacje o b³êdzie.
    GLint logLength;
    glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &logLength);

    GLchar* log = new GLchar[logLength];
    glGetProgramInfoLog(ID, logLength, NULL, log);
    std::cout << "Blad podczas laczenia programu: " << log;
    delete[] log;
    // Wypisz log b³êdu.
    throw "Blad podczas laczenia programu";
  }
}

void Program::bindVBO(GLenum bufferType)
{
  glBindBuffer(bufferType, VBO);
}

void Program::resetBinding(GLenum bufferType) {
  glBindBuffer(bufferType, 0);
  glBindVertexArray(0);
}

void Program::bindVAO()
{
  glBindVertexArray(VAO);
}

void Program::bind() {
  glUseProgram(ID);
}

template <typename T>
void Program::sendData(const T* data,
                              size_t dataSize,
                              GLenum bufferType,
                              GLenum usageType)
{
  bindVAO();
  bindVBO(bufferType);
  glBufferData(bufferType, dataSize, data, usageType);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
  glEnableVertexAttribArray(0);
  resetBinding();
}
