#include"IndexBuffer.h"


IndexBuffer::IndexBuffer(unsigned int* indices,int count):m_Count(count)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), indices, GL_STATIC_DRAW);
}
IndexBuffer::IndexBuffer(int count)
{
    m_Count=0;
    unsigned int indices[count];
    unsigned int offset=0;
    for(int i=0;i<count;i+=6)
    {
        indices[i+0]=offset;
        indices[i+1]=offset+1;
        indices[i+2]=offset+2;
        indices[i+3]=offset;
        indices[i+4]=offset+2;
        indices[i+5]=offset+3;
        offset+=4;
    }
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}
void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);

}
void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 
}
int IndexBuffer::GetCount() const
{
    return m_Count;
}
void IndexBuffer::SetCount(int n) 
{
    m_Count=n;
}
