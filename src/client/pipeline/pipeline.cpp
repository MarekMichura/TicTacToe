#include "pipeline.hpp"
#include <iostream>

PipeLine::PipeLine(const unsigned int size) : size(size)
{
  std::cout << "create pipeline\n";
  glCreateProgramPipelines(size, &ID);
}

PipeLine::~PipeLine()
{
  std::cout << "delete pipeline\n";
  glDeleteProgramPipelines(size, &ID);
}

void PipeLine::attach(const GLbitfield stage, const Shader* shader) const
{
  glUseProgramStages(ID, stage, shader->getID());
}

void PipeLine::bind() const
{
  glBindProgramPipeline(ID);
}