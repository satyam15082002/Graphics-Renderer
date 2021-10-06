#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTextCoord;
layout (location = 3) in float aTextID;

out vec2 TextCoord;
out float TextID;
out vec4 Color;
uniform mat4 view;
uniform mat4 model;
void main()
{
  gl_Position = view*model*vec4(aPos, 1.0f);
  TextCoord = aTextCoord;
  Color=aColor;
  TextID=aTextID;
}