#pragma once

#include <map>
#include <memory>

#include "buffer.hpp"
#include "shareBuffer.h"

namespace gl {
class ShareBufferContainer {
private:
  std::map<SHARE_BUFFER, std::weak_ptr<Buffer>> container;

public:
  ShareBufferContainer(const ShareBufferContainer&) = delete;
  ShareBufferContainer(ShareBufferContainer&&) = delete;
  ShareBufferContainer& operator=(const ShareBufferContainer&) = delete;
  ShareBufferContainer& operator=(ShareBufferContainer&&) = delete;

  ShareBufferContainer() = default;
  ~ShareBufferContainer() = default;

  std::shared_ptr<Buffer> getBuffer(SHARE_BUFFER type);
};
}  // namespace gl