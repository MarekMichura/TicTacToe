#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Shader {
private:
  const GLuint ID;

public:
  Shader(const char* source, GLenum type, const std::string text = "");
  ~Shader();

  GLuint getID();
};

#endif