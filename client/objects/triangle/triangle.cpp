#include "triangle.hpp"
#include "my_assert.h"
#include "position2D.hpp"
#include "shareBuffer.h"
#include "vao.hpp"

namespace gl {
Triangle::Triangle(std::weak_ptr<Engine> engine)
    : program(engine.lock()->getShareProgram()->getProgram(SHARE_PROGRAM::RED)),
      vbo(engine.lock()->getShareBuffer()->getBuffer(SHARE_BUFFER::TRIANGLE_VBO))
{
  vao.use();
  vbo->use();

  VAO::createAttributePointerToSelectedVAO(0, 2, GL_VARIABLE_TYPE::FLOAT, false, sizeof(Position2D));
}

void Triangle::draw()
{
  program->use();
  vao.use();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
}  // namespace gl