#version 330 core

layout(location = 0) in vec2 inPos;
layout(location = 1) in vec4 in_color;
out vec4 color;

void main()
{
  color = in_color;
  gl_Position = vec4(inPos.x, inPos.y, 0.f, 1.f);
}