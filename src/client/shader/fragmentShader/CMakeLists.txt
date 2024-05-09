file(READ "fragmentShader.GLSL" fragmentShader)
file(WRITE
  "${CMAKE_BINARY_DIR}/_deps/src/fragmentShader.h"
  "#include <string>\nconst char* fragmentShaderSource = R\"(${fragmentShader})\";\n")
