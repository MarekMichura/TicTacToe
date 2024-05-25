#include <format>

#include "shareBufferContainer.hpp"
#include "rectangleEBO.h"
#include "rectangleVBO.h"
#include "triangleVBO.h"
#include "my_assert.h"

namespace gl {

static std::shared_ptr<Buffer> staticBufferFactory(SHARE_BUFFER type)
{
  switch (type) {
    case SHARE_BUFFER::TRIANGLE_VBO:
      return triangleVBO();
    case SHARE_BUFFER::RECTANGLE_VBO:
      return rectangleVBO();
    case SHARE_BUFFER::RECTANGLE_EBO:
      return rectangleEBO();
  }
  return triangleVBO();

  Assert(false, std::format("Shared buffer id: {}, doesn't exist", (uint)type));
}

std::shared_ptr<Buffer> ShareBufferContainer::getBuffer(SHARE_BUFFER type)
{
  auto it = container.find(type);
  if (it != container.end()) {
    if (auto element = it->second.lock()) {
      return element;
    }
  }

  auto factory = staticBufferFactory(type);
  container.insert_or_assign(type, factory);

  return factory;
}

};  // namespace gl