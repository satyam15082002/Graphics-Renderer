#include"VertexArray.h"


VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}
void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
    m_VB->Bind();
    m_IB->Bind();
}
void VertexArray::Unbind() const
{
    glBindVertexArray(0);
    m_VB->Unbind();
    m_IB->Unbind();
}
void VertexArray::AddVertexBuffer(Ref<VertexBuffer>& VB)
{
    m_VB=VB;
}
void VertexArray::AddIndexBuffer(Ref<IndexBuffer>& IB)
{
    m_IB=IB;
}

