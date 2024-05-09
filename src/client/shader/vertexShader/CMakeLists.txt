file(READ "vertexShader.GLSL" vertexShader)
file(WRITE
  "${CMAKE_BINARY_DIR}/_deps/src/vertexShader.h"
  "#include <string>\nconst char* vertexShaderSource = R\"(${vertexShader})\";\n")