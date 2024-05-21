#include <iostream>
#include <memory>

#include "coloredSquare.hpp"
#include "engine.hpp"
#include "square.hpp"
#include "triangle.hpp"

#ifdef _WIN32
extern "C" {
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

int main()
{
  gl::Engine engine;

  engine.loadMesh(std::make_unique<gl::ColoredSquare>());
  engine.loadMesh(std::make_unique<gl::Square>());
  engine.loadMesh(std::make_unique<gl::Triangle>());

  engine.mainLoop();
  std::cout << "main loop end\n";
}
