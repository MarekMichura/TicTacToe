#version 330 core

layout(location = 0) in vec2 inPos;
layout(location = 1) in vec4 inColor;
out vec4 color;

layout(std140) uniform time
{
  float currentTime;
  float deltaTime;
};

void main()
{
  color = inColor;
  float pos = inPos.x + sin(currentTime);
  // if (t > 0.5)
  //   pos = inPos.x + 1 - t;
  // if (t > 1.5)
  //   pos = inPos.x - 2 + t;
  gl_Position = vec4(pos, inPos.y, 0.f, 1.f);
}