#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "my_assert.h"
#include "my_log.h"

#include "glfw.hpp"

namespace gl {
GLFW::GLFW(GLFW_Constructor param) noexcept
{
  const int status = glfwInit();
  Assert(status != 0, "GLFW is not initialized");
  Log("GLFW has been initialized");

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, param.versionMajorGLFW);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, param.versionMinorGLFW);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);
  glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

  Log("GLFW window hints has been set: ");
  Log("GLFW version: " + std::string(glfwGetVersionString()));
  gladLoadGL();
}

GLFW::~GLFW() noexcept
{
  glfwTerminate();
  Log("GLFW has been terminated");
}
}  // namespace gl