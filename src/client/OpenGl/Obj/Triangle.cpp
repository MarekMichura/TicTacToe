#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

const GLfloat vertices[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,   // Lower left corner
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    // Lower right corner
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f  // Upper corner
};

class Triangle {
private:
  GLuint ID;
  GLuint buf;

public:
  Triangle() {
    glGenVertexArrays(1, &buf);

    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glBindVertexArray(0);
  };
  ~Triangle() {
    glDeleteVertexArrays(1, &buf);
    glDeleteVertexArrays(1, &ID);
  }

  void bind() {
    glBindVertexArray(buf);
  }
};
