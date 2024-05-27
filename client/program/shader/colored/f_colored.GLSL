#version 330 core

in vec4 color;
out vec4 FragColor;

layout(std140) uniform time
{
  float currentTime;
  float deltaTime;
};

void main()
{
  vec4 newCollor = vec4(color.rgb * ((sin(currentTime) + 2) / 2), color.a);
  FragColor = newCollor;
}