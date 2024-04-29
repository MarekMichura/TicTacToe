#include "pipeline.hpp"

PipeLine::PipeLine(const unsigned int size) : size(size)
{
  glCreateProgramPipelines(size, &ID);
}

PipeLine::~PipeLine()
{
  glDeleteProgramPipelines(size, &ID);
}

void PipeLine::attach(GLbitfield stage, Shader* shader)
{
  glUseProgramStages(ID, stage, shader->getID());
}

void PipeLine::bind()
{
  glBindProgramPipeline(ID);
}