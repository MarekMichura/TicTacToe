#pragma once

#include <sys/types.h>

#include "color.hpp"
#include "glTypes.h"

namespace gl {
using uint = unsigned int;
class VAO {
private:
  const uint ID;

public:
  VAO(VAO&&) = delete;
  VAO& operator=(const VAO&) = delete;
  VAO& operator=(VAO&&) = delete;
  VAO(const VAO&) = delete;

  VAO();
  ~VAO();

  void use() const;
  static void createAttributePointerToSelectedVAO(  
      const uint index,
      const int howManyVariables,
      const GL_VARIABLE_TYPE variableType,
      const uchar normalized,
      const int sizeOfAttribute,
      const void* offset = nullptr);
  static void unUse();
};
}  // namespace gl