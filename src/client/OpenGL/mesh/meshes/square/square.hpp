#pragma once

#include <iostream>
#include <memory>
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
  Square(const Square&) = delete;
  Square(Square&&) = delete;
  Square& operator=(const Square&) = delete;
  Square& operator=(Square&&) = delete;

  Square() : Mesh(PROGRAM_NAME::RED_COLOR)
  {
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_ARRAY));
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_INDEX));

    vao.use();
    vbo[0]->use();
    vbo[1]->use();
    VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2);
  }
  ~Square() override { std::cout << "Square will be destroyed\n"; }

  void draw() const override
  {
    Mesh::draw();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }
};

class Square2 : public Mesh {
public:
  Square2(const Square2&) = delete;
  Square2(Square2&&) = delete;
  Square2& operator=(const Square2&) = delete;
  Square2& operator=(Square2&&) = delete;

  Square2() : Mesh(PROGRAM_NAME::RED_COLOR)
  {
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_ARRAY));
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::SQUARE_VERTEX_INDEX_INVALID));

    vao.use();
    vbo[0]->use();
    vbo[1]->use();
    VAO::makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2);
  }

  ~Square2() override { std::cout << "Square2 will be destroyed\n"; }

  void draw() const override
  {
    Mesh::draw();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }
};
}  // namespace gl