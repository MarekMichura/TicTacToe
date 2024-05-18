#version 330 core

out vec4 FragColor;
in vec4 color;

// float distance2D(vec2 p1, vec2 p2)
// {
//   return length(p2 - p1);
// }

void main()
{
  // float dist = distance2D(gl_FragCoord.xy, vec2(400, 400));
  // if (dist < 100 && dist > 80)
  //   FragColor = vec4(1.f, 1.f, 1.f, 0.5f);
  // else
  FragColor = vec4(color.xyz, .1f);
}