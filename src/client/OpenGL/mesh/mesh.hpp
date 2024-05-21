#pragma once

namespace gl {
class Mesh {
public:
  Mesh(const Mesh&) = delete;
  Mesh(Mesh&&) = delete;
  Mesh& operator=(const Mesh&) = delete;
  Mesh& operator=(Mesh&&) = delete;

  Mesh() = default;
  virtual ~Mesh() = default;

  virtual void draw() = 0;
};
}  // namespace gl