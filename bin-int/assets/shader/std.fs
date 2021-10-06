#version 330 core
out vec4 FragColor;
// in vec2 TextCoord;
in float TextID;
in vec4 Color;
void main()
{
    int index=int(TextID);
   // FragColor = texture(ourTexture[index], TexCoord);
   FragColor=Color;
}