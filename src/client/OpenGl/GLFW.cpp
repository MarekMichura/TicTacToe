#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLFW {
public:
  GLFW(int versionMajor = 3, int versionMinor = 3) {
    if (!glfwInit()) {
      throw "Failed to initialize glfw\n";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }
  ~GLFW() {
    glfwTerminate();
  }
};