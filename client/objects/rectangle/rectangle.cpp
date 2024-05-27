#include "glTypes.h"
#include "position2D.hpp"
#include "vao.hpp"
#include "rectangle.hpp"

#include "position2DWithColor.h"
#include "shareBuffer.h"

namespace gl {
Rectangle::Rectangle(std::shared_ptr<Engine> engine)
    : program(engine->getShareProgram()->getProgram(SHARE_PROGRAM::COLORED)),
      vbo(engine->getShareBuffer()->getBuffer(SHARE_BUFFER::RECTANGLE_VBO_COLOR)),
      ebo(engine->getShareBuffer()->getBuffer(SHARE_BUFFER::RECTANGLE_EBO)),
      timeUBO(engine->getShareBuffer()->getBuffer(SHARE_BUFFER::TIME))
{
  vao.use();
  vbo->use();
  ebo->use();

  program->connectUBO("Time", timeUBO, 0);
  // timeUBO->use();

  VAO::createAttributePointerToSelectedVAO(0, 2, GL_VARIABLE_TYPE::FLOAT, 0u, sizeof(Position2DWithColor));
  VAO::createAttributePointerToSelectedVAO(1, 4, GL_VARIABLE_TYPE::FLOAT, 0u, sizeof(Position2DWithColor),
                                           (void*)sizeof(Position2D));
}

void Rectangle::draw()
{
  program->use();
  vao.use();
  glDrawElements(GL_TRIANGLES, 6, (uint)GL_VARIABLE_TYPE::UINT, 0);
}
}  // namespace gl