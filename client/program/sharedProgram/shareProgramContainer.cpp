#include <cstdlib>
#include <format>
#include <memory>

#include "program.hpp"
#include "shareProgramContainer.hpp"
#include "shareProgram.h"
#include "my_assert.h"

namespace gl {

static std::shared_ptr<Program> staticBufferFactory(SHARE_PROGRAM type)
{
  return std::make_shared<Program>("v_redColor.GLSL", "f_redColor.GLSL");
  switch (type) {
    case SHARE_PROGRAM::COLORED:
    case SHARE_PROGRAM::RED:
      break;
  }
  Assert(false, std::format("Shared program id: {}, doesn't exist", (uint)type));
  abort();
}

std::shared_ptr<Program> ShareProgramContainer::getProgram(SHARE_PROGRAM type)
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