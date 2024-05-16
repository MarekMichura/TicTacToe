#pragma once

#include <iostream>
#include "mesh.hpp"
#include "staticContainer/programEnum.h"
#include "vao.hpp"
#include "triangleData.h"

namespace gl {
class Triangle : public Mesh {
public:
  Triangle() : Mesh(PROGRAM_NAME::RED_COLOR)
  {
    vao.use();
    vbo.push_back(std::make_shared<VBO>(  //
        vao,                              //
        GL_ARRAY_BUFFER,                  //
        TRIANGLE_POINTS,                  //
        sizeof(TRIANGLE_POINTS),          //
        GL_STATIC_DRAW));

    vbo[0]->use();

    vao.makePointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2);
  }

  ~Triangle() { std::cout << "Triangle destroyed\n"; }

  void draw() const override
  {
    Mesh::draw();
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
};
}  // namespace gl