#include "vboContainer.hpp"
#include "squareData.h"
#include "triangleData.h"
#include "vbo.hpp"

namespace gl {
VboMap VBOContainer::container{};

const VboFunMap VBOContainer::containerFun{
    {VBO_NAME::TRIANGLE_VERTEX_ARRAY, VBO_TRIANGLE_POINTS},            //
    {VBO_NAME::SQUARE_VERTEX_ARRAY, VBO_SQUARE_POINTS},                //
    {VBO_NAME::SQUARE_VERTEX_INDEX, VBO_SQUARE_INDEX},                 //
    {VBO_NAME::SQUARE_VERTEX_INDEX_INVALID, VBO_SQUARE_INDEX_PROBLEM}  //
};

std::shared_ptr<VBO> VBOContainer::getVBO(VBO_NAME name)
{
  auto it = container.find(name);
  if (it != container.end()) {
    if (auto data = it->second.lock()) {
      return data;
    }
  }

  auto fun = containerFun.find(name)->second();
  container.insert_or_assign(name, fun);
  return fun;
}
}  // namespace gl