#pragma once
#include"../Renderer/VertexArray.h"
#include"../Renderer/VertexBuffer.h"
#include"../Renderer/IndexBuffer.h"
#include"../Renderer/Shader.h"
#include"../Renderer/Camera.h"
#include"../Renderer/Texture.h"
#include"Type.h"
#include<vector>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
struct RenderData
{
    int64_t m_QuadsCount=0;
    std::vector<Vertex> m_VertexBuffer; 
    int64_t GetQuadCount() { return m_QuadsCount; }
    int64_t GetVertexCount(){ return m_QuadsCount*4; }
    int64_t GetIndiceCount(){ return m_QuadsCount*6; }
};
const int64_t m_MaxQuads=6000;
const int64_t m_MaxVertex=4*m_MaxQuads;
const int64_t m_MaxIndices=6*m_MaxQuads;

class Renderer2D
{
    public:
        static  void Init(Ref<Camera>& cam);
        static  void DrawQuad(glm::vec3 pos,glm::vec4 color);
        static  void DrawQuad(glm::mat4 trans,glm::vec4 color);
        static  void DrawQuad(glm::vec3 pos,glm::vec4 color,float TextID);
        static  void DrawQuad(glm::mat4 trans,glm::vec4 color,float TextID);

        static void ShutDown();
        static  void Flush();
        
        static Ref<VertexArray> m_VA;
        static Ref<Shader> m_Shader;
        static Ref<Camera> m_Camera;
        static  RenderData Stats;
        static Ref<Texture> m_Texture[10];
        static int m_TextureCount;
};