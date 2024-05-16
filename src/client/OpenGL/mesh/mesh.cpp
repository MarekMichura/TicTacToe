#include "mesh.hpp"
#include <iostream>
#include "staticContainer/programContainer.hpp"

namespace gl {
Mesh::Mesh(PROGRAM_NAME name) : program(ProgramContainer::getProgram(name)) {}

Mesh::~Mesh()
{
  std::cout << "Mesh has been deleted\n";
}

void Mesh::draw() const
{
  program->use();
  vao.use();
}
}  // namespace gl