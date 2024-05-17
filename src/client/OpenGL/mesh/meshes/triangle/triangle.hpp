#pragma once

#include <iostream>
#include "mesh.hpp"
#include "staticContainer/programEnum.h"
#include "staticContainer/vboContainer.hpp"
#include "vao.hpp"
#include "triangleData.h"

namespace gl {
class Triangle : public Mesh {
public:
  Triangle(const Triangle&) = delete;
  Triangle(Triangle&&) = delete;
  Triangle& operator=(const Triangle&) = delete;
  Triangle& operator=(Triangle&&) = delete;

  Triangle() : Mesh(PROGRAM_NAME::RED_COLOR)
  {
    vbo.push_back(VBOContainer::getVBO(VBO_NAME::TRIANGLE_VERTEX_ARRAY));

    vao.use();
    vbo[0]->use();
    vao.makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2);
  }

  ~Triangle() override { std::cout << "Triangle destroyed\n"; }

  void draw() const override
  {
    Mesh::draw();
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
};
}  // namespace gl