#include "square.hpp"
#include <iostream>
#include "position2d.hpp"
#include "staticContainer/programContainer.hpp"
#include "staticContainer/vboEnum.h"
#include "staticContainer/vboContainer.hpp"

namespace gl {
Square::Square()
    : program(ProgramContainer::getProgram(PROGRAM_NAME::RED_COLOR)),
      vbo(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_ARRAY)),
      ebo(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_INDEX))
{
  vao.use();
  vbo->use();
  ebo->use();
  VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Position2d));
}

Square::~Square()
{
  std::cout << "Square will be destroyed\n";
}

void Square::draw()
{
  program->use();
  vao.use();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
}  // namespace gl