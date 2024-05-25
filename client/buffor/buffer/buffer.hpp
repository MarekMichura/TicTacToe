#pragma once

#include <memory>

#include "vao.hpp"
#include "bufferTypes.h"
#include "bufferUsage.h"

namespace gl {
using VAO_ptr = std::shared_ptr<VAO>;

class Buffer {
private:
  const uint ID;
  const BUFFER_TYPE type;

public:
  Buffer(Buffer&&) = delete;
  Buffer& operator=(const Buffer&) = delete;
  Buffer& operator=(Buffer&&) = delete;
  Buffer(const Buffer&) = delete;

  template <typename T>
  Buffer(const BUFFER_TYPE type,
         const long dataSize,
         const T data,
         const BUFFER_USAGE usage,
         const VAO_ptr vao = nullptr);
  ~Buffer();

  void use() const;
  uint getID() const;
  template <typename T>
  void updateData(const T newData, const long newDataSize, const long offsetData) const;

  static void unUse(const BUFFER_TYPE type);
};
}  // namespace gl