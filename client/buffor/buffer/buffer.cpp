#include <glad/glad.h>

#include <format>

#include "buffer.hpp"
#include "my_log.h"
#include "position2D.hpp"
#include "triangleFace.hpp"

namespace gl {

uint Buffer::generateBuffer()
{
  uint buffer = 0;
  glGenBuffers(1, &buffer);
  return buffer;
}

// template Buffer::Buffer(const BUFFER_TYPE, const long, const Position2D[], const BUFFER_USAGE, const VAO_ptr);
// template Buffer::Buffer(const BUFFER_TYPE, const long, const TriangleFace[], const BUFFER_USAGE, const VAO_ptr);
// template <typename T>
// Buffer::Buffer(const BUFFER_TYPE type, const long dataSize, const T data, const BUFFER_USAGE usage, const VAO_ptr
// vao)
//     : ID(generateBuffer()), type(type)
// {
//   (vao) ? vao->use() : VAO::unUse();

//   glBindBuffer((uint)type, ID);
//   glBufferData((uint)type, dataSize, data, (uint)usage);
//   Log(std::format("Created buffer id: {}", ID));
// }

Buffer::~Buffer()
{
  Log(std::format("Deleted buffer id: {}", ID));
  glDeleteBuffers(1, &ID);
}

void Buffer::use() const
{
  glBindBuffer((uint)type, ID);
}

void Buffer::unUse(const BUFFER_TYPE type)
{
  glBindBuffer((uint)type, 0);
}

uint Buffer::getID() const
{
  return ID;
}

template void Buffer::updateData(const void*, const long, const long) const;
template <typename T>
void Buffer::updateData(const T newData, const long newDataSize, const long offsetData) const
{
  use();
  glBufferSubData((uint)type, offsetData, newDataSize, newData);
}
};  // namespace gl