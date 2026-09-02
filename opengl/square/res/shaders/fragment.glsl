#version 330 core

in vec3 posClr;
out vec4 color;

void main()
{
  color = vec4(posClr, 1.0f);
}
