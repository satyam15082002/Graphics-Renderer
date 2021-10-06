#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTextCoord;
layout (location = 3) in float aTextID;

out vec2 TextCoord;
out float TextID;
out vec4 Color;
uniform mat4 view;
void main()
{
  gl_Position = view*aPos;
  TextCoord = aTextCoord;
  Color=aColor;
  TextID=aTextID;
}