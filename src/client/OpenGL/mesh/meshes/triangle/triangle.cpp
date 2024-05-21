#include "triangle.hpp"
#include <iostream>
#include "position2d.hpp"
#include "program.hpp"
#include "staticContainer/programContainer.hpp"
#include "staticContainer/vboEnum.h"
#include "staticContainer/vboContainer.hpp"
#include "vao.hpp"

namespace gl {
Triangle::Triangle()
    : program(ProgramContainer::getProgram(PROGRAM_NAME::RED_COLOR)),
      vbo(VBOContainer::getVBO(VBO_NAME::TRIANGLE_VERTEX_ARRAY))
{
  vao.use();
  vbo->use();
  gl::VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(gl::Position2d));
}

Triangle::~Triangle()
{
  std::cout << "Triangle will be destroyed\n";
}

void Triangle::draw()
{
  program->use();
  vao.use();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
}  // namespace gl