#ifndef GLFW_HPP
#define GLFW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLFW {
private:
public:
  GLFW(int versionMajor = 4, int versionMinor = 5);
  ~GLFW();
};

#endif