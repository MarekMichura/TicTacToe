#include <memory>
#include "vbo.hpp"

namespace gl {
constexpr static float SQUARE_POINTS[] = {
    -.5f, .5f,   // left top
    -.5f, -.5f,  // left bottom
    .5f,  -.5f,  // right bottom
    .5f,  .5f,   // right top
    1.f,  1.f,   // right top
};

inline std::shared_ptr<VBO> VBO_SQUARE_POINTS()
{
  return std::make_shared<VBO>(  //
      GL_ARRAY_BUFFER,           //
      SQUARE_POINTS,             //
      sizeof(SQUARE_POINTS),     //
      GL_STATIC_DRAW);
}

constexpr static unsigned int SQUARE_INDEX[] = {
    0, 1, 2,  //
    0, 2, 3   //
};

inline std::shared_ptr<VBO> VBO_SQUARE_INDEX()
{
  return std::make_shared<VBO>(  //
      GL_ELEMENT_ARRAY_BUFFER,   //
      SQUARE_INDEX,              //
      sizeof(SQUARE_INDEX),      //
      GL_STATIC_DRAW);
}

constexpr static unsigned int SQUARE_INDEX_PROBLEM[] = {
    2, 1, 4,  //
    0, 3, 4   //
};

inline std::shared_ptr<VBO> VBO_SQUARE_INDEX_PROBLEM()
{
  return std::make_shared<VBO>(      //
      GL_ELEMENT_ARRAY_BUFFER,       //
      SQUARE_INDEX_PROBLEM,          //
      sizeof(SQUARE_INDEX_PROBLEM),  //
      GL_STATIC_DRAW);
}
}  // namespace gl