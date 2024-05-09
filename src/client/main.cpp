#include <iostream>
#include "engine.hpp"
#include "shader.hpp"

#include "fragmentShader.h"
#include "triangle.h"
#include "vertexShader.h"
#include "window.hpp"
extern const char* fragmentShaderSource;
extern const char* vertexShaderSource;

int main()
{
  try {
    Engine engine({});
    engine.setBgColor();

    auto id = engine.createPipeline(  //
        {
            .fragmentShaderSource = fragmentShaderSource,  //
            .vertexShaderSource = vertexShaderSource,      //
            .pipelineData = myFirstObj,                    //
            .pipelineDataSize = sizeof(myFirstObj)         //
        });
    engine.bindPipeline(id);
    engine.mainLoop();
  }
  catch (char const* error) {
    std::cout << error << "\n";
    return -1;
  }
}