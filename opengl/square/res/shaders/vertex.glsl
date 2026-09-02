#version 330 core

layout(location = 0) in vec2 point;
layout(location = 1) in vec3 clr;

out vec3 posClr;

void main()
{
  gl_Position = vec4(point.x , point.y, 1.0f,1.0f);
  posClr = clr;
}
