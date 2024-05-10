#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "engine.hpp"

#include "fragmentShader.h"
#include "triangle.h"
#include "vertexShader.h"
extern const char* fragmentShaderSource;
extern const char* vertexShaderSource;

#ifdef _WIN3
extern "C" {
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

void useEngine()
{
  Engine engine({});
  engine.setBgColor();

  auto id = engine.createPipeline({
      .fragmentShaderSource = fragmentShaderSource,  //
      .vertexShaderSource = vertexShaderSource,      //
      .pipelineData = myFirstObj,                    //
      .pipelineDataSize = sizeof(myFirstObj)         //
  });
  engine.bindPipeline(id);

  engine.mainLoop();
}

int main()
{
  try {
    useEngine();
  }
  catch (char const* error) {
    std::cout << error << "\n";
    return -1;
  }
}