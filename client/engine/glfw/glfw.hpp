#pragma once

namespace gl {
struct GLFW_Constructor {
  static constexpr int GLFW_DEFAULT_VERSION_MAJOR = 3;
  static constexpr int GLFW_DEFAULT_VERSION_MINOR = 3;

  int versionMajorGLFW = GLFW_DEFAULT_VERSION_MAJOR;
  int versionMinorGLFW = GLFW_DEFAULT_VERSION_MINOR;
};

class GLFW {
public:
  GLFW(const GLFW&) = delete;
  GLFW(GLFW&&) = delete;
  GLFW& operator=(const GLFW&) = delete;
  GLFW& operator=(GLFW&&) = delete;

  GLFW(GLFW_Constructor param) noexcept;
  ~GLFW() noexcept;
};
}  // namespace gl