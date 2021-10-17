#include"Texture.h"



Texture::Texture(const std::string& path):m_RendererID(0),m_FilePath(path),m_LocalBuffer(nullptr),m_Width(0),m_Height(0),m_Channels(0)
{
    stbi_set_flip_vertically_on_load(1);

    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID); // set the texture wrapping/filtering options (on currently bound texture) 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // load and generate the texture 
    m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channels, 4);
    if (m_LocalBuffer) 
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width,m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE,m_LocalBuffer);
        glGenerateMipmap(GL_TEXTURE_2D); 
        stbi_image_free(m_LocalBuffer);
    }
    else 
    {
        std::cout << "Failed to load texture" << std::endl; 
    }
}
Ref<Texture> Texture::Create(const std::string& path)
{
    return std::make_shared<Texture>(path);
}
Texture::~Texture()
{
    glDeleteTextures(1,&m_RendererID);
}

void Texture::Bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0+slot);
    glBindTexture(GL_TEXTURE_2D,m_RendererID);
}
void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D,0);

}
