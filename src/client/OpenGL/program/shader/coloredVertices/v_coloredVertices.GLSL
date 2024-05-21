#version 330 core

layout(location = 0) in vec2 inPos;
layout(location = 1) in vec4 in_color;

layout(std140) uniform MyUniformBlock
{
  float time;
  float prev;
};

out vec4 color;

void main()
{
  color = in_color;
  float t = mod(time / 2, 2);
  float pos = inPos.x + t;
  if (t > 0.5)
    pos = inPos.x + 1 - t;
  if (t > 1.5)
    pos = inPos.x - 2 + t;
  gl_Position = vec4(pos, inPos.y, 0.f, 1.f);
}