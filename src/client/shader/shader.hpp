#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader {
private:
  const GLuint ID;

public:
  Shader(const char* source, const GLenum type);
  ~Shader();

  GLuint getID() const;
};

#endif