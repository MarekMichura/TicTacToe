#include "square.hpp"
#include <iostream>
#include "staticContainer/vboEnum.h"
#include "staticContainer/vboContainer.hpp"

namespace gl {
Square::Square() : Mesh(PROGRAM_NAME::RED_COLOR)
{
  vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_ARRAY));
  vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_INDEX));

  vao.use();
  vbo[0]->use();
  vbo[1]->use();
  VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2);
}

Square::~Square()
{
  std::cout << "Square will be destroyed\n";
}

void Square::draw() const
{
  Mesh::draw();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
}  // namespace gl