#include <iostream>
#include <memory>
#include <utility>

#include "engine.hpp"
#include "square.hpp"
#include "triangle.hpp"

#ifdef _WIN32
extern "C" {
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

void useEngine()
{
  gl::Engine engine;

  engine.loadMesh(std::make_unique<gl::Square2>());
  engine.loadMesh(std::make_unique<gl::Square>());
  engine.loadMesh(std::make_unique<gl::Triangle>());

  engine.mainLoop();
  std::cout << "main loop end\n";
}

int main()
{
  try {
    useEngine();
  }
  catch (const char* error) {
    std::cout << error << "\n";
    return -1;
  }
}