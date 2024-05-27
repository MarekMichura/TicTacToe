#include "engine.hpp"
#include "closeWindow.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

#ifdef _WIN32
extern "C" {
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif
#ifdef __linux__

__attribute__((constructor)) void enable_nv_optimus()
{
  setenv("NV_PRIME_RENDER_OFFLOAD", "1", 1);
  setenv("NV_PRIME_RENDER_OFFLOAD_PROVIDER", "1", 1);
  setenv("NV_OPTIMUS", "1", 1);
}

#endif

int main()
{
  auto engine = gl::Engine::GenerateEngine();

  engine->insertObj<gl::CloseWindow>();
  // engine->insertObj<gl::Triangle>();
  engine->insertObj<gl::Rectangle>();

  engine->mainLoop();
  return 0;
}