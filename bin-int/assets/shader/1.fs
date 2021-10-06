#version 330 core
out vec4 FragColor;
// in vec2 TextCoord;
in float TextID;
in vec4 Color;
uniform sampler2D ourTexture[25];
void main()
{
    int index=int(TextID);
   // FragColor = texture(ourTexture[index], TexCoord);
   FragColor=vec4(1.0f,0.0f,0.0f,1.0f);
}