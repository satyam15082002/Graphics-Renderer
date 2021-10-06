#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"../Batch/Type.h"
#include"Shader.h"
#include"VertexArray.h"
#include"IndexBuffer.h"
#include"Texture.h"
#include<vector>
#include<array>
#include<glm/glm.hpp>

class Renderer
{
    public:
        Renderer()=default;
        static void Clear();
        static void Draw(Ref<Shader>& shader,Ref<VertexArray>& va);
        static void Draw(Ref<Shader>& shader,Ref<VertexArray>& va,Ref<Texture>& tex);
    public:
        static glm::vec4 m_Color;
};

