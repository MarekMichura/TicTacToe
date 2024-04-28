#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Shader {
private:
  GLuint ID;

public:
  Shader(const char* source, int type) {
    ID = glCreateShader(type);
    glShaderSource(ID, 1, &source, NULL);
    glCompileShader(ID);
  };

  ~Shader() {
    glDeleteShader(ID);
  }

  GLuint getID() {
    return ID;
  }
};

class ShaderProgram {
private:
  GLuint ID;

public:
  ShaderProgram() {
    ID = glCreateProgram();
  }

  ~ShaderProgram() {
    glDeleteProgram(ID);
  }

  GLuint getID() {
    return ID;
  }

  void attach(Shader* shader) {
    glAttachShader(ID, shader->getID());
  }

  void link() {
    glLinkProgram(ID);
  }

  void use() {
    glUseProgram(ID);
  }
};
