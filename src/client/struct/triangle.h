#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>
#include <corecrt_math.h>

GLfloat myFirstObj[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3,    0.0f,  // Lower left corner
    0.5f,  -0.5f * float(sqrt(3)) / 3,    0.0f,  // Lower right corner
    0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f   // Upper corner
};

#endif