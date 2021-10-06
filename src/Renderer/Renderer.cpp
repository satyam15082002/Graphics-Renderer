#include"Renderer.h"

glm::vec4 Renderer::m_Color={0.0f, 0.0f, 0.0f,1.0f};
void Renderer::Clear()
{
        glClearColor(Renderer::m_Color.r,Renderer::m_Color.g,Renderer::m_Color.b,Renderer::m_Color.w);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
void Renderer::Draw(Ref<Shader>& shader,Ref<VertexArray>& va)
{
    shader->Bind();
    va->Bind();
    glDrawElements(GL_TRIANGLES,va->m_IB->GetCount(),GL_UNSIGNED_INT,NULL);

}
void Renderer::Draw(Ref<Shader>& shader,Ref<VertexArray>& va,Ref<Texture>& tex)
{
    shader->Bind();
    va->Bind();
    tex->Bind();
    glDrawElements(GL_TRIANGLES,va->m_IB->GetCount(),GL_UNSIGNED_INT,NULL);

}
