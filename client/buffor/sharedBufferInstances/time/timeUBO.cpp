#include <array>
#include <memory>

#include "buffer.hpp"

#include "bufferUsage.h"
#include "timeUBO.h"

namespace gl {

std::array<TimeUBO, 1> time{TimeUBO(0, 0)};

std::shared_ptr<Buffer> timeUBO()
{
  return std::make_shared<Buffer>(  //
      BUFFER_TYPE::UBO,             //
      sizeof(TimeUBO),              //
      time.data(),                  //
      BUFFER_USAGE::DRAW_STATIC     //
  );
}
}  // namespace gl