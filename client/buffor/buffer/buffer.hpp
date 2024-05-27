#pragma once

#include <memory>
#include <format>

#include "vao.hpp"
#include "bufferTypes.h"
#include "bufferUsage.h"
#include "my_log.h"

namespace gl {
using VAO_ptr = std::shared_ptr<VAO>;
using uint = unsigned int;

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
         const VAO_ptr vao = nullptr)
      : ID(generateBuffer()), type(type)
  {
    (vao) ? vao->use() : VAO::unUse();

    glBindBuffer((uint)type, ID);
    glBufferData((uint)type, dataSize, data, (uint)usage);
    Log(std::format("Created buffer id: {}", ID));
  }
  ~Buffer();

  void use() const;
  uint getID() const;
  template <typename T>
  void updateData(const T newData, const long newDataSize, const long offsetData) const
  {
    use();
    glBufferSubData((uint)type, offsetData, newDataSize, newData);
  }

  static void unUse(const BUFFER_TYPE type);
  static uint generateBuffer();
};
}  // namespace gl