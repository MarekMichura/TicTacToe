#include "triangle.hpp"
#include <iostream>
#include "staticContainer/vboEnum.h"
#include "staticContainer/vboContainer.hpp"
#include "vao.hpp"

namespace gl {
Triangle::Triangle() : Mesh(PROGRAM_NAME::RED_COLOR)
{
  //VAO::lose();
  //VBO::lose();
  vbo.push_back(VBOContainer::getVBO(VBO_NAME::TRIANGLE_VERTEX_ARRAY));

  vao.use();
  vbo[0]->use();
  VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2,nullptr);
}

Triangle::~Triangle()
{
  std::cout << "Triangle will be destroyed\n";
}

void Triangle::draw() const
{
  Mesh::draw();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
}  // namespace gl