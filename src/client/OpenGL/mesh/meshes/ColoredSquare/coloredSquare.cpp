#include "coloredSquare.hpp"
#include <iostream>
#include <memory>
#include "position2d.hpp"
#include "program.hpp"
#include "staticContainer/programContainer.hpp"
#include "staticContainer/vboEnum.h"
#include "staticContainer/vboContainer.hpp"
#include "coloredSquareData.h"
#include "vao.hpp"

namespace gl {
ColoredSquare::ColoredSquare()
    : program(ProgramContainer::getProgram(PROGRAM_NAME::COLORED_VERTICES)),
      vbo(VBOContainer::getVBO(VBO_NAME::COLORED_SQUARE_VERTEX_ARRAY)),
      ebo(VBOContainer::getVBO(VBO_NAME::COLORED_SQUARE_VERTEX_INDEX)),
      ubo(VBOContainer::getVBO(VBO_NAME::TIME))
{
  vao.use();
  vbo->use();
  ebo->use();

  VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(ColPos), 0);
  VAO::makePointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(ColPos), (void*)(sizeof(Position2d)));

  program->combineUniform("MyUniformBlock", ubo, 0);
}

ColoredSquare::~ColoredSquare()
{
  std::cout << "Colored square will be destroyed\n";
}

void ColoredSquare::draw()
{
  program->use();
  vao.use();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
}  // namespace gl