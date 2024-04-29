#version 450 core

layout(location = 0) in vec2 inPos;

out gl_PerVertex
{
  vec4 gl_Position;
};

void main()
{
  gl_Position = vec4(inPos.x, inPos.y, 0.f, 1.f);
}