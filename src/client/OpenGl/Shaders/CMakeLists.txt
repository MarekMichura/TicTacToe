file(READ "fragmentShader.GLSL" fragmentShader)
file(WRITE
  "${CMAKE_BINARY_DIR}/_deps/src/fragmentShader.h"
  "#include <string>\nconst char* fragmentShaderSource = R\"(${fragmentShader})\";\n")

file(READ "vertexShader.GLSL" vertexShader)
file(WRITE
  "${CMAKE_BINARY_DIR}/_deps/src/vertexShader.h"
  "#include <string>\nconst char* vertexShaderSource = R\"(${vertexShader})\";\n")

list(APPEND CLIENT_FILES
  "${CMAKE_BINARY_DIR}/_deps/src/fragmentShader.h"
  "${CMAKE_BINARY_DIR}/_deps/src/vertexShader.h")