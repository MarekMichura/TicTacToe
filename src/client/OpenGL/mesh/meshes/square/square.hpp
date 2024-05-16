#pragma once

#include <iostream>
#include "mesh.hpp"
#include "program.hpp"
#include "staticContainer/programEnum.h"
#include "staticContainer/vboEnum.h"
#include "vao.hpp"
#include "squareData.h"
#include "staticContainer/vboContainer.hpp"

namespace gl {
class Square : public Mesh {
public:
  Square() : Mesh(PROGRAM_NAME::RED_COLOR)
  {
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_ARRAY));
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_INDEX));

    vao.use();
    vbo[0]->use();
    vbo[1]->use();
    vao.makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2);
  }

  ~Square() { std::cout << "Square destroyed\n"; }

  void draw() const override
  {
    Mesh::draw();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }
};

class Square2 : public Mesh {
public:
  Square2() : Mesh(PROGRAM_NAME::RED_COLOR)
  {
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_ARRAY));
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_INDEX_INVALID));

    vao.use();
    vbo[0]->use();
    vbo[1]->use();
    vao.makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2);
  }

  ~Square2() { std::cout << "Square destroyed\n"; }

  void draw() const override
  {
    Mesh::draw();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }
};
}  // namespace gl