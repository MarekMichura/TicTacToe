#pragma once

#include <functional>
#include <map>
#include <memory>
#include "vbo.hpp"
#include "vboEnum.h"

namespace gl {
using VboFunMap = std::map<VBO_NAME, std::function<std::shared_ptr<VBO>()>>;
using VboMap = std::map<VBO_NAME, std::weak_ptr<VBO>>;

class VBOContainer {
private:
  const static VboFunMap containerFun;
  static VboMap container;

public:
  static std::shared_ptr<VBO> getVBO(VBO_NAME name);
};

}  // namespace gl
