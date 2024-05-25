#include "engine.hpp"
#include "closeWindow.hpp"
#include "triangle.hpp"

int main()
{
  auto engine = gl::Engine::GenerateEngine();

  engine->insertObj<gl::CloseWindow>();
  engine->insertObj<gl::Triangle>();

  engine->mainLoop();
  return 0;
}