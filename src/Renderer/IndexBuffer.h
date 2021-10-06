#pragma once
#include<GL/glew.h>

class IndexBuffer
{
    private:
        unsigned int m_RendererID;
        int m_Count;
    public:
        IndexBuffer(unsigned int* indices,int count);
        IndexBuffer(int count);
        ~IndexBuffer();
        void Bind() const;
        void Unbind() const;
        int GetCount() const;
        void SetCount(int n) ;

};

