#include <memory>
#include "programContainer.hpp"
#include "_shaderColorRed.h"
#include "_shaderColoredVertices.h"
#include "staticContainer/programEnum.h"

namespace gl {
ProgramMap ProgramContainer::container{};

const ProgramFunMap ProgramContainer::containerFun{
    //
    {PROGRAM_NAME::RED_COLOR, PROGRAM_COLOR_RED},                //
    {PROGRAM_NAME::COLORED_VERTICES, PROGRAM_COLORED_VERTICES},  //
};

std::shared_ptr<Program> ProgramContainer::getProgram(PROGRAM_NAME name)
{
  auto it = container.find(name);
  if (it != container.end()) {
    if (auto data = it->second.lock()) {
      return data;
    }
  }

  auto fun = containerFun.find(name)->second();
  container.insert_or_assign(name, fun);
  return fun;
}
}  // namespace gl