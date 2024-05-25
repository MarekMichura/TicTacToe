#pragma once

#include <map>
#include <memory>

#include "program.hpp"
#include "shareProgram.h"

namespace gl {
class ShareProgramContainer {
private:
  std::map<SHARE_PROGRAM, std::weak_ptr<Program>> container;

public:
  ShareProgramContainer(const ShareProgramContainer&) = delete;
  ShareProgramContainer(ShareProgramContainer&&) = delete;
  ShareProgramContainer& operator=(const ShareProgramContainer&) = delete;
  ShareProgramContainer& operator=(ShareProgramContainer&&) = delete;

  ShareProgramContainer() = default;
  ~ShareProgramContainer() = default;

  std::shared_ptr<Program> getProgram(SHARE_PROGRAM type);
};
}  // namespace gl