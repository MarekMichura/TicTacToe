#version 330 core

// in vec3 color;
out vec4 FragColor;

float distance2D(vec2 p1, vec2 p2)
{
  return length(p2 - p1);
}

void main()
{
  float dist = distance2D(gl_FragCoord.xy, vec2(400, 400));
  if (dist < 100 && dist > 80)
    FragColor = vec4(1.f, 0.f, 0.f, .3f);
  else
    FragColor = vec4(1.f, 1.f, 1.f, .1f);
}