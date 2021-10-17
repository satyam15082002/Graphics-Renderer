#pragma once
#include<iostream>
#include<GL/glew.h>
#include<stb_image/stb_image.h>
#include"./../Batch/Type.h"
class Texture
{
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char* m_LocalBuffer;
    int m_Width,m_Height,m_Channels;
public:
    Texture(const std::string& path);
    ~Texture();
    static Ref<Texture> Create(const std::string& path);
    void Bind(unsigned int slot=0) const;
    void Unbind() const;
    inline int GetWidth() const { return m_Width; }
    inline int GetHeight() const { return m_Height; }
    unsigned int GetRedererID() const { return m_RendererID; }

};

