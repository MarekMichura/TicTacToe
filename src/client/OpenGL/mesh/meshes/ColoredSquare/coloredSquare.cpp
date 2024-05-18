#include "coloredSquare.hpp"
#include <iostream>
#include <memory>
#include "position2d.hpp"
#include "staticContainer/vboEnum.h"
#include "staticContainer/vboContainer.hpp"
#include "coloredSquareData.h"
#include "vao.hpp"

namespace gl {
ColoredSquare::ColoredSquare() : Mesh(PROGRAM_NAME::COLORED_VERTICES)
{
  vbo.push_back(VBOContainer::getVBO(VBO_NAME::COLORED_SQUARE_VERTEX_ARRAY));
  vbo.push_back(VBOContainer::getVBO(VBO_NAME::COLORED_SQUARE_VERTEX_INDEX));

  vao.use();
  vbo[0]->use();
  vbo[1]->use();
  VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(ColPos), 0);
  VAO::makePointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(ColPos), (void*)(sizeof(Position2d)));
}

ColoredSquare::~ColoredSquare()
{
  std::cout << "Colored square will be destroyed\n";
}

void ColoredSquare::draw() const
{
  Mesh::draw();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
}  // namespace gl