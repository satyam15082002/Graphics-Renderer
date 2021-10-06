#pragma once
#include<GL/glew.h>

class VertexBuffer
{
    private:
        unsigned int m_RendererID;
    public:
        VertexBuffer(void* vertices,size_t size);
        VertexBuffer(size_t size);
        ~VertexBuffer();
        void Bind() const;
        void Unbind() const;
        unsigned int& GetRendererID(){ return m_RendererID; }
        void SetData(size_t size,void* data);
};

