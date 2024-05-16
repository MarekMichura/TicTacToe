#pragma once

#include <functional>
#include <map>
#include <memory>
#include "program.hpp"
#include "programEnum.h"

namespace gl {
using ProgramFunMap =
    std::map<PROGRAM_NAME, std::function<std::shared_ptr<Program>()>>;
using ProgramMap = std::map<PROGRAM_NAME, std::weak_ptr<Program>>;

class ProgramContainer {
private:
  const static ProgramFunMap containerFun;
  static ProgramMap container;

public:
  static std::shared_ptr<Program> getProgram(PROGRAM_NAME name);
};

}  // namespace gl
