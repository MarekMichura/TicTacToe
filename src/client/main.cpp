#include <glad/glad.h>

#include <iostream>
#include <GLFW/glfw3.h>

#include "engine.hpp"
#include "shader.hpp"

#include "fragmentShader.h"
#include "triangle.h"
#include "vertexShader.h"
#include "window.hpp"
extern const char* fragmentShaderSource;
extern const char* vertexShaderSource;

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

extern "C" {
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
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