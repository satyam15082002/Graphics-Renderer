#pragma once
#include<GL/glew.h>
#include<memory>
#include"VertexBuffer.h"
#include"IndexBuffer.h"
#include"../Batch/Type.h"
class VertexArray
{
    private:
            unsigned int m_RendererID;
    public:
        Ref<VertexBuffer> m_VB;
        Ref<IndexBuffer> m_IB;
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void Unbind() const;

        void AddVertexBuffer(Ref<VertexBuffer>& VB);
        void AddIndexBuffer(Ref<IndexBuffer>& IB);

};

