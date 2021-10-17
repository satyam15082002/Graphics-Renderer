#include"Renderer2D.h"
#include"../Renderer/Renderer.h"
Ref<VertexArray> Renderer2D::m_VA;
Ref<Shader> Renderer2D::m_Shader;
Ref<Camera> Renderer2D::m_Camera;
RenderData Renderer2D::Stats;
Ref<Texture> Renderer2D::m_Texture[10];
int  Renderer2D::m_TextureCount=0;

void Renderer2D::Init(Ref<Camera>& cam)
{
    m_Camera=cam;
    m_Texture[0]=Texture::Create("./assets/texture/default.jpg");
    m_TextureCount++;
    m_VA=std::make_shared<VertexArray>();
    m_VA->m_VB=std::make_shared<VertexBuffer>(sizeof(Vertex)*m_MaxVertex);
    m_VA->m_IB=std::make_shared<IndexBuffer>(m_MaxIndices);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,m_Position)); 

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,m_Color)); 

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,m_TextCoords)); 

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,m_TextId)); 

    m_Shader=make_shared<Shader>("assets/shader/std.vs","assets/shader/std.fs");
    m_Shader->Bind();
    m_Shader->Unbind();
}
void Renderer2D::ShutDown()
{
    Stats.m_QuadsCount=0;
    Stats.m_VertexBuffer.clear();
}
void Renderer2D::DrawQuad(glm::vec3 pos,glm::vec4 color)
{
    Vertex v1,v2,v3,v4;
    v1.m_Position={-0.5f+pos.x,0.0f+pos.y,0.0f+pos.z,1.0f};
    v1.m_Color=color;
    v1.m_TextCoords={0.0f,0.0f};
    v1.m_TextId=0.0f;
    v2.m_Position={0.5f+pos.x,0.0f+pos.y,0.0f+pos.z,1.0f};
    v2.m_Color=color;
    v2.m_TextCoords={1.0f,0.0f};
    v2.m_TextId=0.0f;
    v3.m_Position={0.5f+pos.x,0.5f+pos.y,0.0f+pos.z,1.0f}; 
    v3.m_Color=color;
    v3.m_TextCoords={1.0f,1.0f};
    v3.m_TextId=0.0f;
    v4.m_Position={-0.5f+pos.x,0.5f+pos.y,0.0f+pos.z,1.0f};
    v4.m_Color=color;
    v4.m_TextCoords={0.0f,1.0f};
    v4.m_TextId=0.0f;
    Stats.m_VertexBuffer.push_back(v1);
    Stats.m_VertexBuffer.push_back(v2);
    Stats.m_VertexBuffer.push_back(v3);
    Stats.m_VertexBuffer.push_back(v4);
    
    ++Stats.m_QuadsCount;
}
void Renderer2D::DrawQuad(glm::vec3 pos,glm::vec4 color,float TextID)
{
    Vertex v1,v2,v3,v4;
    v1.m_Position={-0.5f+pos.x,0.0f+pos.y,0.0f+pos.z,1.0f};
    v1.m_Color=color;
    v1.m_TextCoords={0.0f,0.0f};
    v1.m_TextId=TextID;
    v2.m_Position={0.5f+pos.x,0.0f+pos.y,0.0f+pos.z,1.0f};
    v2.m_Color=color;
    v2.m_TextCoords={1.0f,0.0f};
    v2.m_TextId=TextID;
    v3.m_Position={0.5f+pos.x,0.5f+pos.y,0.0f+pos.z,1.0f}; 
    v3.m_Color=color;
    v3.m_TextCoords={1.0f,1.0f};
    v3.m_TextId=TextID;
    v4.m_Position={-0.5f+pos.x,0.5f+pos.y,0.0f+pos.z,1.0f};
    v4.m_Color=color;
    v4.m_TextCoords={0.0f,1.0f};
    v4.m_TextId=TextID;
    Stats.m_VertexBuffer.push_back(v1);
    Stats.m_VertexBuffer.push_back(v2);
    Stats.m_VertexBuffer.push_back(v3);
    Stats.m_VertexBuffer.push_back(v4);
    
    ++Stats.m_QuadsCount;  
}
void Renderer2D::DrawQuad(glm::mat4 trans,glm::vec4 color)
{
    Vertex v1,v2,v3,v4;
    v1.m_Position={-0.5f,0.0f,0.0f,1.0f};
    v1.m_Position=trans*v1.m_Position;
    v1.m_Color=color;
    v1.m_TextCoords={0.0f,0.0f};
    v1.m_TextId=0.0f;
    v2.m_Position={0.5f,0.0f,0.0f,1.0f};
    v2.m_Position=trans*v2.m_Position;
    v2.m_Color=color;
    v2.m_TextCoords={1.0f,0.0f};
    v2.m_TextId=0.0f;
    v3.m_Position={0.5f,0.5f,0.0f,1.0f};
    v3.m_Position=trans*v3.m_Position;
    v3.m_Color=color;
    v3.m_TextCoords={1.0f,1.0f};
    v3.m_TextId=0.0f;
    v4.m_Position={-0.5f,0.5f,0.0f,1.0f};
    v4.m_Position=trans*v4.m_Position;
    v4.m_Color=color;
    v4.m_TextCoords={0.0f,1.0f};
    v4.m_TextId=0.0f;
    Stats.m_VertexBuffer.push_back(v1);
    Stats.m_VertexBuffer.push_back(v2);
    Stats.m_VertexBuffer.push_back(v3);
    Stats.m_VertexBuffer.push_back(v4);
    
    ++Stats.m_QuadsCount;
}
void Renderer2D::DrawQuad(glm::mat4 trans,glm::vec4 color,float TextID)
{
      Vertex v1,v2,v3,v4;
    v1.m_Position={-0.5f,0.0f,0.0f,1.0f};
    v1.m_Position=trans*v1.m_Position;
    v1.m_Color=color;
    v1.m_TextCoords={0.0f,0.0f};
    v1.m_TextId=TextID;
    v2.m_Position={0.5f,0.0f,0.0f,1.0f};
    v2.m_Position=trans*v2.m_Position;
    v2.m_Color=color;
    v2.m_TextCoords={1.0f,0.0f};
    v2.m_TextId=TextID;
    v3.m_Position={0.5f,0.5f,0.0f,1.0f};
    v3.m_Position=trans*v3.m_Position;
    v3.m_Color=color;
    v3.m_TextCoords={1.0f,1.0f};
    v3.m_TextId=TextID;
    v4.m_Position={-0.5f,0.5f,0.0f,1.0f};
    v4.m_Position=trans*v4.m_Position;
    v4.m_Color=color;
    v4.m_TextCoords={0.0f,1.0f};
    v4.m_TextId=TextID;
    Stats.m_VertexBuffer.push_back(v1);
    Stats.m_VertexBuffer.push_back(v2);
    Stats.m_VertexBuffer.push_back(v3);
    Stats.m_VertexBuffer.push_back(v4);
    
    ++Stats.m_QuadsCount;
}

void Renderer2D::Flush()
{
    m_Shader->Bind();
    for(int i=0;i<m_TextureCount;i++)
        m_Texture[i]->Bind(i);
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    m_Shader->SetIntArray("ourTexture",10,arr);
    m_Shader->SetMat4("view",m_Camera->GetProjectionViewMatrix());
    m_VA->Bind();
    m_VA->m_VB->SetData(sizeof(Vertex)*Stats.GetVertexCount(),Stats.m_VertexBuffer.data());
    glDrawElements(GL_TRIANGLES,Stats.GetIndiceCount(),GL_UNSIGNED_INT,NULL);
}