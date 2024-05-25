#version 330 core

layout(location = 0) in vec2 inPos;
// layout(location = 1) in vec3 color;
// out vec3 color;

void main()
{
  gl_Position = vec4(inPos.x, inPos.y, 0.f, 1.f);
}